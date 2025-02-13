
#include <stdio.h>
#define MAX 8

void insercion_directa(int n, int arr[MAX]);
void ShellSort(int n, int a[MAX]);
void BusquedaBinaria(int A[MAX], int limIzq, int limDer, int valor);
int main()
{
	int A[MAX], i;
	int limIzq=0, limDer=MAX-1;
	int valor;
	printf("\nLLENADO DEL VECTOR");
	for(i=0; i<MAX; i++)
	{
		printf("\nVec[%d] = ", i+1);
		scanf("%d", &A[i]);
	}
	printf("\n--Vector Desordenado--\n");
	for(i=0; i<MAX; i++)
	{
		printf("[%d] ", A[i]);
	}
	ShellSort(MAX, A);
	printf("\nNúmero a buscar: ");
	scanf("%d", &valor);
	BusquedaBinaria(A, limIzq, limDer, valor);
	return 0;
}
void ShellSort(int n, int a[MAX])
{
	int incrmnt,i,j,l=0,k,x=0;
	int aux[n];
	incrmnt=n/2;
	while(incrmnt>0)
	{
		for(i=0;i<incrmnt;i++)
		{
			for(j=i;j<n;j+=incrmnt)
			{
				aux[l]=a[j];
				l++;
			}
			insercion_directa(l,aux);
			for(k=i;k<n;k+=incrmnt)
			{
				a[k]=aux[x];
				x++;
			}
			x=0;
			l=0;
		}
		incrmnt/=2;
	} 
	printf("\n--Vector Ordenado--\n");
	for(i=0; i<MAX; i++)
	{
		printf("[%d] ", a[i]);
	}
}

void insercion_directa(int n, int a[MAX])
{
int i,j,aux;
i=1;
for(j=1;j<n;j++) 
   for(i=j;i > 0 && (a[i] < a[i-1]); i--)
    {
      aux=a[i];
      a[i]=a[i-1];
      a[i-1]=aux;
    }
}
void BusquedaBinaria(int A[MAX], int limIzq, int limDer, int valor)
{
	int mitad;
	if(limIzq==limDer)
	{
		if(A[limIzq]==valor)
			printf("\nEl numero %d fue encontrado en la posición [%d]", valor,limIzq+1);
		else
			printf("\nValor no existente en el arreglo");
	}
	else
	{
		mitad = (limIzq + limDer)/2;
		if(A[mitad]==valor)
			printf("\nEl numero %d fue encontrado en la posición [%d]", valor, mitad+1);
		else
		{
			if(valor > A[mitad])
				BusquedaBinaria(A, mitad+1, limDer, valor);
			else
				BusquedaBinaria(A, limIzq, mitad-1, valor);
		}
	}
}






