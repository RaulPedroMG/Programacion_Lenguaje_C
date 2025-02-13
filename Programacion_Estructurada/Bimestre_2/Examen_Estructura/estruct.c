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

void LeeDatos(Alumno l[ML], int *t)
/*
 * Función que lee y valida datos del teclado proporcionados por el usuario al arreglo l.
 * Conforme se almacenan los datos en el arreglo se actualiza la variable a donde apunta t.
*/
{
	WINDOW *w2;
	int i,salir=0;
	float prom;
	char aux[MATRI];
	w2 = newwin(15,40,3,15);
	while (!salir && *t<ML)
	{
		clear();
		mvprintw(18,57,"Total: %d",*t+1);
		attron(A_BOLD);
		Centrar("LECTURA DE DATOS",2);
		mvprintw(5,2,"MATRICULA:");
		LeeMatricula(aux,5,15);
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

