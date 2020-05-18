#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "/home/ahmet/grep.txt"

int main()
{

    if (search(fopen(TEST_FILE, "r"), "ahmet") == 0)
    {
        printf("Test failed:Ahmet'i bulamadı.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "mehmet") == 1)
    {
        printf("Test failed:mehmet bulundu.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "sagopa") == 0)
    {
        printf("Test failed:sagopayı bulamadı.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "akman") == 0)
    {
        printf("Test failed:akmanı bulamadı.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "tuvaletkagidi") == 1)
    {
        printf("Test failed:tuvaletkagidi bulundu.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "seliim") == 0)
    {
        printf("Test failed:selliim bulunmadı.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "rak ") == 0)
    {
        printf("Test failed:rak  bulunmadı.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "ssssselim ") == 0)
    {
        printf("Test failed:ssssselim bulunmadı.");
        return -1;
    }
    printf("All tests succesful.\n");
    return 0;
}
