/*
 *unsis-li
 * nombre:hanoi.c
 * descripcion:este programa calculos movimientos 
 * 				que se deve de hacer para mover los 
 * 				discos en la torre de Hanoi de forma
 * 				recursiva.
 */

#include <stdio.h>
void Hanoi(int n, char *o, char *d, char *a);
int main()
{
	int nd;
	char o[]= "Origen";
	char d[]= "Destino";
	char a[]= "Auxiliar";
	
	printf("\nTORRES DE HANOI\n");
	do
	{
		printf("\nDame el total de discos a mover: ");
		scanf("%d",&nd);
		if (nd>0)
			Hanoi(nd,o,d,a);//llamando a la función 
	}while (nd>0);
	return 0;
}

void Hanoi(int n, char *o, char *d, char *a)
/*Da los movimientos que se hizo para resolver
 * la torre de hanoi*/
{
	if (n == 1)
		printf("\nMoviendo disco %d, de %s ---> %s",n,o,d);
	else
	{
		Hanoi(n-1,o,a,d);
		printf("\nMoviendo disco %d, de %s ---> %s",n,o,d);
		Hanoi(n-1,a,d,o);
	}
}
