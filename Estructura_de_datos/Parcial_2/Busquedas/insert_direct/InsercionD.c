#include <stdio.h>
#define N 20

void llena_arreglo(int n,int a[N]);//Llena el arreglo con enteros
void insercion_directa(int n, int arr[N]);//Ordenamiento por insercion directa
void imprime_arreglo(int num,int a[N]);//Imprime el arreglo

int main()
{
	int a[N],num;
	printf("Cuantos numeros tiene tu arreglo: ");
	scanf("%d",&num);
	llena_arreglo(num,a);
	printf("ARREGLO DESORDENADO\n");
	imprime_arreglo(num,a);
	insercion_directa(num,a);
	printf("ARREGLO ORDENADO\n");
	imprime_arreglo(num,a);
	return 0;
	}
	
	
void llena_arreglo(int n,int a[N])
{
	int i;
	for(i=0;i<n;i++)
	    {
			printf("Escribe el %d° Numero: ",i+1);
			scanf("%d",&a[i]);
			}
	}
	

void insercion_directa(int n, int a[N])
{
int i,j,aux;
i=1;
for(j=1;j<n;j++) 
   for(i=j;i > 0 && (a[i] < a[i-1]); i--) //Empezamos a recorrer desde el primer elemento y
    {                                     //colocamos al numero en su posicion correcta
      aux=a[i];
      a[i]=a[i-1];  //Intercambio
      a[i-1]=aux;
    }
}

void imprime_arreglo(int n,int a[N])
{
	int i;
	for (i=0;i<n;i++)
	    printf("%d ",a[i]);
	printf("\n");
	
	}
