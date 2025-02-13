/*UNIVERSIDAD DE LA SIERRA SUR - LICENCIATURA EN INFORMATICA
 * Nombre: Vector.c
 * Descripción: Este programa reserva espacio suficiente para n reales y los lee, 
				para que despues imprima el promedio de los elementos del vector y 
				la diferencia del promedio con respecto a cada elemento del vector. 
 * 	Autor: Raúl (M3G@)
 * 	Fecha: 1 de Junio de 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#include <stdlib.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void LeerVector(int n, float *ap);
float Promedio(int n, float *ap);
void Diferencias(int n, float *ap, float promedio);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main()
{
	int n;
	float *ap, promedio;
	
  	printf("\n       ***USO DE MEMORIA DINÁMICA***");
	do
	{
		printf("\n\nCuantos elementos tendrá el arreglo?:\n       ");
		scanf("%d",&n);
	}while (n < 1 || n > 50);
	ap = (float *)malloc (n * sizeof(int));
	if (!ap)
		printf("\nNo hay memoria disponible!");
	else
	{
		printf("\n       Leyendo vector...");
		LeerVector (n, ap);
		printf("\n");
		promedio = Promedio(n, ap);
		printf("\nEl promedio de todos los elementos es : %f ",promedio);
		printf("\n\n       Diferencias...");
		Diferencias (n, ap, promedio);
		free(ap);
	}
	return 0;
}

/*DEFINICION DE FUNCIONES*/
void LeerVector (int n, float *ap)
{
	int ind;
	for (ind = 0;ind < n; ind++)
	{	
		printf("\nDame el valor para el elemento [%d] : ",ind+1);
		scanf("%f",&*ap+ind);
	}
}

float Promedio(int n, float *ap)
{
	int ind;
	float prom = 0;
	for (ind = 0;ind < n; ind++)
	{	
		prom = prom + ap[ind];
	}
	prom = prom / n;
	return prom;  
}

void Diferencias(int n, float *ap, float promedio)
{
	int ind;
	float dif;
	for (ind = 0;ind < n; ind++)
	{	
		dif = promedio - ap[ind];
		printf("\nLa diferencia en el promedio con [%f] es : %f",*ap+ind,dif);
	}
}
