#include <stdio.h>
#include <stdlib.h>
#include "../src/options.h"

int main(int argc, char *argv[])
{
    configuration_t conf;
    if (parse_cmd_arguments(argc, argv, &conf) == -1)
    {
        fprintf(stderr, "bad arguments");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "path: %s\n", conf.path);
    fprintf(stderr, "regex: %s\n", conf.regex);
    fprintf(stderr, "before: %d\n", conf.options.before);
    fprintf(stderr, "after: %d\n", conf.options.after);
    fprintf(stderr, "recursive: %d\n", conf.recursive);
    fprintf(stderr, "color: %d\n", isflag(conf.flags, ENABLE_COLOR));
    fprintf(stderr, "case sensitive: %d\n", isflag(conf.flags, ENABLE_CASE_SENSITIVE));
    fprintf(stderr, "line number: %d\n", isflag(conf.flags, ENABLE_LINE_NUMBER));
    fprintf(stderr, "word: %d\n", isflag(conf.flags, ENABLE_WORD));

    return EXIT_SUCCESS;
}
