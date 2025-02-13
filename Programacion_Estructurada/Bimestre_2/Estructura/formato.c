#include <ncurses.h>
#include <string.h>
#include "formato.h"

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
