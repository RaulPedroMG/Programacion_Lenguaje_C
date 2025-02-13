# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall
SRC = Lista-R.c lista.c lista.h
OBJ = Lista-R.o lista.o


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o Lista-R $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

lista.o: lista.c lista.h
Lista-R.o: Lista-R.c lista.h
