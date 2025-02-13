/*Quicksort interativo*/
#include<stdio.h>
#include<stdlib.h>
#define NE 100

void quicksort(int lista[], int );
void qs(int [], int,int);
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

void quicksort(int lista[], int n_elementos )
{
	qs(lista, 0, n_elementos-1);
}

/**Función no recursiva qs**/
void qs(int lista[], int inf, int sup)
{

	struct elemento_pila
	{
	int inf, sup;
	}pila[NE];

	int izq, der;
	int mitad, x, p;

/******Iniciar valores de las pilas*********/
	p=1, pila[p].inf=inf, pila[p].sup=sup;
	do
	{
	/*Tomar los datos inf, sup, de la parte superior de la pila*/
		inf=pila[p].inf, sup=pila[p].sup, p--;
		do{
		/*División del array en dos partes*/
			izq=inf; der=sup;
			mitad=lista[(izq+der)/2];
			do{
				while(lista[izq]<mitad && izq < sup)izq++;
				while(mitad<lista[der] && der > inf )der--;
				if(izq<=der)
				{
				x=lista[izq], lista[izq]=lista[der], lista[der]=x;
				izq++;der--;
			}
		}while(izq<=der);

		if(izq<sup)
			{/*Meter en la pila los valores: izq, sup*/
			p++, pila[p].inf=izq, pila[p].sup=sup;
			}
/*inf=inf;*/ sup=der;
		}while(inf<der);
	}while(p);
}
