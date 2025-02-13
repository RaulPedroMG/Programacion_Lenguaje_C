#include <stdio.h>

int Sumaprim(int n);

int main ()
{
	int lim, sumap; 
	printf("\n\nIntroduzca el limite de los numeros primos : ");
	scanf("%d",&lim);
	sumap = Sumaprim(lim);
	printf("\n\nLa suma de los numeros primos es : %d ",sumap);
	return 0;
}
	
int Sumaprim(int n)
{
	int i, div, suma = 0, j;
	for(i = 0; i <= n; i++)
	{
		div = 0;
		for(j = 1; j <= i; j++)
		{
			if(i % j == 0)
				div++;
		}
		if(div == 2)
			suma = suma + i;
	}
	return suma;
}

		
