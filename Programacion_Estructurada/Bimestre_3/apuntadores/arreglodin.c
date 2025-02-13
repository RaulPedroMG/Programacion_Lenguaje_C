/*UNIVERSIDAD DE LA SIERRA SUR - LICENCIATURA EN INFORMATICA
 * Nombre: arreglodin.c
 * Descripción: Este programa reserva espacio suficiente para n enteros, imprime
 * 				sus valores y después libera la memoria.
 * 	Autor: SKRV
 * 	Fecha: 30 de mayo de 2011
	
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ap,ind,n;
	
  	printf("\nUSO DE MEMORIA DINÁMICA");
	do
	{
		printf("\n\nCuantos elementos tendrá el arreglo?: ");
		scanf("%d",&n);
	}while (n<1 || n > 50);
	ap = (int *)malloc (n * sizeof(int));
	if (!ap)
		printf("\nNo hay memoria disponible!");
	else
	{
		for (ind=0;ind < n; ind++)
			*(ap+ind) = ind+1;
		for (ind=0;ind < n; ind++)
			printf("\n%p \t%X \t%4d",ap+ind,(unsigned int)ap+ind,*ap+ind);
			//printf("\n%p \t%4d",ap+ind,*ap+ind);
		free(ap);
	}
	return 0;
}
