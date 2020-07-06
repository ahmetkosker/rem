#ifndef _REM_FILESYSTEM_H
#define _REM_FILESYSTEM_H

int walk_in_dir(char *dir, void (*callback)(char *));

#endif