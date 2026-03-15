#ifndef FS_H
#define FS_H

#include "common.h"

typedef struct {
    int used;
    char name[MAX_FILENAME];
    char content[MAX_FILE_CONTENT];
    int size;
} FileEntry;

void init_fs(void);
void list_files(void);
int write_file(const char *filename, const char *content);
const char *read_file(const char *filename);

#endif
