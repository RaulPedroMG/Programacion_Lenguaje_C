CC=gcc

all: estruct.o validanc.o formato.o prueba.o
	$(CC) estruct.o validanc.o formato.o prueba.o -o prueba -lncurses
estruct.o:estruct.c
	$(CC) -c estruct.c
validanc.o:validanc.c
	$(CC) -c validanc.c
formato.o:formato.c
	$(CC) -c formato.c
principal.o:prueba.c
	$(CC) -c prueba.c
.phony clean:
	rm *.o
