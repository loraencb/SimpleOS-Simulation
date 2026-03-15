#include <stdio.h>
#include "syscall.h"
#include "fs.h"

int sys_read_file(const char *filename) {
    const char *data = read_file(filename);
    if (!data) {
        printf("sys_read: file '%s' not found\n", filename);
        return -1;
    }

    printf("%s\n", data);
    return 0;
}

int sys_write_file(const char *filename, const char *content) {
    if (write_file(filename, content) == 0) {
        printf("sys_write: wrote to '%s'\n", filename);
        return 0;
    }

    printf("sys_write: failed to write '%s'\n", filename);
    return -1;
}
