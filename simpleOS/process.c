#include <stdio.h>
#include <string.h>
#include "process.h"

static PCB process_table[MAX_PROCESSES];
static int next_pid = 1;
static int current_index = -1;

void init_process_table(void) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        process_table[i].used = 0;
    }
}

const char *state_to_string(ProcessState state) {
    switch (state) {
        case NEW: return "NEW";
        case READY: return "READY";
        case RUNNING: return "RUNNING";
        case WAITING: return "WAITING";
        case TERMINATED: return "TERMINATED";
        default: return "UNKNOWN";
    }
}

int create_process(const char *name, int pages_needed) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (!process_table[i].used) {
            process_table[i].used = 1;
            process_table[i].pid = next_pid++;
            strncpy(process_table[i].name, name, sizeof(process_table[i].name) - 1);
            process_table[i].name[sizeof(process_table[i].name) - 1] = '\0';
            process_table[i].state = READY;
            process_table[i].pages_allocated = pages_needed;
            return process_table[i].pid;
        }
    }
    return -1;
}

void list_processes(void) {
    printf("\nPID   NAME                 STATE       PAGES\n");
    printf("----  -------------------  ----------  -----\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (process_table[i].used) {
            printf("%-4d  %-19s  %-10s  %-5d\n",
                   process_table[i].pid,
                   process_table[i].name,
                   state_to_string(process_table[i].state),
                   process_table[i].pages_allocated);
        }
    }
    printf("\n");
}

void run_scheduler_tick(void) {
    int found = 0;

    if (current_index >= 0 &&
        process_table[current_index].used &&
        process_table[current_index].state == RUNNING) {
        process_table[current_index].state = READY;
    }

    for (int i = 1; i <= MAX_PROCESSES; i++) {
        int idx = (current_index + i) % MAX_PROCESSES;
        if (process_table[idx].used && process_table[idx].state == READY) {
            process_table[idx].state = RUNNING;
            current_index = idx;
            found = 1;
            printf("Scheduler: process %s (PID %d) is now RUNNING\n",
                   process_table[idx].name,
                   process_table[idx].pid);
            break;
        }
    }

    if (!found) {
        printf("Scheduler: no READY processes found\n");
    }
}