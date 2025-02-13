# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall -lncurses
SRC = serpientes.c escalera.c formato.c escalera.h formato.h  -lncurses
OBJ = serpientes.o escalera.o formato.o -lncurses


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o serpientes $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas


escalera.o: escalera.c escalera.h
formato.o: formato.c formato.h
serpientes.o: serpientes.c escalera.h formato.h
