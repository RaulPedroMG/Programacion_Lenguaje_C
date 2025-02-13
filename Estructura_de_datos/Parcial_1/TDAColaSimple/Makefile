# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall
SRC = ejecola.c cola.c cola.h
OBJ = ejecola.o cola.o


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o ejecola $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

cola.o: cola.c cola.h
ejecola.o: ejecola.c cola.h
