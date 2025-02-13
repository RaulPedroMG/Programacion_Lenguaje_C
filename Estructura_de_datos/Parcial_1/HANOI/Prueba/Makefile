# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -c -Wall -lncurses
SRC = Hanoi-0224.c torres.c pilas.c formato.c archivos.c torres.h pilas.h formato.h archivos.h variables.h
OBJ = Hanoi-0224.o torres.o pilas.o formato.o archivos.o


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o Hanoi-0224 $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

torres.o: torres.c torres.h
pilas.o: pilas.c pilas.h
formato.o: formato.c formato.h
archivos.o: archivos.c archivos.h
Hanoi-0224.o: Hanoi-0224.c torres.h pilas.h formato.h archivos.h variables.h
