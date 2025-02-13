#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int info;
	struct nodo *sig;
};

int Menu();
void ListaVacia(struct nodo **lista);
int EsVacia(struct nodo *lista);
void InserPrim(int x, struct nodo **lista);
void inserta_num(struct nodo **lista,int num);
struct nodo *crea_nodo();
void imp_lista(struct nodo *lista);

int main()
{

	int opc,num;
	//struct nodo *lista=NULL;
	struct nodo *lista;
	//struct nodo *p;
	do{
		opc=Menu();
		if(opc>0 && opc<4)
		{
			switch(opc)
			{
				case 1:
					if(EsVacia(lista) == 0)
						ListaVacia(&lista);
					else
						printf("\n\tLa lista ya fue creada");
				break;
				
				case 2:
					printf("\nEscribe el número a insertar: ");
					scanf("%d",&num);
					InserPrim(num,&lista);
				break;
				
				case 3:
					if(EsVacia(lista) == 0)
						imp_lista(lista);
					else
						printf("\n\tLa lista esta vacia");
				break;
			}
		}
		if(opc < 1 || opc > 4)
			printf("\t\t Opcion Invalida");
	}while(opc != 4);
	/*if(lista != NULL)
	{
		printf("\nLa lista no esta vacia\n");
		imp_lista(lista);
		printf("\n\n");
		p=(struct nodo *)malloc(sizeof(struct nodo));
		p=lista;
		lista=lista->sig;
		free(p);
		imp_lista(lista);
		if(EsVacia(lista) == 1)
			printf("\nLa lista esta vacia\n");
		else
			printf("\nLa lista no esta vacia\n");
	}*/
		return 0;
}

int Menu()
{
	int opc;
	printf("\n\n\t\tMenu");
	printf("\n\t1 : Crear lista");
	printf("\n\t2 : Insertar primero");
	printf("\n\t3 : Imprimir lista");
	printf("\n\t4 : Salir");
	printf("\n\tElija una opcion : ");
	scanf("%d",&opc);
	return opc;
}

void ListaVacia(struct nodo **lista)
{
	*lista = NULL;
}

int EsVacia(struct nodo *lista)
{
	if(lista == NULL)
		return 1;
	else
		return 0;
}

void InserPrim(int x, struct nodo **lista)
{
	struct nodo *p;
	p=crea_nodo();
	p->info=x;
	p->sig=*lista;
	*lista=p;
}

void inserta_num(struct nodo **lista,int num){
	struct nodo *p;
	p=crea_nodo();
	p->info=num;
	p->sig=*lista;
	*lista=p;
}

struct nodo *crea_nodo()
{
	return ((struct nodo *)malloc(sizeof(struct nodo)));
}

void imp_lista(struct nodo *lista)
{
	for(;lista!=NULL;lista=lista->sig)
		printf("%d->",lista->info);
}
