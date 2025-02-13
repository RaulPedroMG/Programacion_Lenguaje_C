# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall -lncurses
SRC = cola.c cola.h
OBJ = 


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o  $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas


cola.o: cola.c cola.h
formato.o: formato.c formato.h

