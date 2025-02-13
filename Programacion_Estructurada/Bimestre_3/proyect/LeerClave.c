#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

/*Descripci¢n: Este procedimiento permite capturar un nombre, validando
 *caracter por caracter, solo se permiten letras del alfabeto en ingls
 *y espacios en blanco.
*/

void LeerClave(char *cad);

int main ()
{
	char clave[MAX];
	initscr();
	keypad(stdscr, TRUE);
	noecho();   
	clear();
	mvprintw(2,4,"Presione enter para salir ");
	mvprintw(4,4,"Introduzca la clave de la empresa : ");
	LeerClave(clave);
	if (clave[0] != '\0' || clave[0] != '\0')
	{	
		mvprintw(6,4,"La clave leida es : % s", clave);
	}
	mvprintw(8,4," Saliendo....  ");
	getch();
	endwin();
	return 0;
} 

void LeerClave(char *cad)
{	
	int aux, i;
	int ind, band, r = 4, c= 40;
	ind = band = 0;
	while (!band && ind < MAX - 1)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != 127 && aux != 10 && !isalpha(aux) && !isdigit(aux) && aux != ' ');
		switch(aux)
		{
			case 10://retorno de carro
								band = 1;
								cad[ind] = '\0';
								break;
			case 127://backspace <--  retroceso
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
								break;
		}
	}
	if (ind == MAX - 1)
			cad[ind] = '\0';
	if (cad[0] != '\0' || cad[0] != '\0')
	{
		for (i = 0; cad[i] != '\0'; i++)
			cad[i] = toupper(cad[i]);
	}
	endwin();
}
