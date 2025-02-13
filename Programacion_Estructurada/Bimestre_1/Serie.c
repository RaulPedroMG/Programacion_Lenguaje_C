/* UNSIS- LI
	Nombre: Ejercicio1.C
	Descripcion: Utiliza una funcion serie con un argumento entero x, para calcular la suma siguiente:
		suma= 1/1 + 1/2 + 1/3 + 1/4 + 1/5+.......+1/n 
	Autor: Raul (MEGA)
	fecha: 16 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
float Serie (int l);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int n;
	float suma;
	printf("Dame del limite de la serie:\n");
	scanf("%d",&n);
	suma=Serie(n);
	printf("El resultado es:  %f",suma);
	printf("\n");
	return 0;
}


/*DEFINICION DE FUNCIONES*/
float Serie (int l)
/*CALCULA LA SUMATORIA DE LA SERIE*/
{
	int i;
	float res=0;
	for (i=1; i<=l; i++)
	{
		res=res+(1.0/i);
	}
	return res;
} 
  
