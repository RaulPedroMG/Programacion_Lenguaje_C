/* UNSIS- LI
	Nombre: Numeros_Menores.c
	Descripcion:      
	Autor: Raul (MEGA)
	fecha: 6 de abril del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define N 50


/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int Leer_Num (int vec[N]);
int Menores (int vec[N], int elementos);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int vec[N], elem, menores;
	elem = Leer_Num (vec);
	if (elem > 1)
	{
		menores = Menores (vec, elem);
		printf("\nLa cantiada de números menores al número anterior son:  %d\n", menores);
	}	
}




/*DEFINICION DE FUNCIONES*/
int Leer_Num (int vec[N])
/*LEE UNA SERIE DE NÚMEROS Y FINALIZA CUANDO EL USUARIO INTRODUCE UN CERO*/
{
	int i = 0, num;
	printf("\nIntroduce un cero para salir\n");
	do
	{		
		printf("\nIntroduce un número (%d):\n",i+1);
		scanf("%d",&num);
		vec[i] = num;
		i++;
	}while (num != 0);
	printf("\n");
	return i;
} 

/*DEFINICION DE FUNCIONES*/
int Menores (int vec[N], int elementos)
/*OBTIENE LA CANTIDAD DE NÚMEROS MENORES AL ANTERIOR*/
{
	int i, j, menor = 0;
	for (i=0, j=i+1; j < elementos - 1 ; i++, j++)
	{		
		if(vec[i] > vec[j]) 
		{
			menor++;
		}
	}
	printf("\n");
	return menor;
} 



