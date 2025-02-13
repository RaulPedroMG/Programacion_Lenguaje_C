#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include "escalera.h"
#define RET 127
#define ENT 10
void Centrar(char *cad, int r);
void Derecha(char *cad, int r);	
void Error(char *cad, int r);	
void LeerCentrar(char *cad, int r);
void LeeNombre(char *cad,int max,int r, int c);
