/* UNSIS- LI
	Nombre: FuinciónRango.c
	Descripcion: 
	Autor: Raul (MEGA)
	fecha: 15 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>


/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int operacion (int op1, char opr, int op2);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int operando1, operando2, res;
	char operador;
	do
	{
		printf("\nSIMULACION DE UNA CALCULADORA BASICA\n");
		printf("OPERACIONES VALIDAS\n");
		printf("Suma(+)   Resta(-)   Multiplicacion(*)   Division(/)   Modulo(%%) \n");
		printf("Para salir pulse @ \n");
		printf("Introduce el operador:\n");
		scanf("%c",&operador);

		if (operador != '@')
		{
			printf("Introduce el valor del operando1:\n");
			scanf("%d",&operando1);
			printf("Introduce el operando2:\n");	
			scanf("%d",&operando2);
			res = operacion (operando1, operador ,operando2);
			printf("El resultado es:%3d %1c %2d = %2d ",operando1, operador, operando2, res);		
		}
		getchar();	
	}while (operador != '@');
	return 0;
}

/*DEFINICION DE FUNCIONES*/
int operacion (int op1, char opr, int op2)
/*REALIZA LA OPERACION DE ACUERDO A LOS VALORES QUE FUERON INTRODUCIDOS POR EL USUARIO*/
{
	int resul;
	switch (opr)
	{
		case ('+'): resul = op1 + op2;
		break;

		case ('-'): resul = op1 - op2;
		break;
	
		case ('*'): resul = op1 * op2;
		break;
		
		case ('/'): resul = op1 / op2;
		break;

		case ('%'): resul = op1 % op2;
		break;
	}
	return resul;
} 

