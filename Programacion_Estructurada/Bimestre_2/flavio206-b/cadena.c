/*nombre:susutituye espacios en blanco por guion bajo
autor:flavio 206-b
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <ctype.h>
#define ENT 10
#define RET 127

void LeeCad(char *cad,int r,int c);
//void SustCad(char *cad);

int main()
{
	int r=5,c=15;
	char *cad;
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	clear();
	mvprintw(5,2,"escribe una frase");
	LeeCad(cad,r,c);
	//SustCad(cad,r,c);
	mvprintw(10,5,"La cadena leida es: %s",cad);
	getch();
	endwin();
	return 0;
}

void LeeCad(char *cad,int r,int c)
{
	int i,band,aux;
	noecho();
	keypad(stdscr, TRUE);
	i=band=0;
	while(!band)
	{
		do
		{
			move(r,c+i);
			aux=getch();
		}while(aux!=ENT && aux!=RET && !isalpha(aux));
		switch (aux)
		{
			case ENT:
				band=1;
				cad[i]='\0';
				break;
			case RET:
				if (i>0)
				{
					i--;
					move(r,c+i);
					printw(" ");
					move(r,c+i);
				}
				break;
			default:
				cad[i] = aux;
				move(r,c+i);
				printw("%c",aux);
				i++;
		}
	}
}

/*
void SustCad(char *cad);
{
	
}
* */
