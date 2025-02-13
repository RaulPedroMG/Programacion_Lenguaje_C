#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "lista.h"
#include "formato.h"
#include "FunCalcula.h"
/*
 * Funcione y procedimientos creados por el equipo 1
 * */
void crearLista(struct nodo **lista)
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
	//if(p)
	        p=crea_nodo();
	        p->info=x;
	        p->sig=*lista;
	        *lista=p;
}

void InsertaFin(int x,struct nodo **lista){
    struct nodo *p, *aux;
	if(EsVacia(*lista)){                       
		    p=crea_nodo();
        	p->info=x;      
	        p->sig=*lista;
        	*lista=p;
		}else{
		    p=crea_nodo();
			for(aux=*lista; aux->sig!=NULL; aux=aux->sig);
			    p->info=x;
			    p->sig=NULL;
			    aux->sig=p;
		}
}
void Eliminar(struct nodo **lista){
        struct nodo *aux;
		if(EsVacia(*lista)){       
		        *lista=NULL;
		}else{
			for(aux=*lista; aux->sig->sig!=NULL; aux=aux->sig);
				aux->sig=NULL;
		}
}
void InsertaMedio(int x, struct nodo **lista, struct nodo *n){
    struct nodo *p;
    p=crea_nodo();
	if(p)
	{
		if(n==NULL){
			p->info=x;
			p->sig=NULL;
			*lista=p;		
		}else
		{
			p->info=x;
		        p->sig=n->sig;
		        n->sig=p;
		}
	}else
		printf("Error !desbordamiento¡\n");

}

struct nodo *localiza(struct nodo *lista,int val){
	struct nodo *temp;
	int band=0;
	temp=lista;
	do
	{
		if(temp->info>=val)
		{
			band=1;
		}
		else
			temp=temp->sig;
	}
	while(temp->sig!=NULL && band!=1);
	if(temp->info==val)
		return temp;
	else
		return NULL;
}

void Anula(struct nodo **lista){
	*lista = NULL;

}

struct nodo *crea_nodo(){
	return ((struct nodo *)malloc(sizeof(struct nodo)));
}
/*
 * NOTA:
 * 		struct nodo siempre debe de estar escrito de este modo
*/

void implista(struct nodo *lista)
{
	printw("\n");
	printw("       ");
	for(;lista!=NULL;lista=lista->sig){
		printw("%d",lista->info);
	}
}
