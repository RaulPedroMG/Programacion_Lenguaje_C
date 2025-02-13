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
	do
	{
		mvprintw(2,2,"        MENÚ    ");
		mvprintw(2,4,"1:Llenar lista");
		mvprintw(4,4,"2:Imprimir lista");
		mvprintw(6,4,"3:Buscar dato lista");
		mvprintw(8,4,"4:Eliminar dato");
		mvprintw(10,4,"5:Salir");
		mvscanw(2,2,"%d",&opc);
		if (opc > 0 && opc < 6)
		{
			switch (opc)
			{
				case 1: 
					//mvprintw(4,4,"Total: %d",total);
					//getch();
					LeeDatos(lista,&total);
				break;
				
				case 2:	
					//mvprintw(5,4,"Total: %d",total);
					//getch();
					ImpDatos(lista,total);
				break;
				
				case 3:
					LeeMatricula(aux,5,15);
					i = Buscar(lista, &total, aux);
				break;
				
				case 4:
					LeeMatricula(aux,5,15);
					Eliminar(lista,&total, aux);
					ImpDatos(lista,total);
				break;
			}
		}
	}while (opc != 5);
	
	
	endwin();
	return 0;
} 
