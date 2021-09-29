#pragma once

#include <stdio.h>

// debugging utilities for cbbq

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
        if (q->write <= q->watermark)
        {
            i2 = q->write;
            c2 = 'w';
            i3 = q->watermark;
            c3 = 'm';
        }
        else
        {
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
        }
        else
        {
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
        }
        else
        {
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