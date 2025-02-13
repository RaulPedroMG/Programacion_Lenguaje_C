# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall
SRC = EjPila.c Pila.c Pila.h
OBJ = EjPila.o Pila.o


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o EjPila $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

Pila.o: Pila.c Pila.h
EjPila.o: EjPila.c Pila.h