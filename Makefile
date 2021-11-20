CFLAGS=-Wall -Wextra -std=c11 -pedantic -O3

scale: scale.c
	$(CC) $(CFLAGS) -o scale scale.c
