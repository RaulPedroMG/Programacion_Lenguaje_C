/* UNSIS- Licenciatura en Informática
	Nombre: Contar.c
	Descripcion: Este programa usa una función recursiva directa para contar de 1 a 10 
	* 			(Los números estan predeterminados en el programa)  
	Autor: Raul (M3G@)
	fecha: 26 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void contar(int cima);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
  contar(10); /*Llamada de la función contar*/
  return 0;
}

/*DEFINICION DE FUNCIONES RECURSIVAS*/
void contar(int cima)
/*Esta función recursiva se llama a sí misma para imprimir los numeros de 1 hasta cima*/
{
  if (cima > 1) /*Paso base*/
    contar(cima-1);
  printf ("%d " , cima) ;
}
