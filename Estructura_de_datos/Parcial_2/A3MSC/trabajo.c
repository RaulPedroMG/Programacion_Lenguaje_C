#include <stdio.h>
#include "Archivos.h"

void LlenaCola(Cola *pis1, Cola *pis2, Cola *pis3)
{
	int i,j;
	for (i=1; i<=15;i++)
	{
		system ("sleep 1");
		j=rand() % 2+1;
		switch (j)
		{
			case 1:
				InsertarAlea(pis1, &j, &i);
				break;
			case 2:
				InsertarAlea(pis2, &j, &i);
				break;
			case 3:
				InsertarAlea(pis3, &j, &i);
				break;
			}
	}
}

void InsertarAlea(Cola *Pista, int *j, int *i)
{
	if (!colallena (Pista))
		insertar(Pista,i);
	else
		(*i)--;
}


void BuscarVuelo (int clave, Vuelo *turno, int np)
{
	int ind, i;
	for(i=0; i<=20; i++)
	{
		if(*clave == turno[i].clave_v)
			ind=i;
	}
	ImprimirVuelo(ind,turno,np);
}


void ImprimirVuelo(int ind, Vuelo turno, int np)
{
	printf("Clave", turno[ind].clave_v);
	printf("Destino", turno[ind].destino);
	printf("Capitan de vuelo", turno[ind].capitan);
	printf("Estado");
}
