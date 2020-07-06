#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "./options.h"
#include "./filesystem.h"
#include "./rem.h"

/* Walk in given directory recursively and run the callback function for each file (and directory). */
int walk_in_dir(char *dir, void (*callback)(char *))
{
    DIR *dirp = opendir(dir);

    if (dirp == NULL)
        return -1;

    struct dirent *file = readdir(dirp);
    while (file != NULL)
    {
        char path[500];
        char *slash = "/";
        strcpy(path, dir);
        strcat(path, slash);
        strcat(path, file->d_name);
        if (file->d_type == DT_REG)                                                //If file is a regular file.(DT_REG = 8)
            callback(path);                                                        //Do what the user want.
        else if (file->d_type == DT_DIR)                                           //If file is a directory.(DT_DIR = 4)
            if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) // (.. = Previous directory) // (. = Current directory)
                walk_in_dir(path, callback);

        // Filename holds file path.
        file = readdir(dirp);
    }
    closedir(dirp);
    return 0;
}
