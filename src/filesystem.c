#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "./options.h"
#include "./filesystem.h"
#include "./rem.h"

void walkindir(char *dirname, void (*callback)(char *))
{
    DIR *dirp = opendir(dirname);

    if (dirp == NULL)
    {
        printf("Can not open directory.\n");
        return;
    }
    struct dirent *file = readdir(dirp);
    while (file != NULL)
    {
        if (file->d_type == DT_REG)
        {
            unsigned char flags = ENABLE_COLOR | ENABLE_LINE_NUMBER;
            char filename[500];
            char *slash = "/";
            strcpy(filename, dirname);
            strcat(filename, slash);
            strcat(filename, file->d_name);
            walkindir(filename, callback);
        }
        else if (file->d_type == DT_DIR)
        {
            if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0 && strcmp(file->d_name, ".git"))
            {
                char nesteddir[500];
                char *slash = "/";
                strcpy(nesteddir, dirname);
                strcat(nesteddir, slash);
                strcat(nesteddir, file->d_name);
                walkindir(nesteddir, callback);
            }
        }
        file = readdir(dirp);
    }
    closedir(dirp);
}
