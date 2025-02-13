/*
Nombre: validanc.c
Autor:
Fecha: 31 de mayo de 2010
*/
#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include "validanc.h"
#include "formato.h"



float LeeFloatR(int r, int c,float min, float max)
{
	char cad[5];
	float valor;
	do
	{
		LeeRealP(cad,5,r,c);
		valor = atof(cad);
		if (valor < min || valor > max)
		{
			Error("Fuera de rango, intente nuevamente!",r+2);
			mvprintw(r,c,"     ");
		}
	}while (valor < min || valor > max);
	return valor;
}
