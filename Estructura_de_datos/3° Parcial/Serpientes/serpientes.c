#include "formato.h"
int main()
{
	char name1[23], name2[23];
	initscr();
	echo();
	refresh();
	init_curses();
	bkgd(COLOR_PAIR(1));
	Centrar("Bienvenidos al juego SERPIENTES Y ESCALERAS",4);
	Centrar("Nombre de jugadores",6);
	attron(COLOR_PAIR(18));
	Centrar("Player 1:                     ",8);
	Centrar("Player 2:                     ",10);
	attroff(COLOR_PAIR(18));
	attron(COLOR_PAIR(24));
	LeeNombre(name1,23,8,70);
	LeeNombre(name2,23,10,70);
	attroff(COLOR_PAIR(24));
	clear();
	echo();
	pintar(name1,name2);
	endwin();
	return 0;
}

