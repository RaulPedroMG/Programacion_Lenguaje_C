/*
 * unsis-li
 * nombre:pot.c
 * descripccion:este programa calcula la exponenciacion
 * 				de un número de manera recursiva.
 * */
#include <stdio.h>

double Pot(int base,int exp);
int main()
{
	int base,exp;
	
	printf("\n\nCálculo de la Potencia\n");
	do 
	{
		printf("\nProporciona un número positivo para la base: ");
		scanf ("%d",&base);
		
	}while (base <= 0);
	do 
	{
		printf("\nProporciona un número positivo para el exponente: ");
		scanf ("%d",&exp);
		
	}while (exp <= 0);
	printf("%d^%d = %.0lf",base,exp, Pot(base,exp));
	return 0;
}

double Pot(int base,int exp)
/*calcula la exponciación de cualquier numero de forma recursiva*/
{
	if (exp > 0)
		return base * Pot(base,exp-1);//llamando a la función
	return 1;
}
