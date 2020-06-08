#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "test/resources/example.txt"

int main()
{

    if (match_in_file(fopen(TEST_FILE, "r"), "information", 0) != 8)
    {
        printf("Test failed:4 tane information bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "also", 0) != 7)
    {
        printf("Test failed:7 tane also bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "free", 1) != 16)
    {
        printf("Test failed:16 tane free bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "the", 0) != 435)
    {
        printf("Test failed:435 tane the bulunmadı.\n");
        return -1;
    }

    printf("All tests succesful.\n");
    return 0;
}
