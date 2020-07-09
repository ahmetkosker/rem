#include <stdio.h>
#include "../src/rem.h"
#include "../src/options.h"

int main(int argc, char **argv)
{
    unsigned char flags = ENABLE_COLOR | ENABLE_LINE_NUMBER;
    options_t options;
    options.before = 0;
    options.after = 0;
    match_in_file(argv[2], argv[1], 0, options);

    return 0;
}
