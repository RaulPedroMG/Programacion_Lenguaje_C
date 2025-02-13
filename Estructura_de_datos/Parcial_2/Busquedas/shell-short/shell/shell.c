#include <stdio.h>
#define N 20

void llena_arreglo(int n,int a[N]);//Llena el arreglo con enteros
void insercion_directa(int n, int arr[N]);//Ordenamiento por insercion directa
void imprime_arreglo(int num,int a[N]);//Imprime el arreglo
void ShellShort(int n, int a[N]);

int main()
{
	int a[N],num;
	printf("Cuantos numeros tiene tu arreglo: ");
	scanf("%d",&num);
	llena_arreglo(num,a);
	printf("ARREGLO DESORDENADO\n");
	imprime_arreglo(num,a);
	printf("ORDENACION DE SHELL SHORT\n");
	ShellShort(num,a);
	printf("\nARREGLO ORDENADO\n");
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
	{ 
		for(i=j;i > 0 && (a[i] < a[i-1]); i--) //Empezamos a recorrer desde el primer elemento y
		{                                     //colocamos al numero en su posicion correcta
			aux=a[i];
			a[i]=a[i-1];  //Intercambio
			a[i-1]=aux;
		}
	}
}

void ShellShort(int n,int a[N])
{
	int k,i,b,j,l,f,cont,t,aux[N];
	k=n/2;
	b=0;
	t=0;
	//printf("k=%d \n",k);
	do
	{
		for(i=0;i<n && k>0 && b==0 && t<k;i++)
		{
			f=0;
			printf("k-ordenaciones de %d \n",k);
			if (k==1)
			{
				printf("numeros enviados=%d \n",n);
				imprime_arreglo(n,a);
				insercion_directa(n,a);
				printf("numeros ordenados\n");
				imprime_arreglo(n,a);
				b=1;
			}
			else
			{
				for(j=i;j<n;j=j+k)
				{
					aux[f]=a[j];
					f++;
				}
				printf("numeros enviados=%d \n",f);
				imprime_arreglo(f,aux);
				insercion_directa(f,aux);
				printf("numeros ordenados\n");
				imprime_arreglo(f,aux);
				cont=f;
				f=0;
				for(l=i;l<n;l=l+k)
				{
					a[l]=aux[f];
					f++;
				}
				imprime_arreglo(n,a);
			}
			t++;
		}
		k=k/2;
		t=0;
	}while(k>0);
}

void imprime_arreglo(int n,int a[N])
{
	int i;
	for (i=0;i<n;i++)
	{
	    printf("%d ",a[i]);
	}
	printf("\n");
	
}
