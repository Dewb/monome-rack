#define CBBQ_DEBUG

#include "cbbq.h"
#include "cbbq_utils.h"
#include <assert.h>
#include <stdio.h>

#define ASSERT(expr) assert(expr);
#define QASSERT(expr)                                                                             \
    {                                                                                             \
        bool tb = expr;                                                                           \
        printf("[%d] size: %d, read: %d, write: %d, watermark: %d, flipped: %s\n",                \
            __LINE__, q.size, q.read, q.write, q.watermark, q.read > q.write ? "true" : "false"); \
        queue_display(&q);                                                                        \
        if (!tb)                                                                                  \
            printf("FAIL: %s\n", #expr);                                                          \
        assert(tb);                                                                               \
    }


int main(void)
{
    printf("\nTesting...\n\n");

    cbbq q;
    queue_init(&q, 21);
    QASSERT(q.size == 21);

    uint8_t* rbuf;
    uint8_t rlen;

    // start with no messages
    QASSERT(NoMessagesAvailable == queue_read(&q, &rbuf, &rlen));

    // quick write and immediate read
    QASSERT(queue_write(&q, (uint8_t[]) { 0xAA }, 1));
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 1);
    ASSERT(rbuf[0] == 0xAA);
    ASSERT(q.write == 2);
    ASSERT(q.read == 2);
    QASSERT(NoMessagesAvailable == queue_read(&q, &rbuf, &rlen));

    // fill the buffer with messages
    QASSERT(queue_write(&q, (uint8_t[]) { 0x01, 0x02, 0x03 }, 3));
    QASSERT(queue_write(&q, (uint8_t[]) { 0x04, 0x05, 0x06, 0x07, 0x08 }, 5));
    QASSERT(queue_write(&q, (uint8_t[]) { 0xFF, 0xFF }, 2));
    QASSERT(queue_write(&q, (uint8_t[]) { 0xDE, 0xAD, 0xBE, 0xEF, 0xFF }, 5));

    // try to insert a message that won't fit
    QASSERT(QueueFull == queue_write(&q, (uint8_t[]) { 0xDD, 0xDD, 0xDD }, 3));

    // read the first message
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 3);
    ASSERT(rbuf[0] == 0x01);
    ASSERT(rbuf[1] == 0x02);
    ASSERT(rbuf[2] == 0x03);

    // read the second message
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 5);
    ASSERT(rbuf[0] == 0x04);
    ASSERT(rbuf[1] == 0x05);
    ASSERT(rbuf[2] == 0x06);
    ASSERT(rbuf[3] == 0x07);
    ASSERT(rbuf[4] == 0x08);

    // read the third message
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 2);
    ASSERT(rbuf[0] == 0xFF);
    ASSERT(rbuf[1] == 0xFF);

    // write a new message that wraps
    QASSERT(queue_write(&q, (uint8_t[]) { 0xAA, 0xBB, 0xCC, 0xDD }, 4));
    ASSERT(q.write == 5);
    ASSERT(q.watermark == 21);

    // read the fourth message
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 5);
    ASSERT(rbuf[0] == 0xDE);
    ASSERT(rbuf[1] == 0xAD);
    ASSERT(rbuf[2] == 0xBE);
    ASSERT(rbuf[3] == 0xEF);
    ASSERT(rbuf[4] == 0xFF);

    // read the fifth message
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 4);
    ASSERT(rbuf[0] == 0xAA);
    ASSERT(rbuf[1] == 0xBB);
    ASSERT(rbuf[2] == 0xCC);
    ASSERT(rbuf[3] == 0xDD);

    // should be no more messages
    QASSERT(NoMessagesAvailable == queue_read(&q, &rbuf, &rlen));

    // write more messages
    QASSERT(queue_write(&q, (uint8_t[]) { 0x01, 0x02, 0x03 }, 3));
    QASSERT(queue_write(&q, (uint8_t[]) { 0x01, 0x02, 0x03 }, 3));
    QASSERT(queue_write(&q, (uint8_t[]) { 0x01, 0x02, 0x03 }, 3));

    // read the sixth message
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 3);
    ASSERT(rbuf[0] == 0x01);
    ASSERT(rbuf[1] == 0x02);
    ASSERT(rbuf[2] == 0x03);

    // this should wrap
    QASSERT(queue_write(&q, (uint8_t[]) { 0xAA, 0xAA, 0xAA, 0xAA, 0xAA }, 5));
    ASSERT(q.write == 6);

    // this should barely fit in the remaining space before the read pointer
    QASSERT(queue_write(&q, (uint8_t[]) { 0x11 }, 1));
    
    // this should fail because writing it would overtake read
    QASSERT(QueueFull == queue_write(&q, (uint8_t[]) { 0x11 }, 1));

    // this should fail because it's larger than q.size
    QASSERT(MessageTooLarge == queue_write(&q, (uint8_t[]) { 0x11 }, 22));

    printf("Tests passed.\n\n");
    return 0;
}