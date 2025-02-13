#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <time.h>
#include "torres.h"
#include "variables.h"
#include "pilas.h"
#include "formato.h"

void PilaVacia (Pila *a){
	a->tope=-1;
}
     
int EsVacia (Pila *a){
  if (a->tope==-1)
     return 1;
  else
     return 0;  
}
     
int Cima (Pila a){
	if (!EsVacia(&a))
		return a.arreglo[a.tope];
	else{
		printf("PILA VACIA\n");
		return 0;
	}
}


void Push (int x, Pila *a){
	if (a->tope==todis-1){
		printf("PILA LLENA\n");
	}else {         
		a->tope++;
		a->arreglo[a->tope]=x;
	}   
}
     
int Pop (Pila *a){
	int aux;
	if (EsVacia(a)){
		return 0;
		printf ("PILA VACIA\n");
	}else{
		aux=a->arreglo[a->tope];
		a->tope--;
		return aux;
	}    
}
