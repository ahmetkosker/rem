#include <stdio.h>
#include "../src/filesystem.h"
#include "../src/rem.h"
#include "../src/options.h"
void callback(char *filepath)
{
#ifdef REM_TEST_REGEX
    unsigned char flags = ENABLE_NOTHING | ENABLE_COLOR | ENABLE_LINE_NUMBER;
    int count = match_in_file(filepath, REM_TEST_REGEX, flags);
    printf("%s dosyasında %d adet vardır.\n", filepath, count);
#else
    printf("%s\n", filepath);
#endif
}

int main()
{
#ifdef REM_TEST_DIR
    walk_in_dir(REM_TEST_DIR, &callback);
#else
    printf("Test directory is not given.\n");
#endif
    return 0;
}