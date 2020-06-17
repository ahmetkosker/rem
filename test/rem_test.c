#include <stdio.h>
#include "../src/rem.h"
#include "../src/options.h"

int main()
{
#ifdef REM_TEST_FILE
    unsigned char flags = ENABLE_COLOR | ENABLE_LINE_NUMBER;
    int count = match_in_file(REM_TEST_FILE, "information", flags);
    printf("%d", count);
#else
    printf("Test file is not given.\n");
#endif
    return 0;
}
