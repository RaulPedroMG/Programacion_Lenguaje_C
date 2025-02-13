#include <stdio.h>
#include <stdlib.h>

/*
 * Para definir un elemento de la lista, será utilizado el tipo struct. 
 * El elemento de la lista contendrá un campo dato y un puntero siguiente. 
 * El puntero siguiente debe ser del mismo tipo que el elemento, si no, no podrá apuntar hacia el elemento.
 * El puntero siguiente permitirá el acceso al próximo elemento.*/
typedef struct nodo_lista{
	int info;
	struct nodo_lista *sig;
}Nodo;
/*
 * Para tener el control de la lista es preferible guardar ciertos elementos: 
 * El primer elemento, el último elemento, el número de elementos. 
 * Para ello será utilizado otra estructura (no es obligatorio, pueden ser utilizadas variables)*/

/*typedef struct ListaIdentificar {
		Elemento *inicio;
		Elemento *fin;
		int telem;
}Lista;*/
/*
 * El puntero inicio contendrá la dirección del primer elemento de la lista. 
 * El puntero fin contendrá la dirección del último elemento de la lista. 
 * La variable tamaño contiene el número de elementos. 
*/

void CrearLista(Nodo * (&Plista))
{
	Plista = NULL;
}

int EsVacia(Lista *lista)
{
	if(lista->inicio==NULL)
		return 1;
	else
		return 0;
}

int InserPrime(int dato,Lista * lista){
  Elemento *nuevo_elemento;
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  if ((nuevo_elemento->dato = (int *) malloc (1 * sizeof (int)))== NULL)
    return -1;
  nuevo_elemento->dato=&dato;
  nuevo_elemento->siguiente = lista->inicio;
  lista->inicio = nuevo_elemento;
  lista->telem++;
  return 0;
}

int InserVacia(int *dato,Lista * lista){
  Elemento *nuevo_elemento;
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  if ((nuevo_elemento->dato = (int *) malloc (1 * sizeof (int)))== NULL)
    return -1;
  nuevo_elemento->dato=dato;
  nuevo_elemento->siguiente = NULL;
  lista ->inicio = nuevo_elemento;
  lista ->fin = nuevo_elemento;
  lista ->telem++;
  return 0;
}


int main (void)
{
	int *num;
	Nodo lista;
//	Elemento *actual;
//	if ((lista = (Lista *) malloc (sizeof (Lista))) == NULL)
//		return -1;
	/*if ((num = (int *) malloc (1 * sizeof (int)))== NULL)
		return -1;*/
//	actual = NULL;
	CrearLista(*lista);
	if(EsVacia(lista) == 1)
		printf ("La lista esta vacia \n\n");
	printf ("Ingrese un elemento : ");
	scanf("%d",&num);
	printf("\n");
    if (lista->telem == 0){
		InserPrime(num,lista);
		//InserVacia(num,lista);
	}
	actual = lista ->inicio;
	//printf ("El elemento de la lista es : \n");
    printf ("%d",*actual->dato);
    actual = actual->siguiente;
	if (EsVacia(lista)==1)
		printf("\nLista esta vacia");
	else
		printf("\nLista esta llena o al menos tiene un elemento");
	return 0;
}
