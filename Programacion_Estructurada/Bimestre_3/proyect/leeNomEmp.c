#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define CLAVE 9

/*Descripci¢n: Este procedimiento permite capturar un nombre, validando
 *caracter por caracter, solo se permiten letras del alfabeto en ingls
 *y espacios en blanco.
*/

void LeerNomEmp(char *cad);
void GenerarClave(char cad[MAX], char clave[CLAVE], int lon);

int main ()
{
	char cad[MAX],  clave[CLAVE], *nomemp;
	int lon;
	initscr();
	keypad(stdscr, TRUE);
	noecho();   
	clear();
	mvprintw(4,4,"Dame el nombre de la empresa : ");
	LeerNomEmp(cad);
	nomemp = (char *) malloc(strlen(cad));
	strcpy(nomemp, cad);
	lon =  strlen(cad);
	GenerarClave(cad, clave, lon);
	mvprintw(10,4,"La cadena copiada es %s ", nomemp);
	getch();
	endwin();
	return 0;
} 

void LeerNomEmp(char *cad)
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
			
		}while (aux != 7 && aux != 10 && !isalpha(aux) && aux != ' ');
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
								aux = toupper(aux);
								cad[ind] = aux;
								move(r,c+ind);
								printw("%c",aux);
								ind++;
								break;
		}
	}
}

void GenerarClave(char cad[MAX], char clave[CLAVE], int lon)
{
	int f = 1, c = 1, r, ind, *vec;
	for(ind = 0; ind < lon ; ind++)
	{
		if(cad[ind] == ' ')
			f++;
	}
	vec = (int *)malloc(f * sizeof(int));
	mvprintw(12,4,"%d",f);
	vec[0] = -1;
	for(ind = 0; ind < lon ; ind++)
	{
		if(cad[ind] == ' ')
		{
			vec[c] = ind;
			c++;
		}
	}
	mvprintw(14,4,"El vector contiene.");
	for(ind = 0; ind < f; ind++)
		printw("  %d ",vec[ind]);
	ind = - 1;
	r = 1;
	for(c= 0; c < CLAVE && ind < f; c++)
	{
		ind++;
		if(ind < f - 1)
		{
			if(cad[vec[ind] + r] != ' ')
				clave[c] = cad[vec[ind] + r];
			else
				clave[c] = 'X';
		}
		if(ind == f - 1)
		{
			clave[c] = cad[vec[ind] + r];
			ind = -1;
			r++;
		}	
	}
	if(lon < CLAVE - 1)
	{	
		for(ind = lon; ind < CLAVE; ind ++)
			clave[ind] = 'X';
	}
	clave[CLAVE] = '\0';
	mvprintw(18,4,"La clave es : %s ",clave);
}
