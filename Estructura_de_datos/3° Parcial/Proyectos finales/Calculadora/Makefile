# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall -lncurses
SRC = Calcula.c FunCalcula.c lista.c validaciones.c formato.c validaciones.h lista.h formato.h FunCalcula.h  -lncurses
OBJ = Calcula.o lista.o validaciones.o formato.o FunCalcula.o -lncurses


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o Calcula $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

lista.o: lista.c lista.h
validaciones.o: validaciones.c validaciones.h
formato.o: formato.c formato.h
FunCalcula.o: FunCalcula.c FunCalcula.h
Calcula.o: Calcula.c lista.h validaciones.h formato.h
