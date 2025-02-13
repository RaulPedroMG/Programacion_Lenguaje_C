# include <ncurses.h>
#include "validanc.h"
#include "formato.h"
#include "estruct.h"
#define MAX 5

int main ()
{
	Alumno lista[ML];
	int total=0, i, opc;
	char aux[MAT];

	char nombre[MAX];
	initscr();
	
	keypad(stdscr, TRUE);
	noecho();
	mvprintw(2,4,"1:llenar lista");
	mvprintw(4,4,"2:imprimir lista");
	mvprintw(6,4,"3:bucar dato lista");
	mvprintw(8,4,"4:eliminar dato");
	mvprintw(10,4,"5:salir");
	//mvprintw(4,4,"Total: %d",total);
	//getch();
	LeeDatos(lista,&total);
	//mvprintw(5,4,"Total: %d",total);
	//getch();
	ImpDatos(lista,total);
	
	
	LeeMatricula(aux,5,15);
	i = Buscar(lista, &total, aux);
	imprimir (lista,i);
	LeeMatricula(aux,5,15);
	Eliminar(lista,&total, aux);
	ImpDatos(lista,total);
	
	endwin();
	return 0;
} 
