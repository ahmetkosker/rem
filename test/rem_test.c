#include <stdio.h>
#include "../src/rem.h"
#include "../src/options.h"

int main(int argc, char *argv[])
{

    unsigned char flags = ENABLE_COLOR | ENABLE_LINE_NUMBER | ENABLE_WORD;
    options option;
    char *b = argv[3];
    char *a = argv[4];
    char *c = argv[5];
    option.b = b[0] - 48;
    option.a = a[0] - 48;
    option.c = c[0] - 48;
    match_in_file(argv[1], argv[2], 0, option);

    return 0;
}
