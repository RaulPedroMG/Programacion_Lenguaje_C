#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

void crearcola(Cola *cola) 
{
	cola->frente=0; 
	cola->final=-1;
} 
int colallena (Cola cola) 
{
	return (cola.final==MAX-1);
} 

void insertar(Cola *cola,int entrada) 
{ 
	if (colallena(*cola)){ 
		printf("Cola Llena"); 
	}else{
		cola->final++; 
		cola->listaCola[cola->final]=entrada; 
	}
} 

int quitar(Cola *cola) 
{  
	int temp; 
	if(colavacia(cola)){ 
		printf("No hay elementos para sacar"); 
		return 1; 
	}else{	 
		temp=cola->listaCola[cola->frente]; 
		cola->frente++; 
		return temp;
	} 
} 
int colavacia (Cola *cola) 
{
	return (cola->final < cola->frente);
} 

int frente(Cola cola) 
{ 
	if (colavacia(&cola)){  
		printf("Error de ejecucion: Cola Vacia"); 
		return 1; 
	}else{
		return cola.listaCola[cola.frente]; 
	}
} 
