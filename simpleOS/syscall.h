#ifndef SYSCALL_H
#define SYSCALL_H

int sys_read_file(const char *filename);
int sys_write_file(const char *filename, const char *content);

#endif
