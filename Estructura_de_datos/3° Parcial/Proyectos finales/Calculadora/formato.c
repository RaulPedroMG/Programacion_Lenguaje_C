#include <ncurses.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
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

void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno)
{
	int i,j;

	for(i=filaO; i<filaO+ancho;i++)	
		for(j=columnaO; j<columnaO+largo;j++){
			if(i==filaO || i==filaO+ancho-1)		
				mvprintw(i,j,"%c",borde);
			else 
				if(j==columnaO || j==columnaO+largo-1)
					mvprintw(i,j,"%c",borde);
				else 
					mvprintw(i,j,"%c",relleno);
		}		
}

void init_curses()
{
    initscr();
    cbreak();
    start_color();
    init_pair(1,COLOR_RED,COLOR_WHITE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    init_pair(5,COLOR_CYAN, COLOR_WHITE);
    init_pair(6,COLOR_BLUE,COLOR_YELLOW);
    init_pair(7,COLOR_YELLOW,COLOR_MAGENTA);
    init_pair(8,COLOR_YELLOW,COLOR_BLACK);
    init_pair(9,COLOR_WHITE,COLOR_WHITE);
    init_pair(10,COLOR_WHITE,COLOR_MAGENTA);
    init_pair(11,COLOR_RED,COLOR_MAGENTA);
    init_pair(12,COLOR_RED,COLOR_WHITE);
    init_pair(13,COLOR_MAGENTA,COLOR_WHITE);
    init_pair(14,COLOR_WHITE,COLOR_BLACK);
    init_pair(15,COLOR_WHITE,COLOR_GREEN);
    init_pair(16,COLOR_RED,COLOR_MAGENTA);
    curs_set(0);
}
