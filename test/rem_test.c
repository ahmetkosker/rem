#include <stdio.h>
#include "../src/rem.h"
#include "../src/options.h"

int main(int argc, char *argv[])
{
    unsigned char flags = ENABLE_COLOR | ENABLE_LINE_NUMBER | ENABLE_WORD;
    options_t options;
    options.before = 4;
    options.after = 2;
    match_in_file(argv[1], argv[2], 0, options);

    return 0;
}
