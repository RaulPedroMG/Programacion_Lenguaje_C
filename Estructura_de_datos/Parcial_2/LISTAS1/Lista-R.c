#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int Menu();
void imp_lista(struct nodo *lista);

int main()
{
	int opc,num;
	struct nodo *lista;
	struct nodo *tm=NULL;
	do{
		opc=Menu();
		if(opc>0 && opc<9){
			switch(opc){
				case 1:
					if(EsVacia(lista) == 0)
						crearLista(&lista);
					else
						printf("\n\tLa lista ya fue creada");
				break;
				case 2: 
					printf("\nEscribe el número a insertar: ");
					scanf("%d",&num);
					InserPrim(num,&lista);
				break;
				case 3:
					printf("\nEscribe el número al final: ");
					scanf("%d",&num);
					InsertaFin(num, &lista);
				break;
				case 4:
					printf("\nEscribe el número a buscar: ");
					scanf("%d",&num);
					tm=localiza(lista,num);
					if(tm!=NULL){
					        printf("\nEscribe el número para insertar en medio: ");
					        scanf("%d",&num);
					        InsertaMedio(num, &lista, tm);
					}
					else
					        printf("Numero no encontrado");
				break;
				case 5:
				        Eliminar(&lista);
				break;
				case 6:
					if(EsVacia(lista) == 0)
						imp_lista(lista);
					else
						printf("\n\tLa lista esta vacia");
				break;
				case 7:
				        Anula(&lista);
			}
		}
		if(opc < 1 || opc > 9)
			printf("\t\t Opcion Invalida");
	}while(opc != 8);
	return 0;
}

int Menu()
{
	int opc;
	printf("\n\n\t\tMenu");
	printf("\n\t1 : Crear lista");
	printf("\n\t2 : Insertar primero");
	printf("\n\t3 : Insertar al final");
	printf("\n\t4 : Insertar en medio");
	printf("\n\t5 : Eliminar el último nodo");
	printf("\n\t6 : Imprimir lista");
	printf("\n\t7 : Anular lista");
	printf("\n\t8 : Salir");
	printf("\n\telija una opcion : ");
	scanf("%d",&opc);
	return opc;
}
void imp_lista(struct nodo *lista)
{
	for(;lista!=NULL;lista=lista->sig)
		printf("|%d|->",lista->info);
}
