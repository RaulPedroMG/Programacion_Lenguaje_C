#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cola.h"

int main()
{
    int aux, naleatorio, ncopias, nclientes, tcopias = 0;
    Cola a;
    crearcola(&a);
    do
    {
		srand((unsigned) time(NULL)); 
		system("sleep 1"); 
		naleatorio = (rand() % 25); 
		ncopias = (random() % 51);
		if (ncopias != 0)
		{
			if(!colallena(a))
			{
				insertar(&a, ncopias);
				printf("Llega un cliente solicitando %d copias \n", ncopias);
			}
		}
	}while(naleatorio != 0);
	system("sleep 1"); 
	nclientes = a.final;
	printf("\n");
	while (colavacia(&a) != 1)
	{
		aux = quitar(&a);
		tcopias = tcopias + aux;
		printf("Procesando %d copias\n", aux);
	}
	printf("\nCerrando la fotocopiadora, se atendieron %d clientes con un total de %d copias", nclientes, tcopias);
    /*
    quitar(&a);
    for (i=1; i<=MAX;i++)
        insertar(&a,i);   
    insertar(&a,11);    
    printf("DATO EN LA CIMA: %d\n",frente(a));    
    printf("Los datos de la pila son: \n");
    while(!colavacia(&a))
	{
		aux=quitar(&a);
		printf("%d ",aux);
	} */
    printf("\n");     
    return 0;
}
