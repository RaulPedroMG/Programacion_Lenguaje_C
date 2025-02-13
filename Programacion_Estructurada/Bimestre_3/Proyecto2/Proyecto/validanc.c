/*
Nombre: validanc.c
Descripción:contiene las definiciones de las funciones utilizadas en el programa,
* toda las funciones valida los datos a capturar. 
Autor:Equipo 1.
*/
#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include "validanc.h"
#include "formato.h"

void LeerClave(char *cad, int r, int c)
{
	int aux, i;
	int ind, band;
	noecho();
	ind = band = 0;
	mvprintw(r+6, 30, "Presione enter para salir");
	while (!band && ind < MIN - 1)
	{
		do
		{
			move(r , c + ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && !isdigit(aux) && aux != ' ');
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
	if (ind == MIN - 1)
			cad[ind] = '\0';
}

void LeerNomEmp(char *cad)
{	
	int aux;
	int ind, band, r = 10, c= 45;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
			mvprintw(14,25,"                          ");
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

void LeerGiroEmp(char *cad)
{	
	int aux;
	int ind, band, r = 10, c = 45;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
			mvprintw(14,25,"                          ");
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

void LeerDomEmp(char *cad)
{	
	int aux;
	int ind, band, r = 10, c= 48;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalnum(aux) && aux != ' ' && aux!='.' && aux!='#' && aux!=',' && aux!='/' );
		if (ind == 0)
			mvprintw(14,25,"                          ");
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

void LeerEstEmp(char *cad)
{	
	int aux;
	int ind, band, r = 10, c= 45;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
			mvprintw(14,25,"                          ");
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

int LeerCpEmp()
{
	int cp, r=10, c=52;
	mvscanw(r,c,"%d",&cp);
	return cp;
}

void LeerTelEmp(char *cad)
{
	int aux;
	int ind, band, r = 10, c= 47;
	ind = band =0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isdigit(aux) && aux != '-' && aux != ' ' && aux != ',' && aux != 'y');
		if (ind == 0)
			mvprintw(14,25,"                          ");
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

void LeerFaxEmp(char *cad)
{
	int aux;
	int ind, band, r = 10, c= 42;
	ind = band =0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isdigit(aux) && aux != '-' && aux != ' ' && aux != ',' && aux != 'y');
		if (ind == 0)
			mvprintw(14,25,"                          ");
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

void LeerContEmp(char *cad)
{	
	int aux;
	int ind, band, r = 10, c= 47;
	ind = band = 0;
	while (!band )
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			
		}while (aux != RET && aux != ENT && !isalpha(aux) && aux != ' ');
		if (ind == 0)
			mvprintw(14,25,"                          ");
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

void LeerCorreoEmp(char *cad)
{
	int aux;
	int ind, band,u=0,p=0,j=0,l=0, r = 10, c= 45; 
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
			mvprintw(14,25,"                          ");
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
		case 1: cad[0] = 's';
				cad[1] = 'i';
				cad[2] = '\0';
			break;
		case 2: cad[0] = 'n';
				cad[1] = 'o';
				cad[2] = '\0';
			break;
	}
}

void LeerEstanciaEmp(char *cad, int opc)
{	
	switch (opc)
	{
		case 1: cad[0] = 's';
				cad[1] = 'i';
				cad[2] = '\0';
			break;
		case 2: cad[0] = 'n';
				cad[1] = 'o';
				cad[2] = '\0';
			break;
	}
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
/*
void LeeBeca(char *cad)
{	
	switch (cad)
	{
		case 1: cad[0] = 's';
				cad[1] = 'i';
				cad[2] = '\0';
			break;
		case 2: cad[0] = 'n';
				cad[1] = 'o';
				cad[2] = '\0';
			break;
	}
}

int LeeCalif(int num)
{
	int opc;
	clear()
	opc=0;
	mvprintw(3,5"Elija la calificación para la empresa: ");
	mvprintw(5,5"1: mal");
	mvprintw(6,5"2: regular");
	mvprintw(7,5"3: bien");
	mvprintw(8,5"4: muy bien");
	mvprintw(9,5"5: excelente");
	scanw("%d",opc);
	if(opc>=1 || opc<=5)
	return opc;
}

void LeerMal(char *ca)
{
	switch(ca)
	{
		ca[0] = 'M';
		ca[1] = 'A';
		ca[2] = 'L';
		ca[3] = '\0';
	}

}

void LeerRegu(char *ca)
{
	switch(ca)
	{
		ca[0] = 'R';
		ca[1] = 'E';
		ca[2] = 'G';
		ca[3] = 'U';
		ca[4] = 'L';
		ca[5] = 'A';
		ca[6] = 'R';
		ca[7] = '\0';
	}
}

void LeerBien(char *ca)
{
	switch(ca)
	{
		ca[0] = 'B';
		ca[1] = 'I';
		ca[2] = 'E';
		ca[3] = 'N';
		ca[4] = '\0';
	}
}

void LeerMuy(char *ca)
{
	switch(ca)
	{
		ca[0] = 'M';
		ca[1] = 'U';
		ca[2] = 'Y';
		ca[3] = ' ';
		ca[4] = 'B';
		ca[5] = 'I';
		ca[6] = 'E';
		ca[7] = 'N';
		ca[8] = '\0';
	}
}

void LeerExce(char *ca)
{
	switch(ca)
	{
		ca[0] = 'E';
		ca[1] = 'X';
		ca[2] = 'C';
		ca[3] = 'E';
		ca[4] = 'L';
		ca[5] = 'E';
		ca[6] = 'N';
		ca[7] = 'T';
		ca[8] = 'E';
		ca[9] = '\0';
	}
}
*/
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

void LeeRealP(char *cad, int max, int r, int c)
 /*Esta funcion tiene como como finalidad la lectura de un numero real
	*positivo, tiene como argumentos una cadena donde se almacena el dato
	*leido, el maximo de esa cadena, la columna y el renglon donde empezara
	*a imprimir los datos leidos*/
 {
	int aux;
	int ind, band,punto;
	noecho();
	ind = band = punto = 0;
	while (!band && ind < max -1)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}
		while (aux != RET && aux != 10 && !isdigit(aux) && aux != '.');
		switch(aux)
		{
			case '.':
					if (!punto)
					{
						cad[ind] = aux;
						move(r,c+ind);
						printw("%c",aux);
						ind++;
						punto = 1;
					}
					break;
			case 10:
					band = 1;
					cad[ind] = '\0';
					break;
			case RET:
					if(ind > 0)
					{
						ind--;
						if (cad[ind] == '.')
							punto = 0;
						move(r,c+ind);
						printw(" ");
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

void Leecorreo(char *cad,int max,int r, int c) 
// PROCEDIMIENTO Leecorreo(caracter: *cad, entero: max)
/*Descripci¢n: Este procedimiento permite capturar un correo electronico, validando caracter por caracter.
 * EQUIPO 3
*/
{
	int aux;
	int ind, band,u=0,p=0,j=0,l=0; 
	noecho();
	keypad(stdscr, TRUE);
	ind = band =0;
	u=p=j=l=0;
	while (!band && ind < max -1)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
			mvprintw(16,6,"                                                                                ");
		}while (aux != RET && aux != ENT  && !isalnum(aux) && aux!='_' &&  aux!='-' && aux!='@' && aux!='.');
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
	if (ind == max -1)
	{
		//move(r+1,c);
		//Error("Tamaño maximo de la cadena alcanzado",11);
		mvprintw(r+1,c,"Tamaño maximo de la cadena alcanzado");
		cad[ind] = '\0';
	}
}

void LeeContra(char *cad,int max,int r, int c)
/*Equipo 5 */
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
		}while (aux != RET && aux != ENT && !isalpha(aux) && !isdigit(aux) && aux != '.' 
        && aux != '@' && aux != '_' && aux != '-' && aux != '#' && aux != '/');
		switch(aux)
		{
			case ENT: band = 1;
                      cad[ind] = '\0';
			          break;
			case RET: if (ind > 0)
			          {
			            ind--;
			            move(r,c+ind);
			            printw(" ");
			            move(r,c+ind);
	                  }
			          break;
			default : cad[ind] = aux;
		              move(r,c+ind);
			          printw("*");
			          ind++;
		}
	}
	if (ind == max -1)
	{
		//move(r+1,c);
		//Error("TamaÃ±o maximo de la cadena alcanzado",11);
		mvprintw(r+1,c,"TamaÃ±o maximo de la cadena alcanzado");
		cad[ind] = '\0';
	}
}

void LeeRFC(char *cad,int r, int c)
/*DEF: Este procedimiento capturara un RFC, validando caracter
 * por caracter, los primeros cuatro digitos son letras y los
 *otros seis son numeros.
 * EQUIPO 2
*/
{
	char carac;
	int i=0;
	while (i < RFC)
	{
		move(r,c+i);
		carac = getch();
		carac = toupper(carac);
		if(carac == RET)
		{
			if(i > 0)
				{
					i--;
					move(r,c+i);
					printw(" ");
				}
		}
		if(carac==ENT)
			{
				cad[i] = '\0';
			}
		
		else
		{
			switch(i)
			{
				case 0:
				case 2:
				case 3:
					if (isalpha(carac))
					{
						cad[i] = carac;
						move(r,c+i);
						printw("%c",carac);
						i++;
					}	
					break;
				case 4:
						mvprintw(2,39,"-");		
						i++;
					
					break;
				case 1:
						if (carac == 'A' || carac == 'E' || carac == 'I' || carac == 'O' || carac == 'U')
							{
								cad[i] = carac;
								move(r,c+i);
								printw("%c",carac);
								i++;
							}
					break;
				case 5:
				case 6:	
					if (isdigit(carac))
						{
							cad[i] = carac;
							move(r,c+i);
							printw("%c",carac);
							i++;
						}
						break;
				case 7:
						if (isdigit(carac))
						{
							
							if((carac == '0') || (carac =='1'))
							{ 
								cad[i] = carac;
								move(r,c+i);
								printw("%c",carac);
								i++;
							}
						}
						break;
				case 8:
						if (isdigit(carac))
						{
							if(cad[i-1]=='1')
							{
								if(((carac=='0') || (carac=='1')) || (carac=='2'))
								{
									cad[i] = carac;
									move(r,c+i);
									printw("%c",carac);
									i++;
								}
							}
							else
							{
								cad[i] = carac;
								move(r,c+i);
								printw("%c",carac);
								i++;
							}
						}
						
						break;
				default :
						if (isdigit(carac))
						{
							if((cad[i-2]=='0') && (cad[i-1]=='2'))
							{
								if((carac>='0') ||(carac<='2'))
								{
									cad[i] = carac;
									move(r,c+i);
									printw("%c",carac);
									i++;
								}
								if(cad[i]=='2')
								{
									if((((cad[5]=='0')||(cad[5]=='2')||(cad[5]=='4')||(cad[5]=='6')||(cad[5]=='8')) && ((cad[6]=='0')||(cad[6]=='4')||(cad[6]=='8')))||(((cad[5]=='1')||(cad[5]=='3')||(cad[5]=='5')||(cad[5]=='7')||(cad[5]=='9')) && ((cad[6]=='2')||(cad[6]=='6'))))
									{
										
											if(carac>='0' && carac<='9')
											{
											cad[i] = carac;
											move(r,c+i);
											printw("%c",carac);
											i++;	
											}
									}	
									else
									{
										if(carac>='0' && carac<='8')
										{
										cad[i] = carac;
										move(r,c+i);
										printw("%c",carac);
										i++;
										}
									}
									
									
									
									
								}
								else
								{
									if(carac>='0' && carac<='9')
									{
										cad[i] = carac;
										move(r,c+i);
										printw("%c",carac);
										i++;
									}	
								}
							}
							else
							{
								if(((cad[i-2]=='0') && (cad[i-1]=='4')) || ((cad[i-2]=='0') && (cad[i-1]=='6')) || ((cad[i-2]=='0') && (cad[i-1]=='9')) || ((cad[i-2]=='1') && (cad[i-1]=='1')))
								{	
									if((carac>='0') || (carac<='3'))
									{
									cad[i] = carac;
									move(r,c+i);
									printw("%c",carac);
									i++;
									}
									if(cad[i-1]=='3')
									{
										if(carac=='0')
										{
											cad[i] = carac;
											move(r,c+i);
											printw("%c",carac);
											i++;
										}
									}
								}
								else
								{
									if((carac>='0') || (carac<='3'))
									{
									cad[i] = carac;
									move(r,c+i);
									printw("%c",carac);
									i++;
									}
									if(cad[i-1]=='3')
									{
										if(carac=='0' || carac=='1')
										{
											cad[i] = carac;
											move(r,c+i);
											printw("%c",carac);
											i++;
										}
									}
								}
									
							}
						}
			}
		}
	}
	if (i == RFC)
		cad[i] = '\0';
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
}


void LeeMatricula (char *cad,int r, int c)
{
	int ind=0,band=0,anio;
	int aux;
	noecho();
	while (!band && ind < MAT)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}while (aux != ENT  && aux != RET  && !isdigit(aux));
		switch(aux)
		{
			case ENT:band = 1;
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
			{
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
						if(aux>-49 && aux<55)
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
}


/*
void LeeMatricula (char *cad, int r, int c)
{
	int ind=0,band=0,anio;
	int aux;
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	while (!band && ind < MAT-1)
	{
		do{
				move(r,c+ind);
				aux = getch();
		}while (aux != RET && !isdigit(aux) && aux != ENT);
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
			{
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
							if(aux==49)
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
						if(aux>-49 && aux<55)
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
		if(ind==0)
		{
			band = 1;
			cad[ind] = '\0';
		}
	}
	getch();
	endwin();
}
*/

int LeeInt(int r, int c)
{
	char cad[12];
	int valor;
	LeeEntero(cad,12,r,c);
	valor = atoi(cad);
	return valor;
}

float LeeFloat(int r, int c)
{
	char cad[12];
	float valor;
	LeeRealP(cad,12,r,c);
	valor = atof(cad);
	return valor;
}

float LeeFloatR(int r, int c,float min, float max)
{
	char cad[5];
	float valor;
	do
	{
		LeeRealP(cad,5,r,c);
		valor = atof(cad);
		if (valor < min || valor > max)
		{
			Error("Fuera de rango, intente nuevamente!",r+2);
			mvprintw(r,c,"     ");
		}
	}while (valor < min || valor > max);
	return valor;
}
