#include <stdio.h>
#include "../src/rem.h"
#include "../src/options.h"

int main()
{
    //#ifdef REM_TEST_FILE
    //#ifdef REM_TEST_REGEX
    //unsigned char flags = ENABLE_COLOR | ENABLE_LINE_NUMBER | ENABLE_WORD;
    options option;
    //option.a = 3;
    //option.b = 2;
    option.c = 5;
    match_in_file("/home/ahmet/projects/c/rem/LICENSE", "the", 0, option);
    //int count = match_in_file(REM_TEST_FILE, REM_TEST_REGEX, flags);
    //#else
    //    printf("Regex is not given.\n");
    //#endif
    //#else
    //   printf("Test file is not given.\n");
    //#endif
    return 0;
}
