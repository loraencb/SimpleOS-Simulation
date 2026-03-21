#ifndef FS_H
#define FS_H

#define MAX_FILES 10
#define MAX_FILENAME 32
#define MAX_FILE_CONTENT 256

typedef struct {
    int used;
    char name[MAX_FILENAME];
    char content[MAX_FILE_CONTENT];
    int size;
} FileEntry;

extern FileEntry files[MAX_FILES];

void init_fs(void);
void list_files(void);
int write_file(const char *filename, const char *content);
const char *read_file(const char *filename);

#endif