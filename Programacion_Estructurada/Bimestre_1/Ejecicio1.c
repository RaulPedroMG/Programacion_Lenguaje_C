/* UNSIS- LI
	Nombre: Ejercicio1.C
	Descripcion: Calcula el area de un circulo, ademas servira para 		
		explicar la estructura de un programa en C y tambien la 		
		etapa de compilacion.
	Autor: Raul
	fecha: 4 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define PI 3.1416

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
float AreaCir (float rad);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	float r,a;
	printf("Dame le valor del radio:");
	scanf("%f",&r);
	a=AreaCir(r);
	printf("El area del circulo es:%f",a);
	return 0;
}


/*DEFINICION DE FUNCIONES*/
float AreaCir (float rad)
/*CALCULA EL AREA DEL CIRCULO RAD*/
{
	float area;
	area=rad*rad*PI;
	return area;
} 
  
