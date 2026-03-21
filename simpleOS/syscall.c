#include <stdio.h>
#include <string.h>
#include "syscall.h"
#include "fs.h"

static OpenFile open_file_table[MAX_OPEN_FILES];

void init_open_file_table(void) {
    for (int i = 0; i < MAX_OPEN_FILES; i++) {
        open_file_table[i].used = 0;
        open_file_table[i].file_index = -1;
        open_file_table[i].offset = 0;
    }
}

int sys_open(const char *filename) {
    int file_index = -1;

    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used && strcmp(files[i].name, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        return -1;
    }

    for (int i = 0; i < MAX_OPEN_FILES; i++) {
        if (!open_file_table[i].used) {
            open_file_table[i].used = 1;
            open_file_table[i].file_index = file_index;
            open_file_table[i].offset = 0;
            return i;
        }
    }

    return -1;
}

int sys_read(int fd, char *buffer, int size) {
    if (fd < 0 || fd >= MAX_OPEN_FILES || !open_file_table[fd].used) {
        return -1;
    }

    int file_index = open_file_table[fd].file_index;
    const char *content = files[file_index].content;
    int offset = open_file_table[fd].offset;
    int file_size = files[file_index].size;

    if (offset >= file_size) {
        return 0;
    }

    int bytes_to_read = file_size - offset;
    if (bytes_to_read > size) {
        bytes_to_read = size;
    }

    memcpy(buffer, content + offset, bytes_to_read);
    open_file_table[fd].offset += bytes_to_read;

    return bytes_to_read;
}

int sys_close(int fd) {
    if (fd < 0 || fd >= MAX_OPEN_FILES || !open_file_table[fd].used) {
        return -1;
    }

    open_file_table[fd].used = 0;
    open_file_table[fd].file_index = -1;
    open_file_table[fd].offset = 0;

    return 0;
}

int sys_write_file(const char *filename, const char *content) {
    return write_file(filename, content);
}