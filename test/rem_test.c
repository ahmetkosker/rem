#include <stdio.h>
#include "../src/rem.h"
#include "../src/options.h"

#define TEST_FILE "test/resources/example.txt"

int main()
{
    unsigned char flags = ENABLE_NOTHING;
    int count = match_in_file(fopen(TEST_FILE, "r"), "information", flags);
    printf("%d", count);
    return 0;
}
