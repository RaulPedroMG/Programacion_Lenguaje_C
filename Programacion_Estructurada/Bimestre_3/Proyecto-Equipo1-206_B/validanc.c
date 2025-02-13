/*
Nombre: validanc.c
* Descripcion: Contiene las definiciones de las funciones que validan las lecturas
Autor: Equipo 1

*/
#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include "validanc.h"
#include "formato.h"

void LeerContra(char *cad, int r, int c)
{
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != '@' && aux != '_' && aux != '-' && aux != '#' && aux != '/' && aux != '.' && aux != ',' && aux != '-' );
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
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
						printw("*");
						ind++;
						break;
		}
	}
}

void LeerClave(char *cad, int r, int c)
{
	int aux, i;
	int ind, band;
	noecho();
	ind = band = 0;
	mvprintw(r+6, 30, "Presione enter para salir");
//	mvprintw(r + 2, c, "Introduzca la clave de la empresa : ");
	//c = 48;
	while (!band && ind < MIN - 1)
	{
		do
		{
			move(r , c + ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ' && aux != '.' && aux != ','&& aux != '-' && aux != '/');
		switch(aux)
		{
			case ENT://retorno de carro
								if(ind == 0)
								{
									band = 1;
									cad[ind] = '\0';
								}
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
			default :			aux = toupper(aux);
								cad[ind] = aux;
								move(r,c+ind);
								printw("%c",aux);
								ind++;
								break;
		}
	}
	if (ind == MIN - 1)
			cad[ind] = '\0';
}

void LeerNomEmp(char *cad, int r, int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ' && aux != '.' && aux != ',' && aux != '-' && aux != '/' && aux != '(' && aux != ')');
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
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
						aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
}

void GenerarClave(char cad[MAX], char clave[MIN - 1], int lon)
{
	int f = 1, c = 1, r, ind, *vec;
	for(ind = 0; ind < lon ; ind++)
	{
		if(cad[ind] == ' ')
			f++;
	}
	vec = (int *)malloc(f * sizeof(int));
	vec[0] = -1;
	for(ind = 0; ind < lon ; ind++)
	{
		if(cad[ind] == ' ')
		{
			vec[c] = ind;
			c++;
		}
	}
	ind = - 1;
	r = 1;
	c = 0;
	while(c < MIN -1 && ind < f)
	{
		ind++;
		if(ind < f - 1)
		{
			if(cad[vec[ind] + r] != ' ')
				clave[c] = cad[vec[ind] + r];
			else
				c--;
		}
		
		if(ind == f - 1)
		{
			clave[c] = cad[vec[ind] + r];
			ind = -1;
			r++;
		}	
		c++;
	}
	if(lon < MIN - 2)
	{	
		for(ind = lon; ind < MIN  - 1; ind ++)
			clave[ind] = 'X';
	}
	clave[MIN - 1] = '\0';
}

void LeerGiroEmp(char *cad, int r, int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
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
						aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
}

void LeerDomEmp(char *cad, int r, int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalnum(aux) && aux != ' ' && aux!='.' && aux!='#' && aux!=',' && aux!='/' );
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
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
			default : 	aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
	
}

void LeerEstEmp(char *cad, int r, int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
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
						aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
}

void LeerCpEmp(char *cad, int r, int c)
{
	int aux, i;
	int ind, band;
	noecho();
	ind = band = 0;
	while (!band && ind < CP - 1)
	{
		do
		{
			move(r , c + ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isdigit(aux));
		if (ind == 0)
		{
			mvprintw(14,25,"                           ");
			mvprintw(24,100,"                                     ");
		}
		switch(aux)
		{
			case ENT://retorno de carro
								if(ind == 0)
								{
									band = 1;
									cad[ind] = '\0';
								}
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
			case 48: 			if(ind != 0)
								{
									cad[ind] = aux;
									move(r,c+ind);
									printw("%c",aux);
									ind++;
								}
								break;
			default :			aux = toupper(aux);
								cad[ind] = aux;
								move(r,c+ind);
								printw("%c",aux);
								ind++;
								break;
		}
	}
	if (ind == CP)
		cad[ind] = '\0';
}


void LeerTelEmp(char *cad, int r, int c)
{
	int aux;
	int ind, band;
	ind = band =0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isdigit(aux) && aux != '-' && aux != ' ' && aux != ',' && aux != 'y');
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
		switch(aux)
		{
			case ENT:			if (ind == 0 || ind == 10 || ind == 13 || ind > 17)
								{
									band = 1;
									cad[ind] = '\0';
								}
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
}

void LeerFaxEmp(char *cad, int r, int c)
{
	int aux;
	int ind, band;
	ind = band =0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isdigit(aux) && aux != '-' && aux != ' ' && aux != ',' && aux != 'y');
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
		switch(aux)
		{
			case ENT:			if (ind == 0 || ind == 10 || ind == 13 || ind > 17)
								{
									band = 1;
									cad[ind] = '\0';
								}
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
}

void LeerContEmp(char *cad, int r, int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
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
						aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
}

void LeerCorreoEmp(char *cad, int r, int c)
{
	int aux;
	int ind, band,u=0,p=0,j=0,l=0; 
	ind = band =0;
	u=p=j=l=0;
	while (!band)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			mvprintw(16,6,"                                                                                ");
		}while (aux != RET && aux != ENT  && !isalnum(aux) && aux!='_' &&  aux!='-' && aux!='@' && aux!='.');
		if (ind == 0)
		{
			mvprintw(14,25,"                          ");
			mvprintw(24,100,"                                     ");
		}
		switch(aux)
		{
			case ENT://retorno de carro
						if(cad[ind-1]!='.'){
							band = 1;
							cad[ind] = '\0';
						}else{
							mvprintw(16,6,"Eror no debe terminar con (.)");
						}
						break;
			case RET://backspace <--  retroceso
								if (ind > 0){
									ind--;
									if(cad[ind]=='-'){
										j--;
										move(r,c+ind);
										printw(" ");
										move(r,c+ind);
									}else{
										if(cad[ind]=='_'){
											p--;
											move(r,c+ind);
											printw(" ");
											move(r,c+ind);
										}else{
											if(cad[ind]=='.'){
												l--;
												move(r,c+ind);
												printw(" ");
												move(r,c+ind);
											}else{
												if(cad[ind]=='@'){
													u--;
													move(r,c+ind);
													printw(" ");
													move(r,c+ind);
												}else{
													move(r,c+ind);
													printw(" ");
													move(r,c+ind);
												}
											}								
										}
									}
								}
								break;
			case '_':
					if(ind>0 && cad[ind-1]!='@' && p!=63 && u!=1){
						cad[ind]=aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						p=p+1;
					 }else{
					 	mvprintw(16,6,"Error no debe tener un (_) al inicio o (@_)");
					 }
					break;
			case '-':
					if(ind>0 && cad[ind-1]!='@' && j!=63 && u!=1){
						cad[ind]=aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						j=j+1;
				 	}else{
				 		mvprintw(16,6,"Error no debe tener un (-) al inicio o (@-)");
				 	}
					break;
			case '.':
					if(ind>0 && cad[ind-1]!='.'   && cad[ind-1]!='@' && l!=40){
						cad[ind]=aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						l=l+1;
					}else{
						mvprintw(16,6,"Error no puede haber un (.) al inicio o (..) o (.@) o (@.)");
					}
					break;
			case '@':
					if(ind>0 && cad[ind-1]!='.' && cad[ind-1]!='@' && u!=1){
						cad[ind]=aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						u=u+1;
					}else{
					mvprintw(16,6,"Error (@) al inicio o (.@)");
					}
					break;
			default:	
					cad[ind] = aux;
					move(r,c+ind);
					printw("%c",aux);
					ind++;
		}
	}
}

