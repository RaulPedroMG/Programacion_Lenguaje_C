#include <stdio.h>
#define N 5

void SeparaDig(int n, int dig[N]);
int BuscarMayor(int dig[N]);

int main ()
{
	int num, dig[N], mayor; 

	printf("Introduzca un numero de 5 digitos: ");
	scanf("%d",&num);
	if (num > 9999 && num < 100000)
	{
		SeparaDig(num,dig);
		mayor = BuscarMayor(dig);
		printf("\n\nEl digito mayor es: %d ", mayor);
	}
	else 
		printf("\n\nEl numero no es de 5 digitos ");
	return 0;
}
	
void SeparaDig(int n, int dig[N])
{
	int i;
	for(i = 0; i < N; i++)
	{
		if(n != 0)
		{
			dig[i] = n % 10;
			n = n / 10;
		}
	}
}
		
int BuscarMayor(int dig[N])
{
	int i, mayor = 0;
	for(i = 0; i < N; i++)
	{
		if(dig [i] > mayor)
		{
			mayor = dig[i];
		}
	}
	return mayor;
}
