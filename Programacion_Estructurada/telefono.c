#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 13
#define RET 127
#define ENT 10

void LeeTeleEmp(char *cad, int max, int r, int c);

int main ()
{
	char cad[MAX];
	initscr();
	keypad(stdscr, TRUE);
	noecho();   
	clear();	
	mvprintw(2,2,"Introduce el número del telefono de la empresa:");
	LeeTeleEmp(cad,MAX,2,51);
	mvprintw(6,5,"El telefono de la empresa es %s",cad);
	getch();
	endwin();
	return 0;
} 

void LeeTeleEmp(char *cad, int max, int r, int c)
{
	int aux;
	int ind, band;
	noecho();
	keypad(stdscr, TRUE);
	ind = band =0;
	while (!band && ind < max -1)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isdigit(aux) );
		switch(aux)
		{
			case ENT:
								band = 1;
								cad[ind] = '\0';
								break;
			case RET:
								if (ind > 0)
								{
									ind--;
									move(r,c+ind);
									printw(" ");
									move(r,c+ind);
								}
								break;
			default :
								cad[ind] = aux;
								move(r,c+ind);
								printw("%c",aux);
								ind++;
		}
	}
	if (ind == max -1)
		cad[ind] = '\0';
}
