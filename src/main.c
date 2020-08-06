#include <stdio.h>
#include <stdlib.h>
#include "rem.h"
#include "filesystem.h"

configuration_t conf;

void callback(char *path)
{
    match_in_file(path, conf.regex, conf.flags, conf.options);
}

int main(int argc, char **argv)
{
    if (parse_cmd_arguments(argc, argv, &conf) == -1)
    {
        fprintf(stderr, "Bad arguments.\n");
        exit(EXIT_FAILURE);
    }
    if (conf.help)
    {
        printf("[RULE]\n\n\t<Last two options have to be REGEX and FILE-PATH.>\n\nCommands:\n\n\tUsage: rem [REGEX]...[FILE PATH]...\n\tSearch for REGEX in each FILE.\n\tExample: rem -r 'hello' main.c\n\n[OPTIONS]\n\n\t-r,        It activates recursive.\n\t-c,            It activates color.\n\t-n,      It print line number.\n\t-w,        It finds pure word.\n\t-f,        It print file name. \n\n");
        exit(EXIT_SUCCESS);
    }
    if (conf.recursive)
    {
        walk_in_dir(conf.path, &callback);
    }
    else
    {
        match_in_file(conf.path, conf.regex, conf.flags, conf.options);
    }
    exit(EXIT_SUCCESS);
}