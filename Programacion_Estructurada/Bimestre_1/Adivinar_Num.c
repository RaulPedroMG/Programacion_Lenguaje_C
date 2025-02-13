#include <stdlib.h>
#include <stdio.h>

int main() 
{	
	int num, numero;
	numero = rand () % 100;
	printf("\nADIVINA UN NÚMERO\n");
	do
	{
		printf("\nIntroduce un numero:\n");
		scanf("%d",&num);
		if (num > numero)
		{
			printf("\nEstas por arriba\n");
		}
		else
		{
			printf("\nEstas por abajo\n");
		}
	}while (num != numero);
	printf("\nADIVINASTE\n");
	return 0;
}

