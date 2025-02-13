/* UNSIS- Licenciatura en Informática
	Nombre: SerieArmonica.c
	Descripcion: Este programa usa una función recursiva directa imprimir la serie armonica.    
	Autor: Raúl(M3G@)
	fecha: 25 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void Armonica(int can);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main()
{
	int can;
	
	printf("\n\n                          ***Serie Armónica***  \n");
	
	do 
	{
		printf("\n    Introduce la cantidad de sumatorias de la serie armonica :\n            ");
		scanf ("%d",&can);
	}while (can <= 0); /* Regresará hasta que el usuario introduzca un numero positivo */
	
	Armonica(can);	/* Llamada a la función Armonica */
	return 0;
}


/*DEFINICION DE FUNCIONES RECURSIVAS*/
void Armonica(int can)
/*Esta función recursiva se llama a sí misma imprimir la serie armonica*/
{	
	if (can == 1)  /*Paso base*/
	{
		printf("\n    1 / n = 1 / %d",can	);
	}
	else
	{
		Armonica(can-1);  /*Llamada de la misma funcion y mandando can-1*/
		printf("  + 1 / %d",can);
	}
}

