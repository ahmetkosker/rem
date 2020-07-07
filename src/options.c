#include <stdio.h>
#include <string.h>
#include "options.h"

/* Check if the given mask conforms the flags. */
int isflag(unsigned char flags, unsigned char mask)
{
    return (flags & mask) == mask;
}

/* Parse and fill the struct pointed by the given pointer. */
int parse_cmd_arguments(int argc, char **argv, configuration_t *conf)
{
    if (argc < 3)
        return -1;
    conf->path = argv[argc - 1];
    conf->regex = argv[argc - 2];
    int i;
    for (i = 1; i < argc - 2; i++)
    {
        if (!(strcmp(argv[i], "-B")))
        {
            conf->options.before = *argv[i + 1] - 48;
            i++;
        }
        else if (!(strcmp(argv[i], "-A")))
        {
            conf->options.after = *argv[i + 1] - 48;
            i++;
        }
        else if (!(strcmp(argv[i], "-r")))
            conf->recursive = 1;
        else if (!(strcmp(argv[i], "--color")))
        {
            conf->flags = ENABLE_COLOR;
        }
        else if (!(strcmp(argv[i], "--case")))
        {
            conf->flags = ENABLE_COLOR | ENABLE_CASE_SENSITIVE;
        }
        else if (!(strcmp(argv[i], "--line-number")))
        {
            conf->flags = ENABLE_COLOR | ENABLE_CASE_SENSITIVE | ENABLE_LINE_NUMBER;
        }
        else if (!(strcmp(argv[i], "--word")))
        {
            conf->flags = ENABLE_COLOR | ENABLE_CASE_SENSITIVE | ENABLE_LINE_NUMBER | ENABLE_WORD;
        }
    }
    return 0;
}