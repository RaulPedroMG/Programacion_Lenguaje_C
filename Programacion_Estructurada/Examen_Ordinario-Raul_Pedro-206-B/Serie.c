#include <stdio.h>

void Serie(int n);

int main ()
{
	int n; 
	do
	{
		printf("\n\nIntroduzca 0 para salir\n\n");
		printf("Introduzca un numero para el limite de la serie: ");
		scanf("%d",&n);
		printf("\n\n");
		if (n != 0)
			Serie(n);
	}while (n != 0);
	return 0;
}
	
void Serie(int n)
{
	int i = 3, j = 0;
	while(i < n)
	{
		printf(" %d ,", i);
		j = j + 2;
		i = i + j;
	}
}
		
