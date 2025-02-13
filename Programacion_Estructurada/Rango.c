/* UNSIS- LI
	Nombre: Ejercicio1.C
	Descripcion: El algoritmo manda un rango establecido a la funcion para que esta verifique 
		si el número esta entre un rango, si esto se cumple regresará el número para después 
		imprimirlo de lo contrario segurá pidiendo el numero hasta que esté en el rango.
	Autor: Raul (MEGA)
	fecha: 4 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define min 3
#define max 15
/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int Leer_num (int min; int max);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int num;
	num=Leer_num(min; max);
	printf(num);
	return 0;
}


/*DEFINICION DE FUNCIONES*/
float Leer_num (int min; int max)
/*VERIFICA SI EL NUMERO ESTA DENTRO DEL RANGO*/
{
	int num;
	do {
		printf("Introduce el número numero:\n");
		scanf("%d",&num);

		if(num<min || num>max)
			printf("\nEl número está fuera del rango, por favor vuelva a introducirlo\n");
	
	}while (num<min || num>max);

	return num;
} 
  
