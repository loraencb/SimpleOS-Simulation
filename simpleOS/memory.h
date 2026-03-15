#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"

void init_memory(void);
int allocate_pages(int num_pages);
void free_pages(int start_page, int num_pages);
void print_memory_status(void);

#endif
