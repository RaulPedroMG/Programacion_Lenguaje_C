/* UNSIS- LI
	Nombre: parimparec.c
	Descripcion: Este programa usa una función recursiva indirecta para determinar si un número introducido por 
	* 			el usuario es par o impar   
	fecha: 25 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int par(int n);
int impar(int n);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main (void)
{
	int n;
	do 
	{
		printf ("\nEntero > O: ");
		scanf ("%d",&n);
	}while (n<= 0);
	/* Llamada a la función par */
	if (par(n)) /* Verificación si el valor retornado es de la función par,
					es decir, si el valor retornado es 1*/
			printf ("El numero %d es par", n);
	else
		printf ("El numero %d es impar",n);
	return 0;	
}

/*DEFINICION DE FUNCIONES RECURSIVAS*/
int par(int n)
/* Funcion recursiva que verifica si el número es 0 si no llama a la función impar pero mandandole n-1*/ 
{
	if (n == 0)
		return 1;	//Es par
	else
		return impar(n-1);
}

int impar(int n)
/* Funcion recursiva que verifica si el número es 0 si no llama a la función par pero mandandole n-1*/
{
	if (n == 0)	//Es impar
		return 0 ;
	else
		return par(n-1);
}
