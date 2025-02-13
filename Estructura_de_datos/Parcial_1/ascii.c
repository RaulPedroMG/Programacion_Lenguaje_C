/*
	UNSIS 2011
	Nombre: ascii.c
	Descripción: devuel el valor el numero ascii de alguna tecla
	Autor: SKRA
*/
#include <ncurses.h>
int main()
{
	char car;
	int x=0;
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	clear();
	while(x==0){
		mvprintw(2,5,"Pulsa una tecla");
		car= getch();
		mvprintw(4,5,"Ascii %d:", car);
		if(car==7)
			x=1;
	}
	getch();
	endwin();
	return 0;
}
