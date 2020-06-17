#include <stdio.h>
#include "../src/filesystem.h"
#include "../src/rem.h"
#include "../src/options.h"

void callback(char *filepath)
{
    unsigned char flags = ENABLE_NOTHING | ENABLE_COLOR | ENABLE_LINE_NUMBER;
    int count = match_in_file(filepath, "\"", flags);
    printf("%s dosyasında %d kadar \" vardır.\n  ", filepath, count);
}

int main()
{
#ifdef REM_TEST_DIR
    walkindir(REM_TEST_DIR, &callback);
#else
    printf("Test directory is not given.\n");
#endif
    return 0;
}