/* UNSIS- LI
	Nombre: Factorial.c
	Descripcion: Calcula el factorial de num de forma recursiva
	Autor: Raul (MEGA)
	fecha: 23 de mayo del 2011
*/
#include <stdlib.h>
#include <stdio.h>

int factorial (int numero);

int main() 
{	
	int num, fac;
	
	printf("\n              ****FACTORIAL**** \n");
	printf("\nIntroduce un número para calcular su factorial:\n");
	scanf("%d",&num);
	fac = factorial (num);
	printf("\n El factorial del numero %d es: %d",num,fac);
	return 0;
}

int factorial (int numero)
{
  if (numero > 2)
    return numero * factorial(numero-1);
   return numero;
}
