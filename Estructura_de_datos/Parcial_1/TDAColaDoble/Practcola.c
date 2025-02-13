/*
 * Implementacion del TDA cola
 * Autores: Heriberto López Ramirez
 * 			Flavio Juárez Martínez
 * 			Flavio Gonzalez Reyes
*/

#include <stdio.h>
#include "cola.h"

int main()
{
    int x,i;
    cola c;
    CrearCola(&c);
    for(i=1;i<=Max;i++)
		InsertarFinal(&c,i);
	i=ColaVacia(&c);
	printf("\ncolavacia=%d\n",i);
	i=ColaLlena(&c);
	printf("\ncolallena=%d\n",i);
	printf("\ncola\n");
    for(i=1;(ColaVacia(&c))!=1;i++)
    {
		EliminarFrente(&c,&x);
		printf("%d ",x);
    }
    EliminarFrente(&c,&x);
    InsertarFinal(&c,2);
	InsertarFinal(&c,3);
	EliminarFrente(&c,&x);
	printf("\nfrente=%d",x);
    i=ColaVacia(&c);
	printf("\ncolavacia=%d\n",i);
	printf("\nObteniendo el elemento final");
	EliminarFinal(&c,&x);
	printf("\nelemento final=%d",x);
	InsertarFrente(&c,5);
	EliminarFrente(&c,&x);
	printf("\nfrente de la cola=%d",x);
    return 0;
}

