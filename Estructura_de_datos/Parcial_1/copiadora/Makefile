# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall
SRC = copiadora.c cola.c cola.h
OBJ = copiadora.o cola.o


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o copiadora $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

cola.o: cola.c cola.h
impresora.o: copiadora.c cola.h
