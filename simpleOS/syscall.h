#ifndef SYSCALL_H
#define SYSCALL_H

void init_open_file_table(void);
int sys_open(const char *filename);
int sys_read(int fd, char *buffer, int nbytes);
int sys_close(int fd);
int sys_write_file(const char *filename, const char *content);

#endif
