/*RAUL PEDRO MENDEZ GARCIA                            Fecha : 09/11/11
 * Palindromo
 * Verifica si una palabra es palindromo con la ayuda de la implementacion del TDA Pila 
*/
#include <stdio.h>
#include <string.h>

#include "Pila.h"
#define MAXP 40

int main()
{
    int i, band = 1;
    char palabra[MAXP];
    Pila a;
    Pila aux;
    Pila b;
    PilaVacia(&a);
    PilaVacia(&aux);
    PilaVacia(&b);
    printf(" Escribe la palabra:  ");
    //gets(palabra);
    scanf("%[^\n]",palabra);
    //scanf("%s",palabra);
    for(i = 0; i < strlen(palabra); i++)
    {
		if (palabra[i] != ' ')
		{
			Push(palabra[i],&a);
			Push(palabra[i],&aux);
		}
	}
	while(!EsVacia (&aux))
	{
		Push(Pop(&aux), &b);
	}
	while(!EsVacia(&a) && !EsVacia(&b))
	{
		if(Pop(&a) != Pop(&b))
		{
			band = 0;
		}
	} 
	if (band == 1)
	{
		printf("La palabra es Palindromo");
	}
	else
	{
		printf("La palabra no es Palindromo");
	}     
    return 0;
}
