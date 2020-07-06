#include "options.h"

/* Check if the given mask conforms the flags. */
int isflag(unsigned char flags, unsigned char mask)
{
    return (flags & mask) == mask;
}

/* Parse and fill the struct pointed by the given pointer. */
int parse_cmd_arguments(int argc, char *argv[], configuration_t *conf)
{
    if (argc < 3)
        return -1;
    conf->path = argv[argc];
    conf->regex = argv[argc - 1];
    int i;
    for (i = 2; i < argc; i++)
    {
    }
}