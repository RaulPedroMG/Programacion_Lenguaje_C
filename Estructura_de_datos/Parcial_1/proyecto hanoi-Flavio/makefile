CC=gcc

all: Hanoi.o Pila.o JuegoHanoi.o
	$(CC) Hanoi.o Pila.o JuegoHanoi.o -o JuegoHanoi.exe -lncurses -lm
Hanoi.o:Hanoi.c
	$(CC) -c Hanoi.c
Pila.o :Pila.c
	$(CC) -c pila.c
JuegoHanoi.o: JuegoHanoi.c
	$(CC) -c JuegoHanoi.c
.phony clean:
	rm *.o
