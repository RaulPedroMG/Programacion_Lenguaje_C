# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall
SRC = Palindromo.c Pila.c Pila.h
OBJ = Palindromo.o Pila.o


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o Palindromo $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

Pila.o: Pila.c Pila.h
Palindromo.o: Palindromo.c Pila.h
