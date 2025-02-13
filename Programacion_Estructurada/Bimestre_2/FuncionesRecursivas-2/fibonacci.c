/*
 * unsis-li
 * nombre:fibonacci.c
 * descripción::realiza la serie de fibonacci
 * 		segun el número de la serie que
 * 		que quiera el usuario.
 * 
 * */

#include <stdio.h>

int fibonacci(int n);

int main()
{
	int n,Fi;
	printf("\n Introdusca el número que quiere calcular: ");
	scanf("%d",&n);
	printf("\n Visualizacion del resultado: ");
	printf("%d",Fi=fibonacci(n));
	printf("\n\n");
	return 0;
}

int fibonacci(int n)
/*esta función da el resultado del termino que
 * introdujo el usuario*/
{
	if((n==0) || (n==1))
	return 1;
	else
	return fibonacci(n-1)+fibonacci(n-2);//llamando a la función
}
