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



void LeeMatricula(char *cad,int max, int r, int c)
/*EQUIPO 1*/
{
int i=0, band=0;
int aux;
initscr();
keypad(stdscr, TRUE);
noecho();
while (!band && i < max -1)
	{
		do
		{
			move(r,c+i);
			aux = getch();
		}while (aux != RET && aux != ENT && !isdigit(aux) && aux != ' ');
		switch(aux)
		{
			case ENT://retorno de carro
								band = 1;
								cad[i] = '\0';
								break;
			case RET://backspace <--  retroceso
								if (i > 0)
								{
									i--;
									move(r,c+i);
									printw(" ");
									move(r,c+i);
								}
								break;
			default :
							if(aux != ' '){
								cad[i] = aux;
								move(r,c+i);
								printw("%c",aux);
								i++;
							}
		}
	}

}



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
void LeeRealP(char *cad, int max, int r, int c)
 /*Esta funcion tiene como como finalidad la lectura de un numero real
	*positivo, tiene como argumentos una cadena donde se almacena el dato
	*leido, el maximo de esa cadena, la columna y el renglon donde empezara
	*a imprimir los datos leidos*/
 {
	int aux;
	int ind, band,punto;
	noecho();
	ind = band = punto = 0;
	while (!band && ind < max -1)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}
		while (aux != RET && aux != 10 && !isdigit(aux) && aux != '.');
		switch(aux)
		{
			case '.':
					if (!punto)
					{
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						punto = 1;
					}
					break;
			case 10:
					band = 1;
					cad[ind] = '\0';
					break;
			case RET:
					if(ind > 0)
					{
						ind--;
						if (cad[ind] == '.')
							punto = 0;
						move(r,c+ind);
						printw(" ");
					}
					break;
			default :
					cad[ind] = aux;
					move(r,c+ind);
					printw("%c",aux);
					ind++;
		}
	}
	if (ind == max -1)
		cad[ind] = '\0';

 }
