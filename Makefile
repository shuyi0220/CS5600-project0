CC = gcc
FILES_caesar = caesar.h caesar.c caesar_main.c
FILES_queue = queue.h queue.c queue_main.c
FILES_ciphered_queue = caesar.c queue.c ciphered_queue_main.c

# CFLAGS := -Wall

all: caesar queue ciphered_queue

caesar:
	$(CC) -o caesar $(FILES_caesar)

queue:
	$(CC) -o queue $(FILES_queue)


ciphered_queue:
	$(CC) -o ciphered_queue $(FILES_ciphered_queue)

clean:
	rm -f caesar queue ciphered_queue
