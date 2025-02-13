#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <time.h>
#include "torres.h"
#include "variables.h"
#include "pilas.h"
#include "formato.h"

void LeeNombre(char *cad,int max,int r, int c)
/*Descripci¢n: Este procedimiento permite capturar un nombre, validando
 *caracter por caracter, solo se permiten letras del alfabeto en ingls
 *y espacios en blanco.
*/
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
		}while (aux != RET && aux != ENT && !isalpha(aux));
		switch(aux){
			case ENT://retorno de carro
					if(ind>0){
						band = 1;
						cad[ind] = '\0';
					}
					break;
			case RET://backspace <--  retroceso
				if (ind > 0){
					ind--;
					move(r,c+ind);
					printw(" ");
					move(r,c+ind);
				}
				break;
			default :		
				if(ind==0){
					cad[ind] = toupper(aux);
					aux=toupper(aux);
					move(r,c+ind);
					printw("%c",aux);
					ind++;
				}else{
					cad[ind] = aux;
					move(r,c+ind);
					printw("%c",aux);
					ind++;
				}
		}
	}
	if (ind == max -1){
		//move(r+1,c);
		//Error("Tamaño maximo de la cadena alcanzado",11);
		mvprintw(r+1,c,"Tamaño maximo de la cadena alcanzado");
		cad[ind] = '\0';
	}

}


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
		}while (aux != RET && aux != ENT && !isdigit(aux));
		switch(aux){
			case ENT:
								band = 1;
								cad[ind] = '\0';
								break;
			case RET:
								if (ind > 0)
								{
									ind--;
									move(r,c+ind);
									printw(" ");
									move(r,c+ind);
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


int LeeInt(int r, int c)
{
	char cad[12];
	int valor;
	LeeEntero(cad,12,r,c);
	valor = atoi(cad);
	return valor;
}

void Centrar(char *cad, int r)
{
	int ren,col;
	getmaxyx(stdscr, ren, col);
	col = (col / 2) - (strlen(cad) / 2);
	mvprintw(r,col,"%s",cad);
}

void Derecha(char *cad, int r)
{
	int ren,col;
	getmaxyx(stdscr, ren, col);
	col = col- strlen(cad);
	mvprintw(r,col,"%s",cad);
}

void Error(char *cad, int r)
{
	int ren,col,i;
	getmaxyx(stdscr, ren, col);
	col = (col / 2) - (strlen(cad) / 2);
	attron(A_BLINK);
	mvprintw(r,col,"%s",cad);
	getch();
	attroff(A_BLINK);
	for (i=0;i<strlen(cad);i++)
		mvprintw(r,col+i,"  ");
	
}
int Menu1()
{
	int i;
	Centrar("######################################",4);
	Centrar("Universidad de la Sierra Sur",2);
	Centrar("BIENVENIDO",5);
	mvprintw(7,16,"1.- Jugar");
	mvprintw(8,16,"2.- Ver ranking");
	mvprintw(9,16,"3.- Salir ");
	attroff(COLOR_PAIR(2));
	mvprintw(10,16,"                         ");
	mvprintw(10,16,"ELIJE UNA OPCION");
	i=Rango(1,3,10,33);
	return i;
}
int Rango(int men , int may,int r,int c)
{
	int h=0,valor;
	char cad[4];
	while(h==0){
		echo();
		LeeEntero(cad,4,r,c);
		valor = atoi(cad);
		if(valor>=men && valor<=may){
			 h=1;
		}
	}
	return valor;
}

int AvisoConfirmacion(char *cad)
{
	int i=0,b=0;
	char resp;
	while(b==0){
		//clear();
		echo();
		mvprintw(4,6,"%s",cad);
		mvscanw(5,6,"%c",&resp);
		if(resp=='s' || resp=='S'){
			i=1;
			b=1;
		}else{
			b=1;
		}
	}
	clear();
	return  i;
}

void titulo(char *impre,int r1, int r2, int r3)
{
	Centrar(impre,r1);
	Centrar("Universidad de la Sierra Sur",r2);
	Centrar("INFORMÁTICA",r3);
}

void iniciando()
{
	echo();
	refresh();
	printw("\n\tIniciando programas...");
	echo();
	sleep(2);
	printw("\n\tIniciando graficos...");
	echo();
	sleep(2);
	printw("\n\tIniciando ventanas...");
	sleep(2);
	printw("\n\tCargando archivos...");
	sleep(2);
	printw("\n\t...");
}
