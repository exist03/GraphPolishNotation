CC=gcc
CFLAGS=-Wall -Werror -Wextra
all:
	$(CC) $(CFLAGS) stack.c graph.c to_polish.c display.c value.c -o graph
