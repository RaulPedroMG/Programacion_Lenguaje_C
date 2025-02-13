# include <ncurses.h>
#include <string.h>
#include "validanc.h"
#include "formato.h"

int main ()
{
	char fecha[11],rfc[12];
	char cont[MATRI],contra[] = "inf06mat1";
	int band=0;
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	do
	{
		mvprintw(2,2,"Dame la contraseña:                                        ");
		LeeContra(cont,11,2,25);
		if (!strcmp(cont,contra))
		{
			clear();
			mvprintw(4,4,"Fecha: ");
			LeeFecha(fecha,4,15);
			mvprintw(6,4,"RFC:");
			LeeRFC(rfc,6,15);
			Centrar("DATOS CAPTURADOS",10);
			mvprintw(12,4,"Fecha ==> %s",fecha);
			mvprintw(14,4,"RFC ==> %s",rfc);
		}
		else
		{
			Error("Contraseña inválida!",4);
			band++;
		}
	}while (band<3);
	endwin();
	return 0;
} 
