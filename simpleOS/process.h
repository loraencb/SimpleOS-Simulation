#ifndef PROCESS_H
#define PROCESS_H

#include "common.h"

typedef enum {
    NEW = 0,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

typedef struct {
    int pid;
    char name[32];
    ProcessState state;
    int pages_allocated;
    int used;
} PCB;

void init_process_table(void);
int create_process(const char *name, int pages_needed);
void list_processes(void);
void run_scheduler_tick(void);
const char *state_to_string(ProcessState state);

#endif
