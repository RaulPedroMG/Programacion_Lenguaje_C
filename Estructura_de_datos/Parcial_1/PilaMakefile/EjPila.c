/*
 *  EjPila.c
 *  
 *
 *  Created by Víctor Gómez on 21/10/11.
 *  Copyright 2011 UNSIS. All rights reserved.
 *
 */

#include <stdio.h>
#include "Pila.h"

int main()
{
    int aux,i;
    Pila a;
    PilaVacia(&a);
    Pop(&a);
    for (i=1; i<=MAX;i++)
        Push(i,&a);
    Push(11,&a);    
    printf("DATO EN LA CIMA: %d\n",Cima(a));    
    printf("Los datos de la pila son: \n");
    for (i=1; !EsVacia(&a);i++)
	{
		aux=Pop(&a);
		printf("%d ",aux);
	} 
    printf("\n");     
    return 0;
}