/* UNSIS- LI
	Nombre: hanoi.c
	Descripcion: Este programa usa una función recursiva directa para resolver el problema de las torres de Hanoi  
	fecha: 25 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void Hanoi(int n, char *o, char *d, char *a);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main()
{
	int nd;
	char o[]= "Origen"; /* Declaración de la variable que representa la torre origen*/
	char d[]= "Destino"; /* Declaración de la variable que representa la torre destino*/
	char a[]= "Auxiliar"; /* Declaración de la variable que representa la torre auxiliar*/
	
	printf("\nTORRES DE HANOI\n");
	do
	{
		printf("\nDame el total de discos a mover: ");
		scanf("%d",&nd);
		if (nd>0)
			Hanoi(nd,o,d,a); /* Llamada a la función Hanoi */
	}while (nd>0); /* Repetirá hasta que el usuario intriduzca un número positivo*/
	return 0;
}

/*DEFINICION DE FUNCIONES RECURSIVAS*/
void Hanoi(int n, char *o, char *d, char *a)
/*Esta función recursiva se llama a sí misma para resolver el problema de la torre de Hanoi*/
{
	if (n == 1) /*Paso base*/
		printf("\nMoviendo disco %d, de %s ---> %s",n,o,d);
	else
	{
		Hanoi(n-1,o,a,d); /*Llamada de la misma funcion y mandando n-1, la variable de la torre origen,
							la variable de la torre auxiliar y  la variable de la torre destino*/
		printf("\nMoviendo disco %d, de %s ---> %s",n,o,d);
		Hanoi(n-1,a,d,o);/*Llamada de la misma funcion y mandando n-1, la variable de la torre auxiliar,
							la variable de la torre destino y  la variable de la torre origen*/
	}
}