void LeerVisitaEmp(char *cad, int opc)
{	
	switch (opc)
	{
		case 1: cad[0] = 'S';
				cad[1] = 'i';
				cad[2] = '\0';
			break;
		case 2: cad[0] = 'N';
				cad[1] = 'o';
				cad[2] = '\0';
			break;
	}
}

void LeerEstanciaEmp(char *cad, int opc)
{	
	switch (opc)
	{
		case 1: cad[0] = 'S';
				cad[1] = 'i';
				cad[2] = '\0';
			break;
		case 2: cad[0] = 'N';
				cad[1] = 'o';
				cad[2] = '\0';
			break;
	}
}

void LeerServicioEmp(char *cad, int opc)
{	
	switch (opc)
	{
		case 1: cad[0] = 'S';
				cad[1] = 'i';
				cad[2] = '\0';
			break;
		case 2: cad[0] = 'N';
				cad[1] = 'o';
				cad[2] = '\0';
			break;
	}
}

void Leercad(char *cad)
{
	int aux, i;
	int ind, band, r = 23, c = 100;
	noecho();
	ind = band = 0;
	while (!band && ind <  1)
	{
		do
		{
			move(r , c + ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux));
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
			default :			aux = toupper(aux);
								cad[ind] = aux;
								move(r,c+ind);
								printw("%c",aux);
								ind++;
								break;
		}
	}
	if (ind == 1)
			cad[ind] = '\0';
}

void LeerNomAlumn(char *cad,int r,int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
			mvprintw(14,25,"                             ");
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
						aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
}

void LeerApellidoAlumn(char *cad, int r, int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
			mvprintw(14,25,"                            ");
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
						aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
}

