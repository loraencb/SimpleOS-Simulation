#ifndef SYSCALL_H
#define SYSCALL_H

#define MAX_OPEN_FILES 10

typedef struct {
    int used;
    int file_index;
    int offset;
} OpenFile;

void init_open_file_table(void);
int sys_open(const char *filename);
int sys_read(int fd, char *buffer, int size);
int sys_close(int fd);
int sys_write_file(const char *filename, const char *content);

#endif