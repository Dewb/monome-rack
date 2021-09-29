/*

cbbq.h

C implementation of a lock-free, thread-safe, single-producer/single-consumer 
circular message queue for short variable-length byte-sequence messages

by Michael Dewberry 
http://dewb.org
https://github.com/dewb

based directly on the "bbqueue" design by Andrea Lattuada and James Munns
https://ferrous-systems.com/blog/lock-free-ring-buffer/
https://github.com/jamesmunns/bbqueue

   me: "C is terrible and nobody should write it, we should use languages with memory safety"
   also me: <implements a Rust data structure in C>

Requirements/notes

* [TODO] C11 and support for <stdatomic.h> recommended
  * if your MCU is too simple to reorder instructions, you might be okay without it (???)
* Only one thread reads, only one thread writes
* Individual message length 255 bytes or less
* Queue size up to 2^32-1 bytes
* [TODO] support multi-producer/single-consumer with an optional lock function on write? 


License: MIT

Copyright © 2021 Michael Dewberry

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#ifdef CBBQ_DEBUG
#include <assert.h>
#define ASSERT(expr) assert(expr);

#define CHECK_INVARIANTS(q) \
    ASSERT(q->read < q->watermark || q->watermark == 0); \
    ASSERT(q->write <= q->watermark); \
    ASSERT(q->read < q->size); \
    ASSERT(q->write <= q->size); \
    ASSERT(q->watermark <= q->size); 
#else
#define ASSERT(expr)
#define CHECK_INVARIANTS(expr)
#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    uint8_t* buf;
    uint32_t size;
    uint32_t read;
    uint32_t write;
    uint32_t watermark;
} cbbq;

void queue_init(cbbq* q, uint32_t size) 
{
    if (!q) 
    {
        return;
    }

    q->buf = (uint8_t*)malloc(size);
    q->size = size;
    q->read = 0;
    q->write = 0;
    q->watermark = 0;
}

void queue_free(cbbq* q)
{
    if (q)
    {
        free(q->buf);
    }
}

typedef enum
{
    Success = 1,
    NoMessagesAvailable = 0,
    MessageTooLarge = -1,
    QueueFull = -2,
} QueueResult;

// Write a message into the queue.
// queue_write should only be called by the producer thread.
QueueResult
queue_write(cbbq* q, uint8_t* msg_bytes, uint8_t msg_length)
{
    CHECK_INVARIANTS(q)

    // total amount to write is the length byte plus the message contents
    uint32_t write_length = 1 + msg_length;
    if (write_length > q->size)
    {
        return MessageTooLarge;
    }

    // can we fit this message in the remaining area?
    if (q->size - q->write >= write_length)
    {
        if (q->read > q->write && q->read <= q->write + write_length)
        {
            // can't overtake read pointer
            return QueueFull; 
        }

        // record the message length into the buffer
        *(q->buf + q->write) = msg_length;
        // copy the message bytes into the buffer
        memcpy(q->buf + q->write + 1, msg_bytes, msg_length);

        // move the write pointer ahead
        q->write = q->write + write_length;

        // if we're in the non-flipped case, update watermark
        if (q->read < q->write) {
            q->watermark = q->write;
        }
    }
    else // we have to wrap around
    {
        if (q->read <= write_length) {
            // can't overtake read pointer
            return QueueFull; 
        }

        // set the high water mark at the previous write pointer
        q->watermark = q->write;

        // write pointer is now implicitly 0
        // record the message length into the buffer
        *(q->buf) = msg_length;
        // copy the message bytes into the buffer
        memcpy(q->buf + 1, msg_bytes, msg_length);

        // update the write pointer
        q->write = write_length;
    }

    return Success;
}

// Read a message from the queue.
// The contents of the pointer written to read_bytes is only valid until the next
// call to queue_read.
// queue_read should only be called by the consumer thread.
QueueResult
queue_read(cbbq* q, uint8_t** read_bytes, uint8_t* read_length)
{
    CHECK_INVARIANTS(q)

    // reads stop either at the write pointer or the watermark pointer, 
    // depending on whether or not we're in the flipped state
    uint8_t end = q->read > q->write ? q->watermark : q->write;

    // are there messages left to read?
    if (q->read >= end) 
    {
        return NoMessagesAvailable;
    }

    // get the message length from the buffer
    uint8_t msg_length = *(q->buf + q->read);

    // give the consumer a pointer to the message
    if (read_bytes) 
    {
        *read_bytes = q->buf + q->read + 1;
    }

    // give the consumer the message length
    if (read_length)
    {
        *read_length = msg_length;
    }

    // move the read pointer to the next message
    q->read = (q->read + msg_length + 1);

    // if the read pointer reaches the watermark, next read starts at 0
    if (q->read >= q->watermark)
    {
        q->read = 0;
    }

    return Success;
}