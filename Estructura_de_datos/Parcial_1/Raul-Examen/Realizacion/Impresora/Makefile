# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall
SRC = Impresora.c cola.c cola.h
OBJ = Impresora.o cola.o


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o Impresora $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

cola.o: cola.c cola.h
Impresora.o: Impresora.c cola.h
