#include <stdio.h>
#include <stdlib.h>
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
    if (argc < 2)
        return -1;
    if (!(strcmp(argv[1], "-h")))
    {
        conf->help = 1;
        return 0;
    }
    if (!(strcmp(argv[2], "-h")))
    {
        conf->help = 1;
        return 0;
    }
    if (argc < 3)
        return -1;
    conf->path = argv[argc - 1];
    conf->regex = argv[argc - 2];
    int i;
    for (i = 1; i < argc - 2; i++)
    {
        if (!(strcmp(argv[i], "-h")))
        {
            conf->help = 1;
            return 0;
        }
        else if (!(strcmp(argv[i], "-B")))
        {
            conf->options.before = atoi(argv[i + 1]);
            i++;
        }
        else if (!(strcmp(argv[i], "-A")))
        {
            conf->options.after = atoi(argv[i + 1]);
            i++;
        }
        else if (!(strcmp(argv[i], "-C")))
        {
            conf->options.before = atoi(argv[i + 1]);
            conf->options.after = atoi(argv[i + 1]);
            i++;
        }
        else if (!(strcmp(argv[i], "-r")))
            conf->recursive = 1;
        else if (!(strcmp(argv[i], "-c")))
            conf->flags = conf->flags | ENABLE_COLOR;
        else if (!(strcmp(argv[i], "-n")))
            conf->flags = conf->flags | ENABLE_LINE_NUMBER;
        else if (!(strcmp(argv[i], "-w")))
            conf->flags = conf->flags | ENABLE_WORD;
        else if (!(strcmp(argv[i], "-f")))
            conf->flags = conf->flags | ENABLE_FILE_NAME;
    }

    return 0;
}