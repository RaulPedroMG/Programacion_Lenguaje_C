/* UNSIS- LI
	Nombre: Sustitución.c
	Descripcion: El algoritmo muestra un menú donde el usuario puede eligir una opción de lo que desea realizar con el vector.
	Autor: Raul (MEGA)
	fecha: 31 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#define N 10


/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int menu();
void Leer_vec (int vec[N]);
void Imprimir_vec (int vec[N]);
int Mayor_vec (int vec[N]);
int Menor_vec (int vec[N]);
float Promedio_vec (int vec[N]);
void Frecuencia_vec (int vec[N], int vec_c[N]);
void Invertir_vec (int vec[N], int vec_c[N]);
void Histograma_vec (int vec[N]);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int opc, vec[N], vec_c[N], mayor, menor;
	float prom;
	do
	{
		opc = menu();
		if (opc >=1 && opc <= 8)
			{
				switch (opc)
				{
					case (1):
							Leer_vec(vec);
					break;
			
					case (2): 
							Imprimir_vec (vec);
					break;
				
					case (3):
							mayor = Mayor_vec (vec) ;
							printf("\nEl número mayor es:%d\n",mayor);
					break;
					
					case (4): 
							menor = Menor_vec (vec);
							printf("\nEl número menor es:%d\n",menor);
					break;
		
					case (5): 
							prom = Promedio_vec (vec);
							printf("\nEl promedio es:%f\n",prom);
					break;
			
					case (6): 
							Frecuencia_vec (vec, vec_c);
					break;
			
					case (7): 
							Invertir_vec (vec, vec_c);
					break;
			
					case (8): 
							Histograma_vec (vec);
					break;
			}
		}
		else
		{
			if ( opc < 1 || opc > 9 )
			{
				printf("\n*******El número de la opcion es incorrecta*******\n");
			}
		}	
			

	}while (opc != 9);

	printf("\n &&&&&&&&&&&&&&  S A L I E N D O  &&&&&&&&&&&&&&                  \n");
	printf("\n	              ** *                                   \n");
	printf("	              **   **                                \n");
	printf("	              **     **                              \n");
	printf("    ********************      **                             \n");
	printf("    ********************      **                             \n");
	printf("                      **     **	                             \n");
	printf("	              **   **                        	     \n");
	printf("                      *** *                                  \n");

	return 0;
}


/*DEFINICION DE FUNCIONES*/
int menu()
/*MUESTRA EL MENU Y LEE EL NUMERO DE LA OPCIÓN*/
{
	clear();	
	int opc;
	printf("\n       *********MENÚ DEL VECTOR*********\n");
	printf("       *                               *\n");
	printf("       *    1 : Leer el vector         *\n");
	printf("       *    2 : Imprimir el vector     *\n");
	printf("       *    3 : Encontrar el mayor     *\n");
	printf("       *    4 : Encontrar el menor     *\n");
	printf("       *    5 : Obtener el promedio    *\n");
	printf("       *    6 : Obtener frecuencias    *\n");
	printf("       *    7 : Invertir los datos     *\n");
	printf("       *    8 : Histograma             *\n");	
	printf("       *    9 : Salir                  *\n");
	printf("       *                               *\n");
	printf("       *********************************\n");
	printf("\n¿Qué desea hacer?\n");
	scanf("%d",&opc);
	return opc;	
		
}	



/*DEFINICION DE FUNCIONES*/
void Leer_vec (int vec[N])
/*LEE VALORES PARA SIGNARSELOS A LOS ELEMENTOS DEL VECTOR*/
{
	int i, num;
	printf("\n");
	for (i=0; i < N; i++)
	{	
		printf("Introduce un numero (%d)\n", i + 1);
		scanf("%d",&num);
		vec[i]= num; 
	}
	printf("\n");
} 


/*DEFINICION DE FUNCIONES*/
void Imprimir_vec (int vec[N])
/*IMPRIME EL VECTOR*/
{
	int i;
	printf("\n");
	printf("El vector tiene como elementos:\n");
	for (i=0; i < N; i++)
	{	
		printf("  %d   ", vec[i]); 
	}
	printf("\n");
} 



/*DEFINICION DE FUNCIONES*/
int Mayor_vec (int vec[N])
/*OBTIENE EL NÚMERO MAYOR DEL VECTOR*/
{
	int i, mayor=0;
	for (i=0; i < N; i++)
	{	
		if( vec[i] > mayor )
		{
			mayor = vec[i];	
		}
	}
	printf("\n");
	return mayor;
} 


/*DEFINICION DE FUNCIONES*/
int Menor_vec (int vec[N])
/*OBTIENE EL NÚMERO MENOR DEL VECTOR*/
{
	int i, menor = 0;
	for (i=0; i < N; i++)
	{	
		if( menor == 0)
		{
			menor = vec[i];
		}	
		if( vec[i] < menor )
		{
			menor = vec[i];	
		}
	}
	printf("\n");
	return menor;
} 


/*DEFINICION DE FUNCIONES*/
float Promedio_vec (int vec[N])
/*CALCULA EL PROMEDIO DE LOS ELEMENTOS DEL VECTOR*/
{
	int i, suma = 0;
	float prom, elem;
	for (i=0; i < N; i++)
	{	
		suma = suma + vec[i];	
	}
	elem=N;
	prom = suma / elem;
	printf("\n");
	return prom;
} 


/*DEFINICION DE FUNCIONES*/
void Frecuencia_vec (int vec[N], int vec_c[N])
/*CALCULA LA FRECUENCIA DE LOS NUMEROS*/
{
	int i, j, num, rep;
	for (i=0; i < N ; i++)
	{
		vec_c[i] = vec[i];	
	}
	for (i=0; i < N ; i++)
	{		
		if(vec_c[i] != 'a') 
		{
			num = vec_c[i];
			rep = 1;
			for (j= i+1 ; j < N ; j++)
			{
				if(vec_c[i] == vec_c[j]) 
				{
					vec_c[j] = 'a';
					rep = rep + 1;
				}
			}
			if(rep == 1)
			{	
				printf("\nEl número %d se repite: %d vez\n", num,rep);
			}
			else
			{
				printf("\nEl número %d se repite: %d veces\n", num,rep);
			}		
		}
	}
	printf("\n");
} 


/*DEFINICION DE FUNCIONES*/
void Invertir_vec (int vec[N], int vec_c[N])
/*INVIERTE LOS VALORES ELEMENTOS DEL VECTOR Y LOS IMPRIME*/
{
	int i, j;
	for (i=0, j=N-1 ; i < N && j >= 0; i++, j--)
	{
		vec_c[j] = vec[i];	
	}
	printf("\n\n");
	Imprimir_vec (vec_c);
	printf("\n");
} 


/*DEFINICION DE FUNCIONES*/
void Histograma_vec (int vec[N])
/*IMPRIME UNA SERIE DE CARACTER SEGUN EL VALOR DE CADA ELEMENTO*/
{
	int i,j;
	printf("\n\n");
	for (i=0; i<N; i++)
	{
		for (j=0; j< vec[i]; j++)
		{
			printf("@");
		}	
		printf("\n");	
	}
	printf("\n");
} 



