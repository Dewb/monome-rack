#define CBBQ_DEBUG

#include "../cbbq.h"
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

void queue_display(cbbq* q)
{
    for (int i = 0; i < q->size; i++)
        printf("%02X ", q->buf[i]);
    printf("\n");
    uint8_t i1, i2, i3;
    char c1, c2, c3;
    if (q->read <= q->write && q->read <= q->watermark) 
    {
        i1 = q->read;
        c1 = 'r';
        if (q->write <= q->watermark) {
            i2 = q->write;
            c2 = 'w';
            i3 = q->watermark;
            c3 = 'm';
        } else {
            i3 = q->write;
            c3 = 'w';
            i2 = q->watermark;
            c2 = 'm';
        }
    } 
    else if (q->write <= q->read && q->write <= q->watermark)
    {
        i1 = q->write;
        c1 = 'w';
        if (q->read <= q->watermark)
        {
            i2 = q->read;
            c2 = 'r';
            i3 = q->watermark;
            c3 = 'm';
        } else {
            i3 = q->read;
            c3 = 'r';
            i2 = q->watermark;
            c2 = 'm';
        }
    }
    else
    {
        i1 = q->watermark;
        c1 = 'm';
        if (q->read <= q->write)
        {
            i2 = q->read;
            c2 = 'r';
            i3 = q->write;
            c3 = 'w';
        } else {
            i3 = q->read;
            c3 = 'r';
            i2 = q->write;
            c2 = 'w';
        }
    }

    for (int x = 0; x < i1; x++)
    {
        printf("   ");
    }
    printf("%c", c1);

    if (i2 == i1)
    {
        printf("%c", c2);
    } 
    else
    {
        printf("  ");
        for (int x = 0; x < i2 - i1 - 1; x++)
        {
            printf("   ");
        }
        printf("%c", c2);
    }

    if (i3 == i2)
    {
        printf("%c\n\n", c3);
    }
    else
    {
        printf(i2 == i1 ? " " : "  ");
        for (int x = 0; x < i3 - i2 - 1; x++)
        {
            printf("   ");
        }
        printf("%c\n\n", c3);
    }
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

    // fill the buffer with messages
    QASSERT(queue_write(&q, (uint8_t[]) { 0x01, 0x02, 0x03 }, 3));
    QASSERT(queue_write(&q, (uint8_t[]) { 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A }, 7));
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
    ASSERT(rlen == 7);
    ASSERT(rbuf[0] == 0x04);
    ASSERT(rbuf[1] == 0x05);
    ASSERT(rbuf[2] == 0x06);
    ASSERT(rbuf[3] == 0x07);
    ASSERT(rbuf[4] == 0x08);
    ASSERT(rbuf[5] == 0x09);
    ASSERT(rbuf[6] == 0x0A);

    // read the third message
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 2);
    ASSERT(rbuf[0] == 0xFF);
    ASSERT(rbuf[1] == 0xFF);

    // write a new message that wraps
    QASSERT(queue_write(&q, (uint8_t[]) { 0xAA, 0xBB, 0xCC, 0xDD }, 4));

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

    // read the fifth message
    QASSERT(queue_read(&q, &rbuf, &rlen));
    ASSERT(rlen == 3);
    ASSERT(rbuf[0] == 0x01);
    ASSERT(rbuf[1] == 0x02);
    ASSERT(rbuf[2] == 0x03);

    // this should wrap
    QASSERT(queue_write(&q, (uint8_t[]) { 0xAA, 0xAA, 0xAA, 0xAA, 0xAA }, 5));

    // this should barely fit
    QASSERT(queue_write(&q, (uint8_t[]) { 0x11 }, 1));
    
    // these should fail
    QASSERT(QueueFull == queue_write(&q, (uint8_t[]) { 0x11 }, 1));
    QASSERT(MessageTooLarge == queue_write(&q, (uint8_t[]) { 0x11 }, 22));

    printf("Tests passed.\n\n");
    return 0;
}