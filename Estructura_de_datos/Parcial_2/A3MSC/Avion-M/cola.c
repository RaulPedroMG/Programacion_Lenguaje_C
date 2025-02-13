#include <stdio.h>
#include "cola.h"

void crearcola(Cola *cola) 
{
	cola->frente=0; 
	cola->final=0;
} 

int colallena (Cola cola) 
{
	if (cola.final == MAX)
		return 1;
	else
		return 0;
} 

void insertar(Cola *cola,int entrada) 
{ 
	if (!colallena(*cola))
	{
		cola->listaCola[cola->final]=entrada; 
		cola->final++;  
	}
	else
	{ 
		printf("\nCola Llena");
	}
} 

int quitar(Cola *cola) 
 {  
	int temp; 
	if(!colavacia(cola))
	{
		temp=cola->listaCola[cola->frente]; 
		cola->frente++; 
	}
	return temp;
 } 
int colavacia (Cola *cola) 
{
	if(cola->final == cola->frente)
		return 1;
	else
	{
		return 0;
	}
} 

int frente(Cola cola) 
{ 
	//if (colavacia(&cola)){
		//return 1; 
	//}else{
	return cola.listaCola[cola.frente]; 
	//}
} 
