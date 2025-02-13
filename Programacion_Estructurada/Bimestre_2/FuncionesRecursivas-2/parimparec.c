/*
 * unsi-li
 * nombre:parimpares,c
 * descripcion: determinar si un número entero positivo
 * 				 es par o impar; con dos funciones que se 
 * 				llaman mutuamente:recursividad indirecta.
*/

#include <stdio.h>
int par(int n);
int impar(int n);

int main (void)
{
	int n;
	do 
	{
		printf ("\nEntero > O: ");
		scanf ("%d",&n);
	}while (n<= 0);
	
	if (par(n))
		printf ("El numero %d es par", n);
	else
		printf ("El numero %d es impar",n);
	return 0;
	
}
int par(int n)
{
	if (n == 0)
		return 1;	//Es par
	else
		return impar(n-1);//llamando a la función impar
}

int impar(int n)
{
	if (n == 0)	//Es impar
		return 0 ;
	else
		return par(n-1);//llamando a la función par
}
