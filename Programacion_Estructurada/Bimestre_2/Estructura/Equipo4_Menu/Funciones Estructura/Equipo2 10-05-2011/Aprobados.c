/*Equipo 2
 * Integrantes:
 * Teresa del Carmen 
 * Cristian Uriel
 * Selma
 * */
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "estruct.h"
#include "validanc.h"
#include "formato.h"

void BuscarAprobados(Alumno l[ML], int t, int cont[ML], int *j)
/*Este procedimiento realizara un filtro de los alumnos aprovados con un promedio mayor o igual a 6.*/
{
	int i;
	if(t==0)
	{
		mvprintw(5,5,"No hay elementos en el registro.");
		j=0;
	}
	else
	{
		for(i=0,*j=0;i<t;i++)
		{
			if(l[i].calif[CAL-1] >= 6.0)
			{
				cont[*j]=i;
				(*j)++;
				
			}
		}
	}
}



void BuscarReprobados(Alumno l[ML], int t, int cont[ML], int *j)
/*Este procedimiento realizará un filtro de los alumnos con calificación final menor que 6.*/
{
	int i;
	if(t==0)
	{
		mvprintw(5,5,"No hay elementos en el registro.");
		j=0;
	}
	else
	{
		for(i=0,*j=0;i<t;i++)
		{
			if(l[i].calif[CAL-1] < 6)
			{
				
				cont[*j]=i;
				(*j)++;
			}
		}
	}
}
