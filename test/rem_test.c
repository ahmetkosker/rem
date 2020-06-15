#include <stdio.h>

int match_in_file(FILE *, char *, unsigned char);
unsigned char isflag(unsigned char, unsigned char);
unsigned char ENABLE_NOTHING = 0;
unsigned char ENABLE_COLOR = 1;
unsigned char ENABLE_CASE_SENSITIVE = 2;
unsigned char ENABLE_LINE_NUMBER = 4;

#define TEST_FILE "test/resources/example.txt"

int main()
{
    unsigned char flags = ENABLE_NOTHING;
    int count = match_in_file(fopen(TEST_FILE, "r"), "information", flags);
    printf("%d", count);
    return 0;
}
