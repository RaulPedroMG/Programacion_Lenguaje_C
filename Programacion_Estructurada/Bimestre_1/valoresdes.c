/* UNSIS- LI
	Nombre: Ejercicio3.C
	Descripcion: Lee 3 numeros y verifica si el usuarioa lo introduce de manera descendente, 
		de lo contrario le vuelve a pedir los valores hasta que el sean introducido correctamente.
	Autor: Raul (MEGA)
	fecha: 14 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int num1,num2,num3;
	do
	{
		printf("Introduce el primer valor:\n");
		scanf("%d",&num1);
		printf("Introduce el segundo valor:\n");
		scanf("%d",&num2);
		printf("Introduce el tercer valor:\n");
		scanf("%d",&num3);

		if(num1>num2 && num2>num3)
			printf("\n\nHa introducido los valores correctamente\n");
		else
			printf("Vuelva a introducir los datos\n");
		

	}while (num1<num2 || num2<num3);
	return 0;
}



