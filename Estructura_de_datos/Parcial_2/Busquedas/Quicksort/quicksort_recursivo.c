#include<stdio.h>
#include<stdlib.h>

void quicksort(int [], int);
void qs(int [], int, int);

int lista[]={10,3,7,5,12,1,27,3,8,13};
int n_elementos=sizeof(lista)/sizeof(int);

main()
{
	int i;

	printf("Lista desordenada:\n");
	for(i=0; i<n_elementos; i++)
		printf("%6d", lista[i]);
	printf("\n");

	quicksort(lista, n_elementos);
	
	printf("Lista ordenada:\n");
	for(i=0; i<n_elementos; i++)
		printf("%6d", lista[i]);
	printf("\n");
}

/*////////////////////////Quicksort///////////////////////////////////*/
void quicksort(int lista[], int n_elementos)
{
	qs(lista, 0, n_elementos-1);
}


/**Función Recursiva**/
void qs(int lista[], int inf, int sup)
{
	int izq, der;
	int i,pivote,x;
	izq=inf; der=sup;
	pivote=lista[(izq+der)/2];

	do{
		printf("%d<%d y %d<%d\n",lista[izq],pivote,izq,sup);
		while(lista[izq]<pivote && izq<sup){
		printf("%d<%d y %d<%d\n",lista[izq],pivote,izq,sup);
		izq++;}
		while(pivote < lista[der] && der > inf){		printf("%d<%d y %d<%d\n",lista[izq],pivote,izq,sup);
		der--;}
		if(izq<=der)
		{
		x=lista[izq], lista[izq]=lista[der], lista[der]=x;
		izq++;der--;
		}
	}while(izq<=der);

	if(inf<der)qs(lista,inf,der);
	if(izq<sup)qs(lista, izq, sup);
}

