/* UNSIS- LI
	Nombre: pot.c
	Descripcion: Este programa usa una función recursiva directa para calcular la oparacion de un número elevado a una potencia   
	fecha: 25 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
double Pot(int base,int exp);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main()
{
	int base,exp;
	
	printf("\n\nCálculo de la Potencia\n");
	do 
	{
		printf("\nProporciona un número positivo para la base: ");
		scanf ("%d",&base);
		
	}while (base <= 0); /* Repetirá hasta que el usuario intriduzca una base positiva*/
	do 
	{
		printf("\nProporciona un número positivo para el exponente: ");
		scanf ("%d",&exp);
		
	}while (exp <= 0); /* Repetirá hasta que el usuario intriduzca un exp positivo*/
	printf("%d^%d = %.0lf",base,exp, Pot(base,exp));
	return 0;
}

/*DEFINICION DE FUNCIONES RECURSIVAS*/
double Pot(int base,int exp)
/*Esta funci{on recursiva calcula el resultado de un número elevado a una potencia*/
{
	if (exp > 0) /*Paso base*/
		return base * Pot(base,exp-1);
	return 1;
}
