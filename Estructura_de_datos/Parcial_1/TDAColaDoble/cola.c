/*
 * cola.c
 * Autores: Heriberto López Ramírez
 * 			Flavio Juárez Martínez
 * 			Flavio Gonzalez Reyes
*/

#include <stdio.h>
#include "cola.h"

void CrearCola(cola *c)
{
	c->frente=0;
	c->final=-1;
}

int ColaVacia(cola *c)
{
	int ban;
	if(c->frente==0)
		ban=1;
	else
		ban=0;
	return ban;
}

int ColaLlena(cola *c)
{
	int band;
	if (c->final==Max)
		band=1;
	else
		band=0;
	return band;
}

void InsertarFinal(cola *c,int x)
{
	if(c->final<Max)
	{
		c->final=c->final+1;
		c->arreglo[c->final]=x;
		if(c->final==1)
			c->frente=1;
	}
	else
		printf("\nDesbordamiento\n");	
}

void InsertarFrente(cola *c,int x)
{
	if (c->frente<Max)
	{	
		c->frente=c->frente+1;
		c->arreglo[c->frente]=x;
		if(c->frente==1)
			c->final=1;
	}
	else
		printf("\ncola llena\n");
}

void EliminarFrente(cola *c,int *x)
{
	int v;
	v=ColaVacia(c);
	if(v!=1)
	{
		*x=c->arreglo[c->frente];
		if(c->frente==c->final)
		{
			c->frente=0;
			c->final=0;
		}
		else
			c->frente=c->frente+1;
	}
	else
		printf("\nsubdesbordamiento");
	
}

void EliminarFinal(cola *c,int *x)
{
	int v;
	if((v=ColaVacia(c))!=1)
	{
		*x=c->arreglo[c->final];
		if(c->frente==c->final)
		{
			c->frente=0;
			c->final=0;
		}
		else
			c->final=c->final-1;
	}
}
