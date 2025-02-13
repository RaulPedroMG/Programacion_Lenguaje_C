/*nombre:sumade numeros primos
autor:flavio 206-b
*/
#include <stdio.h>

void NumeroPrimo(int n);

int main()
{
	int n;
	printf("introduzca un número: ");
	scanf("%d",&n);
	NumeroPrimo(n);
	return 0;
}

void NumeroPrimo(int n)
{
	int i,suma=0;
	i=1;
	while(i<n)
	{
		if(i/2==0)
		{
			i++;
		}
		else
		{
			suma=suma+i;
			i++;
		}
	}
	printf("la suma de números primos es %d",suma);
}
