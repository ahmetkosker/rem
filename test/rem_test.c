#include <stdio.h>
#include "../src/rem.h"
#include "../src/options.h"

int main()
{
#ifdef REM_TEST_FILE
#ifdef REM_TEST_REGEX
    unsigned char flags = ENABLE_COLOR | ENABLE_LINE_NUMBER | ENABLE_WORD;
    int count = match_in_file(REM_TEST_FILE, REM_TEST_REGEX, flags);
#else
    printf("Regex is not given.\n");
#endif
#else
    printf("Test file is not given.\n");
#endif
    return 0;
}
