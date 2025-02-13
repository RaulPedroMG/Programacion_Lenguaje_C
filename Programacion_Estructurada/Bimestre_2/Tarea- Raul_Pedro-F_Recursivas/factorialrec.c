/* UNSIS- LI
	Nombre: factorial.c
	Descripcion: Este programa usa una función recursiva directa para calcular el factorial del numero (num)  
	fecha: 25 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
double Factorial(int numero);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main()
{
	int num;
	
	printf("\n\nNúmero Factorial\n");
	do 
	{
		printf("\nProporciona un número positivo: ");
		scanf ("%d",&num);
	}while (num <= 0); /* Regresará hasta que el usuario introduzca un numero positivo */
	printf("%d! = %.0lf",num, Factorial(num));
	return 0;
}


/*DEFINICION DE FUNCIONES RECURSIVAS*/
double Factorial(int numero)
/*Esta función recursiva se llama a sí misma para devolver el factorial de un numero*/
{
	if (numero > 1)  /*Paso base*/
		return numero * Factorial(numero-1);  /*Llamada de la misma funcion y mandando numero -1*/
	return 1;
}

