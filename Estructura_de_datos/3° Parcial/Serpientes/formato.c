#include "formato.h"

void Centrar(char *cad, int r)
{
	int ren,col;
	getmaxyx(stdscr, ren, col);
	col = (col / 2) - (strlen(cad) / 2);
	mvprintw(r,col,"%s",cad);
	
}

void LeerCentrar(char *cad, int r)
{
	int ren,col;
	getmaxyx(stdscr, ren, col);
	col = (col / 2) - (strlen(cad) / 2);
	setbuf(stdin, NULL);
	mvscanw(r,col-3,"%[a-z]",cad);
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
	attron(COLOR_PAIR(10));
	getmaxyx(stdscr, ren, col);
	col = (col / 2) - (strlen(cad) / 2);
	attron(A_BLINK);
	mvprintw(r,col,"%s",cad);
	getch();
	attroff(A_BLINK);
	for (i=0;i<strlen(cad);i++)
		mvprintw(r,col+i,"  ");
	
	attroff(COLOR_PAIR(10));
}

void LeeNombre(char *cad,int max,int r, int c)
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
				if(ind==0){
					band = 0;
					cad[ind] ='\0';
					Error("Ingrese su nombre",15);
				}else{
					if(ind>0){
						band = 1;
						cad[ind] = '\0';
					}
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
				if(cad[ind-1]==' ' || ind==0){
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
		//Error("Tamaño maximo de la cadena alcanzado",r+1);
		cad[ind] = '\0';
	}
	return;
}
