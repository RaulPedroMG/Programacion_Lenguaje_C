/*
Nombre: validanc.c
Autor:
Fecha: 31 de mayo de 2010
*/
#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include "validanc.h"


void LeeNombre(char *cad,int max,int r, int c)
/*Descripci¢n: Este procedimiento permite capturar un nombre, validando
 *caracter por caracter, solo se permiten letras del alfabeto en ingls
 *y espacios en blanco.
*/
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
		}
	}
	if (ind == max -1)
	{
		//move(r+1,c);
		//Error("Tamaño maximo de la cadena alcanzado",11);
		mvprintw(r+1,c,"Tamaño maximo de la cadena alcanzado");
		cad[ind] = '\0';
	}

}
void LeeEntero(char *cad,int max,int r, int c)
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
		}while (aux != RET && aux != ENT && !isdigit(aux) && aux != '-');
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
			case '-':
								if (!ind)//ind == 0
								{
									cad[ind] = aux;
									move(r,c+ind);
									printw("%c",aux);
									ind++;
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


int LeeInt(int r, int c)
{
	char cad[12];
	int valor;
	LeeEntero(cad,12,r,c);
	valor = atoi(cad);
	return valor;
}

void LeeFecha(char *cad, int r, int c)
 {
	int d, m, a, fec = 0, band=0;
	int aux;
	char num1[3], num2[3], num3[5];
	int ind=0;
	
	do
	{
		ind=0;
		while (ind < 10 && band == 0)
		{
				do
				{
					move(r,c+ind);
					aux = getch();
			
					if (ind >= 0 && ind <=2)
					{	
						if (ind == 0)
						{	
							num1[0] = cad[ind];
						}
						if (ind == 1)
						{	
							num1[1] = cad[ind];
						}
						if (ind == 2)
						{
						num1[2] = '\0';
						}
						d = atoi(num1);
						if (d > 0 && d < 10)
						{
							mvprintw(r,c,"%2d",d);
						}
					}
					
					if (ind >= 3 && ind <=5)
					{
						if (ind == 3)
						{
							num2[0]=cad[ind];
						}
						if (ind == 4)
						{
							num2[1]=cad[ind];
						}
						if (ind == 5)
						{
							num2[2] = '\0';
						}
					}
					m = atoi(num2);
					if (m > 0 && m < 10)
					{
						mvprintw(r,c+2,"%01d",m);
					}
			
					if (ind >= 6 && ind <=9)
					{
						if (ind == 6)
						{
							num3[0]=cad[ind];
						}
						if (ind == 7)
						{
							num3[1]=cad[ind];
						}
						if (ind == 8)
						{
							num3[2]=cad[ind];
						}
						if (ind == 9)
						{
							num3[3]=cad[ind];
						}
						if (ind == 10)
						{
							num3[4] = '\0';
						}
					}
					a = atoi(num3);
				
				}
				while (aux != RET && aux != ENT && !isdigit(aux));
			
			
				if (aux == RET)
				{
						if (ind > 0)
						{
							ind--;
							move(r,c+ind);
							printw(" ");
						}
					
				}
				else
				{
					cad[ind] = aux;
					move(r,c+ind);
					printw("%c",aux);
					ind++;
				}
				
				if (ind == 2 || ind == 5)
				{
					cad[ind] = '/';
					move(r,c+ind);
					printw("/");
					ind++;
				}
		}
		if (ind == 10)
		cad[ind] = '\0';
		
		if(a >= 1900)
		{
			if(m >= 1 && m <= 12)
			{
				if(m == 2)
				{
					if(a % 400 == 0 && a % 4 == 0)
					{
						if(d >= 1 && d <= 29)
						{
							fec=1;
						}
					}	
					else	
					{
						if(d >= 1 && d <= 28)
						{
							fec=1;
						}
					}
				}
				else
				{
					if(m ==4  || m == 6 || m == 9 || m == 11)
					{
						if(d >= 1 && d <= 30)
						{
							fec=1;
						}
					}
					else
					{	
						if(m ==1  || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
						{
							if(d >= 1 && d <= 31)
							{
								fec=1;
							}
						}	
					}		
				}
			}
		}	
		if (fec == 1)
		{
			mvprintw (r+4,2,"                                           ");
		} 
		if (fec == 0)
		{
			mvprintw (r+4,2,"La fecha es invalida, vuelva a introducirla");
			mvprintw (8,28,"           ");
			move(r,c);
		}
	
	}while (fec != 1);
	
}
