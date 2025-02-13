#include <stdio.h>
#include "Pila.h"

void PilaVacia (Pila *a)
     {
       a->tope=-1;
     }
     
int EsVacia (Pila *a)
     {
       if (a->tope==-1)
           return 1;
       else
           return 0;  
     }
     
int Cima (Pila a)
    {
      if (!EsVacia(&a))
         return a.frase[a.tope];
      else
         printf("PILA VACIA\n");
    }


void Push (char x, Pila *a)
     {
       
       if (a->tope==MAX-1)
          printf("PILA LLENA\n");
       else {         
              a->tope++;
              a->frase[a->tope]=x;
       }   
     }
     
char Pop (Pila *a)
{
	char aux;
	if (EsVacia(a))
		printf ("PILA VACIA\n");
	else
	{
		aux=a->frase[a->tope];
		a->tope--;
		return aux;
	}    
}
