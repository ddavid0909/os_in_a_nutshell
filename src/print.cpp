//
// Created by marko on 20.4.22..
//

#include "../h/print.hpp"
#include "../lib/console.h"
#include "../h/syscall_c.hpp"
void printString1(char const *string)
{
    while (*string != '\0')
    {
        putc(*string);
        string++;
    }
}

void printInteger1(uint64 integer)
{
    static char digits[] = "0123456789";
    char buf[16];
    int i, neg;
    uint x;

    neg = 0;
    if (integer < 0)
    {
        neg = 1;
        x = -integer;
    } else
    {
        x = integer;
    }

    i = 0;
    do
    {
        buf[i++] = digits[x % 10];
    } while ((x /= 10) != 0);
    if (neg)
        buf[i++] = '-';

    while (--i >= 0)
        putc(buf[i]);
}