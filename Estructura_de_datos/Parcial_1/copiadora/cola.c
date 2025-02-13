#include<stdio.h>
#include<stdlib.h>
#include"cola.h"

void iniciar_cola(COLA *Q)
{
	Q->anterior=-1;
	Q->posterior=-1;
}

int encolar(int elemento, COLA *Q)
{
	if(Q->anterior+1>=MAX)
		return(SIN_ESPACIO);

	Q->cola[++Q->anterior]=elemento;
	return OK;
}

int desencolar(COLA * Q)
{
	if(Q->anterior==Q->posterior)/*Cola vacía*/
		printf("Cola vacía\n");

	return(Q->cola[++Q->posterior]);
}

int cola_vacia(COLA *Q)
{
	if(Q->anterior==Q->posterior)
		return(COLA_VACIA);

	return(OK);
}

int tamano_cola(COLA *Q)
{
	return (Q->anterior-Q->posterior);
}
