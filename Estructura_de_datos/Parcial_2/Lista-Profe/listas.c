#include <stdio.h>
#include <stdlib.h>

struct nodo{
int info;
struct nodo *sig;
};

void inserta_num(struct nodo **lista,int num);
struct nodo *crea_nodo();
void imp_lista(struct nodo *lista);

int main()
{

int n,num,i;
struct nodo *lista=NULL;
struct nodo *p;
printf("Cuantos numeros tiene la lista: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("Escribe el numero a insertar: ");
    scanf("%d",&num);
    inserta_num(&lista,num);
    }
imp_lista(lista);
printf("\n\n");
p=(struct nodo *)malloc(sizeof(struct nodo));
p=lista;
lista=lista->sig;
free(p);
imp_lista(lista);

return 0;
}

void inserta_num(struct nodo **lista,int num){
struct nodo *p;
p=crea_nodo();
p->info=num;
p->sig=*lista;
*lista=p;
}

struct nodo *crea_nodo(){
return ((struct nodo *)malloc(sizeof(struct nodo)));
}

void imp_lista(struct nodo *lista){
for(;lista!=NULL;lista=lista->sig)
   printf("%d->",lista->info);
}
