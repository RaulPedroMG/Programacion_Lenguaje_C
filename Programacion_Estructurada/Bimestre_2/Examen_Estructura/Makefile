CC=gcc

all: validanc.o formato.o prueba.o
	$(CC) validanc.o formato.o prueba.o -o prueba -lncurses
validanc.o:validanc.c
	$(CC) -c validanc.c
formato.o:formato.c
	$(CC) -c formato.c
principal.o:prueba.c
	$(CC) -c prueba.c
.phony clean:
	rm *.o
