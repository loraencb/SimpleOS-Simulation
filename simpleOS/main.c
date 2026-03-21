#include <stdio.h>
#include "process.h"
#include "memory.h"
#include "fs.h"
#include "shell.h"
#include "syscall.h"

int main(void) {
    printf("SimpleOS Kernel Simulator Started\n");
    printf("Initializing subsystems...\n");

    init_process_table();
    init_memory();
    init_fs();
    init_open_file_table();

    create_process("init", 1);
    create_process("shell", 1);

    printf("Initialization complete.\n");
    printf("Type 'help' for available commands.\n\n");

    run_shell();

    return 0;
}
