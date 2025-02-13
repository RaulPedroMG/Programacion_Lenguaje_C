#include <ncurses.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Centrar(char *cad, int r);
void Derecha(char *cad, int r);	
void Error(char *cad, int r);	
void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno);
void init_curses();
