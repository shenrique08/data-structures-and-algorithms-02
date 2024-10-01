CC = gcc
CFLAGS = -Wall

all: main

main: main.o arvore_binaria.o
	$(CC) $(CFLAGS) -o main main.o arvore_binaria.o

main.o: main.c arvore_binaria.h
	$(CC) $(CFLAGS) -c main.c

arvore_binaria.o: arvore_binaria.c arvore_binaria.h
	$(CC) $(CFLAGS) -c arvore_binaria.c

clean:
	rm -f *.o main
