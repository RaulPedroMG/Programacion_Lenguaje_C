#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "validaciones.h"
#include "formato.h"
#include "lista.h"
#include "FunCalcula.h"
int main()
{
	char num1[1000], num2[1000];
	int opc,negativo=0;
	struct nodo *lista1,*lista2;
	initscr();
	init_curses();
	bkgd(COLOR_PAIR(1));
	do{
	opc=MenuAd();
	switch(opc){
		case 1:
			clear();
			Leernumero(num1,num2, "*** S  U  M  A ***");
			Agregarlista(num1,num2,&lista1,&lista2,opc,&negativo);
			sumar(lista1,lista2);
			getch();
			break;
		case 2:
			clear();
			Leernumero(num1,num2, "*** R  E  S  T  A ***");
			Agregarlista(num1,num2,&lista1,&lista2,opc,&negativo);
			restar(lista1,lista2,negativo);
			negativo=0;
			getch();
			break;
		case 3:
			clear();
			Leernumero(num1,num2, "*** M  U  L  T  I  P  L  I  C  A  I  O  N ***");
			Agregarlista(num1,num2,&lista1,&lista2,opc,&negativo);
			if(strlen(num1) < strlen(num2))
				multip(lista1,lista2,negativo,num2);
			else
				multip(lista1,lista2,negativo,num1);
			negativo=0;
			getch();
			break;
		
		}
	}while(opc!=4);
	endwin();
	return 0;
}
