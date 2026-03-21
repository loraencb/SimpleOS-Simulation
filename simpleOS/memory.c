#include <stdio.h>
#include "memory.h"

static int memory_bitmap[MAX_PAGES];

void init_memory(void) {
    for (int i = 0; i < MAX_PAGES; i++) {
        memory_bitmap[i] = 0;
    }
}

int allocate_pages(int num_pages) {
    int count = 0;
    int start = -1;

    for (int i = 0; i < MAX_PAGES; i++) {
        if (memory_bitmap[i] == 0) {
            if (count == 0) {
                start = i;
            }
            count++;
            if (count == num_pages) {
                for (int j = start; j < start + num_pages; j++) {
                    memory_bitmap[j] = 1;
                }
                return start;
            }
        } else {
            count = 0;
            start = -1;
        }
    }
    return -1;
}

void free_pages(int start_page, int num_pages) {
    for (int i = start_page; i < start_page + num_pages && i < MAX_PAGES; i++) {
        memory_bitmap[i] = 0;
    }
}

void print_memory_status(void) {
    int used = 0;
    int free_count = 0;

    for (int i = 0; i < MAX_PAGES; i++) {
        if (memory_bitmap[i]) {
            used++;
        } else {
            free_count++;
        }
    }

    printf("\nMemory Status:\n");
    printf("Total Pages: %d\n", MAX_PAGES);
    printf("Used Pages : %d\n", used);
    printf("Free Pages : %d\n", free_count);
    printf("Bitmap     : ");
    for (int i = 0; i < MAX_PAGES; i++) {
        printf("%d", memory_bitmap[i]);
    }
    printf("\n\n");
}