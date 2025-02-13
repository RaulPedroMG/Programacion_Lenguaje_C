/* UNSIS- Licenciatura en Informática
	Nombre: Fibonacci.c
	Descripcion: Este programa usa una función recursiva directa para encontrar el resultado de la serie de fobonacci de num 
	Autor: Raúl(M3G@)
	fecha: 25 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int Fibonacci(int num);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main()
{
	int num;
	
	printf("\n\n             ***Fibonacci***  \n");
	do 
	{
		printf("\n    F(n)\n Introduce un número positivo para n :\n            ");
		scanf ("%d",&num);
	}while (num < 0); /* Regresará hasta que el usuario introduzca un numero positivo */
		
	printf("\n    F(%d)= %d",num,Fibonacci(num));	
	return 0;
}


/*DEFINICION DE FUNCIONES RECURSIVAS*/
int Fibonacci(int num)
/*Esta función recursiva se llama a sí misma para imprimir el resultado de la serie de fibonacci de num*/
{	
	if (num > 1) /*Paso base*/
	{
		return Fibonacci(num - 1) + Fibonacci(num - 2);  /*Llamadas de la misma funcion*/	
	}
	return num;
}
