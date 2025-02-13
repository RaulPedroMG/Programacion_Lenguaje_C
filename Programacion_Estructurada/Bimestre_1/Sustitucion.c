/* UNSIS- LI
	Nombre: Sustitución.c
	Descripcion: El algoritmo lee los elementos de un vector y los sustituye de acuerdo a la elección del usuario.
	Autor: Raul (MEGA)
	fecha: 15 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define N 10


/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void Llenado (int vec[N]);
void Sustituir (int vec[N]);
void Impresion (int vec[N]);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int vec[N];
	Llenado (vec);
	Sustituir (vec);
	Impresion (vec);
	return 0;
}

/*DEFINICION DE FUNCIONES*/
void Llenado (int vec[N])
/*LEE Y ASIGNA VALORES A CADA ALEMENTO DEL VECTOR*/
{
	int i, num;
	for (i=0; i < N; i++)
	{
		printf("Introduce un numero:\n");
		scanf("%d",&num);
		vec[i]=num;
	}
	printf("\n");
} 



/*DEFINICION DE FUNCIONES*/
void Sustituir (int vec[N])
/*LEE Y ASIGNA VALORES A CADA ALEMENTO DEL VECTOR*/
{
	int i, x, y;
	do
	{
		printf("\nINTRODUCE 0 PARA SALIR\n");
		printf("Dame el valor a sustituir:\n");
		scanf("%d",&x);
		if (x != 0)
		{
			printf("Dame el valor que sustituye:\n");
			scanf("%d",&y);
			for (i=0; i < N; i++)
			{
				if(vec [i] == x)
				{
					vec [i] = y;
				}	
			}
		}
	}
	while (x != 0);
	printf("\n");
} 









/*DEFINICION DE FUNCIONES*/
void Impresion (int vec[N])
/*GRAFICA EL DATO ALMACENADO EN EL ARREGLO*/
{
	int i;
	printf("El conjunto de números actualizados es:\n");	
	for (i=0; i < N; i++)
	{
		printf("%d",vec[i]);	
		printf("\n");
	}
	printf("\n\n");
} 

