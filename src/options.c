#include "options.h"

unsigned char isflag(unsigned char flags, unsigned char mask)
{
    return (flags & mask) == mask;
}