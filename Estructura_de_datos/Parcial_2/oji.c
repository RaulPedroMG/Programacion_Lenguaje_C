#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>

void paleta_colores(void);
void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno);

int main()
{
	initscr();
	start_color();
	paleta_colores( );
	bkgd(COLOR_PAIR(2));

	marco(0,0,80,45,' ',':');
	attron(COLOR_PAIR(9));
	attron(COLOR_PAIR(3));
	mvprintw(5, 20,"CREDITOS");
	attron(COLOR_PAIR(9));
	
	mvprintw(6, 15,"EQUIPO 4. INTEGRADO POR:        ");
	mvprintw(7, 15,"* EDGARDO VENTURA PACHECO       ");
	mvprintw(8, 15,"* DEYSI JANET CRUZ RUIZ         ");
	mvprintw(9, 15,"* CRISTIAN URIEL LUNA HERNANDEZ ");
	mvprintw(10, 15,"* SELMA MARITZA AVALOS MATEOS  ");
	attron(COLOR_PAIR(9));
	getch();
	marco(0,0,80,45,'#',':');



	/*attron(COLOR_PAIR(9));
	attron(COLOR_PAIR(9));*/

	getch();
	endwin();
	return 0;
}

void paleta_colores(void)
{
	if (has_colors())
		{
		init_pair(1,COLOR_RED,COLOR_GREEN);
		init_pair(2,COLOR_RED,COLOR_MAGENTA);
		init_pair(3,COLOR_RED,COLOR_YELLOW);
		init_pair(4,COLOR_BLACK,COLOR_RED);
		init_pair(5,COLOR_BLACK,COLOR_BLUE);	
		init_pair(6,COLOR_RED,COLOR_CYAN);
		init_pair(7,COLOR_WHITE,COLOR_BLACK);
		init_pair(8,COLOR_BLUE,COLOR_WHITE);
		init_pair(10,COLOR_WHITE,COLOR_RED);
		init_pair(9,COLOR_BLUE,COLOR_CYAN);
		init_pair(11,COLOR_RED,COLOR_WHITE);
		
		}
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
