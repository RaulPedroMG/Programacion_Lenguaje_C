#include <stdio.h>
#include <stdlib.h>

void imprimir(int a[], int n);
void intercambio(int *x, int *y);
void ordenar(int a[],int n);

int main()
{
	int a[6],i;
	for(i=0;i<6;i++){
		printf(" Nnum Arreglo[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Lista desordenanda\n ");
	imprimir(a,6);
	printf("\n");
	ordenar(a,6);
	printf("\n\n");
	printf("Lista ordenada \n");
	imprimir(a,6);
	return 0;
}

void imprimir(int a[],int n)
{
	int i;
	for(i=0;i<n;i++){
		printf(" | %d | ",a[i]);
	}
	printf("\n");
}


void ordenar(int a[], int n)
{
	int i,j;
	for(i=1;i<n;i++){
		printf("\nPasada %d\n",i);
		imprimir(a,n);
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				//aux=a[j];
				//a[j]=a[j+1];
				//a[j+1]=aux;
				intercambio(&a[j], &a[j+1]);
				imprimir(a,n);
			}
		}
	}
}

void intercambio(int * x, int * y)
{
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}
