CC = gcc
CFLAGS = -g -Wall
SRC = Practcola.c cola.c cola.h
OBJ = Practcola.o cola.o


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o Practcola $(OBJ)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

cola.o: cola.c cola.h
Practcola.o: Practcola.c cola.h