void LeerClav(char *cad, int r, int c)
{
	int aux, i;
	int ind, band;
	noecho();
	ind = band = 0;
	mvprintw(r+6, 30, "Presione enter para salir");
	while (!band && ind < CAL - 1)
	{
		do
		{
			move(r , c + ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isdigit(aux));
		switch(aux)
		{
			case ENT://retorno de carro
								if(ind == 0)
								{
									band = 1;
									cad[ind] = '\0';
								}
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
								
			default :			aux = toupper(aux);
								cad[ind] = aux;
								move(r,c+ind);
								printw("%c",aux);
								ind++;
								break;
		}
	}
	if (ind == CAL - 1)
		cad[ind] = '\0';
}

void LeerNomProfe(char *cad, int r, int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
			mvprintw(14,25,"                                ");
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
						aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
}

void LeerApellidoProfe(char *cad, int r, int c)
{	
	int aux;
	int ind, band;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
			mvprintw(24,25,"                                 ");
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
						aux = toupper(aux);
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						break;
		}
	}
}


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

void LeeFecha(char *cad, int r, int c)
/* Equipo 4*/
 {
	int d, m, a, fec = 0;
	int aux;
	char num1[3], num2[3], num3[5];
	int ind=0;
	
	//do
	//{
		while (ind < 10)
		{
				do
				{
					move(r,c+ind);
					aux = getch();
				
				}
				while (aux != RET && !isdigit(aux));
			
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
				if (aux == ENT)
				{
					if (ind == 1)
					{
						cad[ind]='\0';
						cad[ind]=cad[0];
						cad[0]= '0';  
						mvprintw (r,c,"%s",cad);
						ind=2;
						if (ind == 2 || ind == 5)
						{
							cad[ind] = '/';
							move(r,c+ind);
							printw("/");
							ind++;
						}
					}
					
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
	 

		for(ind = 0; ind >=0 && ind <=10; ind = ind + 1)
		{
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
	
		}

		d = atoi(num1);
		m = atoi(num2);
		a = atoi(num3);
		
		mvprintw (r+4,2,"El dia es:%d",d);
		mvprintw (r+6,2,"El mes es:%d",m);
		mvprintw (r+8,2,"El año es:%d",a);
		
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
		
		if (fec == 0)
		{
			mvprintw (r+12,2,"La fecha es invalida, vuelva a introducirla");
			
		}
	
	//}while (fec != 1);
	
}
void LeeMatricula (char *cad,int r, int c)
{
int ind=0,band=0,anio;
int aux;
initscr();
keypad(stdscr, TRUE);
noecho();
while (!band && ind < MATRI-1)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && !isdigit(aux));
		switch(aux)
		{
			case ENT:
				if (ind == 0)
				{
					band = 1;
					cad[ind] = '\0';
				}
					
			case RET://backspace <--  retroceso
				if (ind > 0)
				{
					ind--;
					move(r,c+ind);
					printw(" ");
					move(r,c+ind);
				}
								break;
			default :{
                                   switch(ind)
                                   {
                                              case 0: 
                                                   if(aux==50)
                                                   {
                                                           cad[ind] = aux;
															move(r,c+ind);
															printw("%c",aux);
															ind++;
                                                   }
                                                   break;
                                              
                                              case 1:
                                                   if(aux==48)
                                                   {
                                                             cad[ind] = aux;
																move(r,c+ind);
																printw("%c",aux);
															ind++;
                                                   }
                                                   break;
                                              
                                              case 2:
                                                  if(aux==49 || aux==48)
                                                  {
                                                            cad[ind] = aux;
															move(r,c+ind);
															printw("%c",aux);
															ind++; 
															if(aux==48)
															{
                                                                      anio=1;
                                                            }
                                                  }
                                                  break;
                                             
                                              case 3:
                                                  if(anio==1)
                                                  {
                                                     if(aux==49 || aux==48)
                                                     {
                                                        cad[ind] = aux;
								                        move(r,c+ind);
   								                        printw("%c",aux);
								                        ind++;
                                                     }
                                                  }
                                                  else
                                                  {
                                                      cad[ind] = aux;
								                      move(r,c+ind);
   								                      printw("%c",aux);
								                      ind++;
                                                  }
                                                  break;
                                              
                                              case 4:
                                                   if(aux==48)
                                                   {
                                                     cad[ind] = aux;
								                     move(r,c+ind);
   								                     printw("%c",aux);
								                     ind++;
                                                   }
                                                   break;
                                              
                                              case 5:
                                                    if(aux>-49 &&aux<55)
                                                    {
                                                       cad[ind] = aux;
								                       move(r,c+ind);
   								                       printw("%c",aux);
								                       ind++;
                                                    }
                                                    break;
											 
											 case 10:
													band = 1;
													cad[ind] = '\0';
													break;
                                              
											 default:
                                                      cad[ind] = aux;
								                      move(r,c+ind);
   								                      printw("%c",aux);
								                      ind++;
                                   } 
							   }           
		}
	}
	getch();
}

