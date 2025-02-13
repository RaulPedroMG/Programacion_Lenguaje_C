# include <ncurses.h>
#include "validanc.h"
#include "formato.h"
#include "estruct.h"
#define MAX 40

int main ()
{
	Alumno lista[ML];
	int total=0;
	

	char nombre[MAX];
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	//mvprintw(4,4,"Total: %d",total);
	//getch();
	LeeDatos(lista,&total);
	//mvprintw(5,4,"Total: %d",total);
	//getch();
	ImpDatos(lista,total);
	
	
	
	endwin();
	return 0;
} 
