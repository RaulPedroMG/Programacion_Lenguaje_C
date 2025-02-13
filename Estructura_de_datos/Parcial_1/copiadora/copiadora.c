#include<stdio.h>
#include<stdlib.h>
#include"cola.h"
#include<time.h>

int main()
{
	COLA q;
	int continuar,ncopias,i=0, total=0;
	iniciar_cola(&q);	

	do
		{
		srand((unsigned) time(NULL));
		system("sleep 1"); 
		ncopias=rand()%51;
		printf("Llega un cliente solicitando %d fotocopias\n",ncopias);		
		continuar=encolar(ncopias,&q);
		i++;
		total=total+ncopias;
		}while(continuar!=-2 && ncopias!=0);

	printf("\n\n");	
	while(cola_vacia(&q)!=COLA_VACIA)
		printf("Procesando %d fotocopias\n",desencolar(&q));	

	printf("\n\nCerrando la fotocopiadora, se atendierón %d personas con un total de %d\n", i-1, total);
	return 0;
}
