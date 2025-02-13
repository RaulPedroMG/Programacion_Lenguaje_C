/* Nombre: estruct.c
  Descripción: Contiene la definición de las funciones para la manipulación de la estructura Alumno.
  Autor: 
  Fecha: 
*/

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "estruct.h"
#include "validanc.h"
#include "formato.h"

void Leedatos(Alumno l[ML], int *t)
/*
 * Función que lee y valida datos del teclado proporcionados por el usuario al arreglo l.
 * Conforme se almacenan los datos en el arreglo se actualiza la variable a donde apunta t.
*/
{
	WINDOW *w2;
	int i,salir=0;
	float prom;
	char aux[MAT];
	w2 = newwin(15,40,3,15);
	while (!salir && *t<ML)
	{
		clear();
		mvprintw(18,57,"Total: %d",*t+1);
		attron(A_BOLD);
		Centrar("LECTURA DE DATOS",2);
		mvprintw(5,2,"MATRICULA:");
		LeeMatricula(aux,11,5,15);
		if (aux[0] == '\0')
			salir = 1;
		else
		{
			strcpy(l[*t].mat,aux);
			for (prom=0,i= 0; i<3;i++)
			{	
				mvprintw(7+i,2,"PARCIAL %d: ",i+1);
				l[*t].calif[i] = LeeFloatR(7+i,20,0.0,10.0);
				prom+=l[*t].calif[i];
			}
			mvprintw(7+i,2,"ORDINARIO: ",i+1);
			l[*t].calif[i] = LeeFloatR(7+i,20,0.0,10.0);
			l[*t].calif[4] = ((prom/3.)+l[*t].calif[3])/2.;
			(*t)++;
		}
	}
	delwin(w2);
}

void ImpDatos(Alumno l[ML],int t)
/*
 * Función que imprime los t elementos del arreglo l a la pantalla. Si el arreglo está vacío imprime
 * que no hay datos leídos.
*/
{
	int i,c;
	WINDOW *w2;
	w2 = newwin(15,40,3,15);
	clear();
	attron(A_BOLD);
	Centrar("DATOS DE ALUMNOS",2);
	//attroff(A_BOLD);
	if (!t)
		mvprintw(5,5,"NO HAY DATOS LEIDOS");
	else
	{
		//attron(A_BOLD);
		mvprintw(4,1,"NUM");
		mvprintw(4,7,"MATRICULA");
		mvprintw(4,19,"Parcial 1 ");
		mvprintw(4,31,"Parcial 2 ");
		mvprintw(4,43,"Parcial 3 ");
		mvprintw(4,55,"Ordinario ");
		mvprintw(4,69,"Final ");
		attroff(A_BOLD);
		for (i = 0; i < t; i++)
		{
			mvprintw(5+i,1,"%2d.  %11s",i+1,l[i].mat);
			for (c=0; c<CAL;c++)
				mvprintw(5+i,21+12*c,"%4.1f",l[i].calif[c]);
		}
	}
	getch();
	delwin(w2);
}

void InsertarOrd(Alumno l[ML],int *t)
{
	int j,i,g,band=0,ind,k;
	float  prom;
	char aux[MAT];
	initscr();
	keypad(stdscr, TRUE);
	noecho();
		clear();
		if(*t==0){
			mvprintw(5,5,"Ingrese la matrícula");
			LeeMatricula(aux,11,5,30);
			strcpy(l[0].mat,aux);
				sus(0,l);
				(*t)++;
		}else{
			if(*t>0){
				mvprintw(5,5,"Ingrese la matrícula");
				LeeMatricula(aux,11,5,30);
				g=strcmp(aux,l[(*t)-1].mat);
				if(g>0){
					strcpy(l[*t].mat,aux);
					sus(*t,l);
					
					(*t)++;
				}else{
					for(ind=0;ind<*t && band==0; ind++){
						i=strcmp(aux,l[ind].mat);
						if(i==0){
							Error("La matrícula ya existe!",ind+6);
							band=1;
						}else{
							if(i<0){
								for(j=*t;j>ind;j--){
									strcpy(l[j].mat,l[j-1].mat);
									for(k=0;k<5;k++){
										l[j].calif[k]=l[j-1].calif[k];
									}
								}
								strcpy(l[ind].mat,aux);
								sus(ind,l);
								(*t)++;
								band=1;
							}
						}
					}
				}
			
			}
		}
}
int menu()
{
	int opc;
	initscr();
	keypad(stdscr, TRUE);
	echo();
	clear();
	mvprintw(5,5,"OPCIONES A REALIZAR");
	mvprintw(6,5,"1.- Ingreso de alumnos");
	mvprintw(7,5,"2.- Insertar un alumno");
	mvprintw(8,5,"3.- Imprimir lista");
	mvprintw(9,5,"4.- buscar un alumno");
	mvprintw(10,5,"5.- eliminar un alumno");
	mvprintw(11,5,"6.- salir");
	mvprintw(12,5,"Eliga su opción ");
	mvscanw(12,25,"%d",&opc);
	return opc;
	endwind();
}
int Buscar (Alumno l[ML], int t, char mat[MAT])
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Devolverá el índice donde localizó la> 
 * matrícula mat, si no encontró la matrícula devolverá -1.*/

{
	int i, y=-1;
		for (i=0; i<t && y==-1; i++)
		{
			if (strcmp(mat, l[i].mat)==0)
			{
				y=i;
			}
		}
	return y;
}



void Eliminar(Alumno l[ML],int t, char mat[MAT])
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Eliminará el registro donde localice la 
 * matrícula mat, pedirá confirmación para eliminarla.
 * Enviará un mensaje si la matrícula no se encontró.*/

{
	int i, j, y;
	char conf;
	
		clear();
		y = Buscar(l, t, mat);
		if (y == -1)
		{
			printw (" NO SE ENCONTRÓ LA MATRICULA BUSCADA");
		}
		else
		{
			mvprintw(2,2,"¿Esta seguro de que desea eliminar la fila %d  [s/n]", y);
			mvscanw (4,30,"%c",&conf);
			if (conf == 's')
			{
				for(i= y; i < t-1; i++)
				{
					strcpy(l[i].mat,l[i+1].mat);
					for(j=0; j<CAL; j++)
					{
						l[i].calif[j]=l[i+1].calif[j];
					}
				}
			}
		}
}
void Imprimir(Alumno l[ML], int j)
{
	int i;
	clear();
	//attron(A_BOLD);
		mvprintw(4,1,"NUM");
		mvprintw(4,7,"MATRICULA");
		mvprintw(4,19,"Parcial 1 ");
		mvprintw(4,31,"Parcial 2 ");
		mvprintw(4,43,"Parcial 3 ");
		mvprintw(4,55,"Ordinario ");
		mvprintw(4,69,"Final ");
		attroff(A_BOLD);
	mvprintw(5,2,"%s",l[j].mat);
	for(i=0; i<CAL; i++)
	{
		mvprintw(5,21+12*i,"%4.1f",l[j].calif[i]);
	}
}

void sus(int x, Alumno l[ML])	
{
	int j, prom;
	for(prom=0,j=0;j<3;j++){
		mvprintw(7+j,2,"PARCIAL %d: ",j+1);
		l[x].calif[j]=LeeFloatR(7+j,20,0.0,10.0);
		prom=prom+l[x].calif[j];
	}
	prom=prom/3;
	mvprintw(7+j,2,"Dame ordinario ");
	l[x].calif[j]=LeeFloatR(7+j,20,0.0,10.0);
	l[x].calif[4]=(prom+l[x].calif[j])/2;	
}

