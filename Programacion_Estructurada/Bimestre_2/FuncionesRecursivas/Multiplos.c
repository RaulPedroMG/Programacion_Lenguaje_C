/* UNSIS- Licenciatura en Informática
	Nombre: multiplos.c
	Descripcion: Este programa usa una función recursiva directa para encontrar los primeros n multiplos de 
	* 			un número introducido por el usuario    
	Autor: Raúl(M3G@)
	fecha: 25 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void Multiplos(int num, int can, int mul);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main()
{
	int num, can, mul=0;
	
	printf("\n\n                          ***Multiplos***  \n");
	do 
	{
		printf("\n    Introduce un número positivo para encontrar sus multiplos:\n            ");
		scanf ("%d",&num);
	}while (num <= 0); /* Regresará hasta que el usuario introduzca un numero positivo */
	
	do 
	{
		printf("\n    Introduce la cantidad de multiplos a encontrar:\n            ");
		scanf ("%d",&can);
	}while (can <= 0); /* Regresará hasta que el usuario introduzca un numero positivo */
	
	Multiplos(num, can, mul);	/* Llamada a la función Multiplos */
	return 0;
}


/*DEFINICION DE FUNCIONES RECURSIVAS*/
void Multiplos(int num, int can, int mul)
/*Esta función recursiva se llama a sí misma imprimir los multiplos de num*/
{	
	mul=num*can;
	if (can == 1)  /*Paso base*/
	{
		//printf("\n El %d° multiplo de %d es: %d",can,num, num);
		printf("\n    %d * n = %d",num,mul);
	}
	else
	{
		Multiplos(num, can-1, mul);  /*Llamada de la misma funcion y mandando num, can-1, mul*/
		//printf("\n El %d° multiplo de %d es: %d",can,num, mul);
		printf(", %d",mul);
	}
}

