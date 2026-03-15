#include <stdio.h>
#include <string.h>
#include "fs.h"

static FileEntry files[MAX_FILES];

void init_fs(void) {
    for (int i = 0; i < MAX_FILES; i++) {
        files[i].used = 0;
    }

    write_file("readme.txt", "Welcome to SimpleOS");
    write_file("notes.txt", "This is a kernel simulation.");
}

void list_files(void) {
    printf("\nFiles:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used) {
            printf("- %s (%d bytes)\n", files[i].name, files[i].size);
        }
    }
    printf("\n");
}

int write_file(const char *filename, const char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used && strcmp(files[i].name, filename) == 0) {
            strncpy(files[i].content, content, MAX_FILE_CONTENT - 1);
            files[i].content[MAX_FILE_CONTENT - 1] = '\0';
            files[i].size = (int)strlen(files[i].content);
            return 0;
        }
    }

    for (int i = 0; i < MAX_FILES; i++) {
        if (!files[i].used) {
            files[i].used = 1;
            strncpy(files[i].name, filename, MAX_FILENAME - 1);
            files[i].name[MAX_FILENAME - 1] = '\0';

            strncpy(files[i].content, content, MAX_FILE_CONTENT - 1);
            files[i].content[MAX_FILE_CONTENT - 1] = '\0';
            files[i].size = (int)strlen(files[i].content);
            return 0;
        }
    }

    return -1;
}

const char *read_file(const char *filename) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used && strcmp(files[i].name, filename) == 0) {
            return files[i].content;
        }
    }
    return NULL;
}
