#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define RET 127
#define ENT 10


/*Descripci¢n: Este procedimiento permite capturar el giro, validando
 *caracter por caracter, solo se permiten letras del alfabeto en ingles
 *y espacios en blanco.
*/

void LeerGiroEmp(char *cad);

int main ()
{
	char gir[50], *giroemp;
	initscr();
	keypad(stdscr, TRUE);
	noecho();   
	clear();
	mvprintw(4,4,"Dame el giro de la empresa : ");
	LeerGiroEmp(gir);
	giroemp = (char *) malloc(strlen(gir));
	strcpy(giroemp, gir);
	mvprintw(10,4,"La cadena copiada es %s ", giroemp);
	getch();
	endwin();
	return 0;
} 

void LeerGiroEmp(char *cad)
{	
	int aux;
	int ind, band, r = 6, c= 6;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		switch(aux)
		{
			case ENT://retorno de carro
								band = 1;
								cad[ind] = '\0';
								break;
			case RET://backspace <--  retroceso
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
	endwin();
}
