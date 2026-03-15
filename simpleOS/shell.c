#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include "process.h"
#include "memory.h"
#include "fs.h"
#include "syscall.h"

static void print_help(void) {
    printf("\nAvailable commands:\n");
    printf("help                 - show commands\n");
    printf("ps                   - list processes\n");
    printf("sched                - run one scheduler tick\n");
    printf("mem                  - show memory bitmap status\n");
    printf("ls                   - list files\n");
    printf("cat <file>           - display file contents\n");
    printf("write <file> <text>  - write text to file\n");
    printf("run                  - create a demo process\n");
    printf("exit                 - quit simulator\n\n");
}

void run_shell(void) {
    char input[512];

    while (1) {
        printf("simpleos> ");

        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "help") == 0) {
            print_help();
        } else if (strcmp(input, "ps") == 0) {
            list_processes();
        } else if (strcmp(input, "sched") == 0) {
            run_scheduler_tick();
        } else if (strcmp(input, "mem") == 0) {
            print_memory_status();
        } else if (strcmp(input, "ls") == 0) {
            list_files();
        } else if (strncmp(input, "cat ", 4) == 0) {
            char *filename = input + 4;
            sys_read_file(filename);
        } else if (strncmp(input, "write ", 6) == 0) {
            char *rest = input + 6;
            char *space = strchr(rest, ' ');

            if (!space) {
                printf("Usage: write <file> <text>\n");
                continue;
            }

            *space = '\0';
            char *filename = rest;
            char *content = space + 1;

            sys_write_file(filename, content);
        } else if (strcmp(input, "run") == 0) {
            int start = allocate_pages(2);
            if (start == -1) {
                printf("Not enough memory to create process\n");
            } else {
                int pid = create_process("demo_process", 2);
                if (pid == -1) {
                    printf("Process table full\n");
                } else {
                    printf("Created process PID %d using pages %d-%d\n", pid, start, start + 1);
                }
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting SimpleOS simulator.\n");
            break;
        } else if (strlen(input) == 0) {
        } else {
            printf("Unknown command. Type 'help'.\n");
        }
    }
}
