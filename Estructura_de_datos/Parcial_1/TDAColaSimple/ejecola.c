#include <stdio.h>
#include "cola.h"

int main()
{
    int aux,i;
    Cola a;
    crearcola(&a);
    quitar(&a);
    for (i=1; i<=MAX;i++)
        insertar(&a,i);
        
    insertar(&a,11);    
    printf("DATO EN LA CIMA: %d\n",frente(a));    
    printf("Los datos de la pila son: \n");
    for (i=1; !colavacia(&a);i++)
	{
		aux=quitar(&a);
		printf("%d ",aux);
	} 
    printf("\n");     
    return 0;
}
