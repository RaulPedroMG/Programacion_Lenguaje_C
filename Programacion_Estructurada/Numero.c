/* UNSIS- LI
	Nombre: Sustitución.c
	Descripcion: El algoritmo lee los elementos de un vector y los sustituye de acuerdo a la elección del usuario.
	Autor: Raul (MEGA)
	fecha: 15 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define N 10


/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int Num_Dig ( int n, int vec[N]);
int Impares (int vec[N], int elementos);
void Frecuencia (int vec[N], int elementos);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int num, vec[N], elem, im;
	printf("\nIntroduce un numero:\n");
	scanf("%d",&num);
	elem = Num_Dig (num, vec);
	im = Impares (vec, elem);
	printf("\nEl número tiene %d digitos impares:\n", im);
	Frecuencia (vec, elem);
	return 0;
}




/*DEFINICION DE FUNCIONES*/
int Num_Dig (int n, int vec[N])
/*SEPARA EL NUMERO POR DIGITOS*/
{
	int i;
	for (i=0; n != 0; i++)
	{		
		vec[i]= n % 10; 
		n = n / 10;
	}
	printf("\n");
	return i;
} 

/*DEFINICION DE FUNCIONES*/
int Impares (int vec[N], int elementos)
/*OBTIENE LA CANTIDAD DE DIGITOS IMPARES*/
{
	int i, impar=0;
	for (i=0; i < elementos ; i++)
	{		
		if(vec[i]  % 2 == 1) 
		{
			impar = impar + 1;
		}
	}
	printf("\n");
	return impar;
} 


/*DEFINICION DE FUNCIONES*/
void Frecuencia (int vec[N], int elementos)
/*CALCULA LA FRECUENCIA DE LOS NUMEROS*/
{
	int i, j, n, rep;
	for (i=0; i < elementos ; i++)
	{		
		if(vec[i] != -1) 
		{
			n = vec[i];
			rep = 1;
			for (j= i+1 ; j < elementos ; j++)
			{
				if(vec[i] == vec[j]) 
				{
					vec[j] = -1;
					rep = rep + 1;
				}
			}
			if(rep == 1)
			{	
				printf("\nEl número %d se repite: %d vez\n", n,rep);
			}
			else
			{
				printf("\nEl número %d se repite: %d veces\n", n,rep);
			}		
		}
	}
	printf("\n");
} 

