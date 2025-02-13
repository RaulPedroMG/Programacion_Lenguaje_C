/*
 * unsis-li
 * nombre;factorialrec.c
 * descripción:este programa calcula el factorial
 * 				de un número de forma recursiva.
 * */

#include <stdio.h>

double Factorial(int numero);
int main()
{
	int num;
	
	printf("\n\nNúmero Factorial\n");
		do 
	{
		printf("\nProporciona un número positivo: ");
		scanf ("%d",&num);
	}while (num <= 0);
	printf("%d! = %.0lf",num, Factorial(num));
	return 0;
}

double Factorial(int numero)
/*calcula el factorial de un número*/
{
	if (numero > 1)
		return numero * Factorial(numero-1);//llamando a la función
	return 1;
}

