# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = -g -Wall -lncurses
SRC = avion2.c fpavion.c cola.c fpavion.h cola.h -lncurses
OBJ = avion2.o fpavion.o cola.o -lncurses


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o avion2 $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

fpavion.o:fpavion.c fpavion.h
cola.o: cola.c cola.h
avion2.o: avion2.c fpavion.h cola.h
