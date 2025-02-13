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
	char cad[MAX],  clave[] = "XXXXXXXXX", *nomemp;
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
			
		}while (aux != 7 && aux != 10 && !isalpha(aux) && aux != ' ' && aux != '.');
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
	mvprintw(12,10,"%d ",lon);
	mvprintw(12,4,"%d",f);
	/*ind = 0;
	while(ind < CLAVE)
	{	
		clave[ind] = 'X';
		ind++;
	}*/
	mvprintw(15,4,"La clave es : %s ",clave);
	vec[0] = -1;
	for(ind = 0; ind < lon ; ind++)
	{
		if(cad[ind] == ' ')
		{
			vec[c] = ind;
			c++;
		}
	}
	mvprintw(17,4,"El vector contiene.");
	for(ind = 0; ind < f; ind++)
		printw("  %d ",vec[ind]);
	ind = - 1;
	r = 1;
	c = 0;
	while(c <= CLAVE && ind < f && c < lon && clave[c] != '\0')
	{
		ind++;
		if(ind < f - 1)
		{
			if(cad[vec[ind] + r] != ' ' && cad[ind] != 'a')
				clave[c] = cad[vec[ind] + r];
			else
			{
				cad[ind] = 'a';
				c--;
			}
		}
		
		if(ind == f - 1)
		{
			clave[c] = cad[vec[ind] + r];
			ind = -1;
			r++;
		}
		c++;
	}
	if(c < CLAVE)
	{
		c = c -1;
		while(c < CLAVE)
		{	
			c++;
			clave[c] = 'X';
		}
	}
	clave[CLAVE] = '\0';
	mvprintw(20,4,"La clave es : %s ",clave);
}
