#include <stdio.h>
#include "../src/rem.h"
#include "../src/options.h"
#define TEST_FILE "test/resources/example.txt"

int main()
{
    unsigned char flags = ENABLE_COLOR | ENABLE_LINE_NUMBER;
    int count = match_in_file(TEST_FILE, "information", flags);
    printf("%d", count);
    return 0;
}
