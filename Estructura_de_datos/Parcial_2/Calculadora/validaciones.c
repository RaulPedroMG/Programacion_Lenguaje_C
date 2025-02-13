/*2011
 * Descripción: Contiene  las validaciones que se deben de relizar al 
 * introducir datos a las estructuras
 * */
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "formato.h"
#include "validaciones.h"

void LeeEntero(char *cad,int max,int r, int c)
{
	int aux;
	int ind, band;
	noecho();
	keypad(stdscr, TRUE);
	ind = band =0;
	while (!band && ind < max -1){
		do{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isdigit(aux) && aux != '-');
		switch(aux){
			case ENT:
				if(ind == 0){
					band = 0;
					cad[ind] = '\0';
					Error("E r r 0 r : Ingresa un número",20);
				}else{
					if(ind > 0){
						band = 1;
						cad[ind] = '\0';
					}
				}
				break;
			case RET:
				if(ind > 0){
					ind--;
					move(r,c+ind);
					printw(" ");
					move(r,c+ind);
				}
				break;
			case '-':
				if (!ind){
					cad[ind] = aux;
					move(r,c+ind);
					printw("%c",aux);
					ind++;
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




int Rango(int men , int may,int r,int c)
{
	int h=0,valor;
	char cad[2];
	while(h==0){
		echo();
		mvprintw(r,c,"      ");
		LeeEntero(cad,3,r,c+2);
		valor = atoi(cad);
		if(valor>=men && valor<=may){
			 h=1;
		}
	}
	return valor;
}
