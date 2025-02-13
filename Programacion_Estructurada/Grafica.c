/* UNSIS- LI
	Nombre: FuinciónRango.c
	Descripcion: El algoritmo grafica los datos almacenados en un arreglo
	Autor: Raul (MEGA)
	fecha: 15 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define N 5


/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void Llenado (int vec[N]);
void Grafica (int vec[N]);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int vec[N];
	Llenado (vec);
	Grafica (vec);
	return 0;
}

/*DEFINICION DE FUNCIONES*/
void Llenado (int vec[N])
/*LEE Y ASIGNA VALORES A CADA ALEMENTO DEL VECTOR*/
{
	int i, num;
	for (i=0; i<=N; i++)
	{
		printf("Introduce un numero:\n");
		scanf("%d",&num);
		vec[i]=num;
	}
	printf("\n");
} 

/*DEFINICION DE FUNCIONES*/
void Grafica (int vec[N])
/*GRAFICA EL DATO ALMACENADO EN EL ARREGLO*/
{
	int i,j;
	for (i=0; i<=N; i++)
	{
		for (j=0; j<vec[i]; j++)
		{
			printf("@");
		}	
		printf("\n");	
	}
	printf("\n\n");
} 

