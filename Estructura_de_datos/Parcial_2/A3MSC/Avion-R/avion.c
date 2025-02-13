#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void diavion(int i);
void movavion(void);
void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno);
void init_curses();

int main()
{
	initscr();
	init_curses();
	bkgd(COLOR_PAIR(7));
	//attron(COLOR_PAIR(7));
	movavion();
	getch();
	endwin();
	return 0;
}
void movavion(void)
{
	int i;
	for(i=40; i>-2; i--){ 
		clear();
		attron(COLOR_PAIR(2));
		marco(2,80,100,50,' ',' ');
		attron(COLOR_PAIR(7));
		mvprintw(10,100,"LIC INFORMATICA");
		attron(COLOR_PAIR(4));
		marco(-1,11,30,60,'#',' ');
		attron(COLOR_PAIR(9));
		marco(3,25,1,5,' ',' ');//Faltan mas rayas blancas
		attron(COLOR_PAIR(9));
		marco(12,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(21,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(30,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(39,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(48,25,1,5,' ',' ');
		attron(COLOR_PAIR(8));
		diavion(i);
		if(i == 40)
		{
			attron(COLOR_PAIR(7));
			mvprintw(40,100,"Estado: Avion en espera");
			refresh();
			system("sleep 3");
		}
		if(i < 40 && i > 38)
		{
			system("sleep 2");
		}
		if(i < 39 && i > 37)
		{
			system("sleep 1");
		}
		if(i < 38 && i > 36)
		{
			system("sleep 0.8");
		}
		if(i < 37 && i > 34)
		{
			system("sleep 0.6");
		}
		if(i < 35 && i > 31)
		{
			system("sleep 0.4");
		}
		if(i < 32 && i > 27)
		{
			system("sleep 0.3");
		}
		if(i < 28 && i > 24)
		{
			system("sleep 0.2");
		}
		if(i < 25 && i > 20)
		{
			system("sleep 0.15");
		}
		if(i < 21 && i > 15)
		{
			system("sleep 0.1");
		}
		if(i < 16 && i > 10)
		{
			system("sleep 0.05");
		}
		if(i < 11 && i > -3)
		{
			system("sleep 0.03");
		}
	}
}

void diavion(int i)
{
		mvprintw(-17+i,25,"/\\");
		mvprintw(-16+i,24,"/--\\");
		mvprintw(-15+i,23,"||--||");
		mvprintw(-14+i,23,"||--||");
		mvprintw(-13+i,21,"|||/--\\|||");
		mvprintw(-12+i,23,"|/--\\|");
		mvprintw(-11+i,23,"|/--\\|");
		mvprintw(-10+i,21,"//|/--\\|\\\\");
		mvprintw(-9+i,19,"//--|/--\\|--\\\\");
		mvprintw(-8+i,16,"//-----|/--\\|-----\\\\");	
		mvprintw(-7+i,14,"//-------|/--\\|-------\\\\");
		mvprintw(-6+i,12,"//||||||||||/--\\||||||||||\\\\");	
		mvprintw(-5+i,22,"||/--\\||");
		mvprintw(-4+i,22,"||/--\\||");
		mvprintw(-3+i,22,"||/--\\||");
		mvprintw(-2+i,21,"/||/--\\||\\");
		mvprintw(-1+i,19,"/--||/--\\||--\\");
		mvprintw(0+i,22,"||/--\\||");
		refresh();
}

void init_curses()
/* Función que inicializa el modo n_curses
 * En ella se crean algunas combinaciones de colores 
 * con la instrucción init_pair("Numero de combinacion",COLORES)
 * apaga el echo y activa las teclas especiales.
 */
{
    initscr();
    cbreak();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    init_pair(4,COLOR_WHITE,COLOR_BLACK);
    init_pair(5,COLOR_CYAN, COLOR_WHITE);
    init_pair(6,COLOR_BLUE,COLOR_YELLOW);
    init_pair(7,COLOR_YELLOW,COLOR_BLUE);
    init_pair(8,COLOR_YELLOW,COLOR_BLACK);
    init_pair(9,COLOR_WHITE,COLOR_WHITE);
    curs_set(0);
}

void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno)
{
	int i,j;

	for(i=filaO; i<filaO+ancho;i++)	
		for(j=columnaO; j<columnaO+largo;j++)	
			{
			if(i==filaO || i==filaO+ancho-1)		
			mvprintw(i,j,"%c",borde);
			else if(j==columnaO || j==columnaO+largo-1)
				mvprintw(i,j,"%c",borde);
			else 
				mvprintw(i,j,"%c",relleno);
			}		
}
