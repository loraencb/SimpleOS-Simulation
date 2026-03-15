CC=gcc
CFLAGS=-Wall -Wextra -std=c11
OBJ=main.o process.o memory.o fs.o syscall.o shell.o

all: simpleos

simpleos: $(OBJ)
	$(CC) $(CFLAGS) -o simpleos $(OBJ)

clean:
	rm -f *.o simpleos
