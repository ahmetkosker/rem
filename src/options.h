#ifndef _REM_OPTIONS_H
#define _REM_OPTIONS_H

typedef struct options_t
{
    int after;
    int before;
} options_t;

typedef struct configuration_t
{
    char *path;
    char *regex;
    int recursive;
    options_t options;
    unsigned char flags;
} configuration_t;

int parse_cmd_arguments(int argc, char *argv[], configuration_t *conf);
int isflag(unsigned char flags, unsigned char mask);
static unsigned char ENABLE_NOTHING = 0;
static unsigned char ENABLE_COLOR = 1;
static unsigned char ENABLE_CASE_SENSITIVE = 2;
static unsigned char ENABLE_LINE_NUMBER = 4;
static unsigned char ENABLE_WORD = 8;

#endif
