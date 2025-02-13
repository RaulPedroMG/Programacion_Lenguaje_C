CC=gcc

all:validanc.o prueba.o
	$(CC) validanc.o prueba.o -o prueba -lncurses
validanc.o: validanc.c
	$(CC) -c validanc.c
prueba.o: prueba.c
	$(CC) -c prueba.c
.phony clean:
	rm *.o
