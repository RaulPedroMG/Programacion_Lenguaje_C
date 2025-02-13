/* UNSIS- LI
	Nombre: Cua_Mag.c
	Descripcion: El algoritmo imprime un cuadro mágico.
	Autor: Raul (MEGA)
	fecha: 25 de abril del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define N 5

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void Llenar_Cua (int Mat[N][N]);
void Imprimir_Cua (int Mat[N][N]);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int mat[N][N];
	Llenar_Cua (mat);
	Imprimir_Cua (mat);
	return 0;
}


/*DEFINICION DE FUNCIONES*/
void Llenar_Cua (int Mat[N][N])
/*IMPRIME EL VECTOR*/
{
	int i,j;
	printf("\n");
	for (i=0; i < N; i++)
	{	
		 for (j=0; j < N; j++)
		{
			if (i == 0 && j == 0)
			{
				Mat[i][j] = 17;
			}	
			if ( j == 2)
			{
				Mat[i][j] = Mat[i][j-1] + 2;
				if (Mat [i][j] > N*N)
				{
					Mat[i][j] = Mat[i][j] - N*N;
				}	
			}
			if (j != 0 && j != 2 && j != 0)
			{
				Mat[i][j] = Mat[i][j-1] + 7;
				if (Mat [i][j] > N*N)
				{
					Mat[i][j] = Mat[i][j] - N*N;
				}
			}
			if (j == N-1 && i!=0 && i != N-1)
			{
				Mat[i][j] = Mat[i][j-1] + 2;
				if (Mat [i][j] > N*N)
				{
					Mat[i][j] = Mat[i][j] - N*N;
				}	
			}
			if (j == 0 )
			{
				if (i == 1 || i == N-2 )
				{
					Mat[i][j] = Mat[i-1][N-1] + 8;
					if (Mat [i][j] > N*N)
					{
						Mat[i][j] = Mat[i][j] - N*N;
					}
				}
				if	(i > 1 && i < N-2)
				{
					Mat[i][j] = Mat[i-1][N-1] + 13;
					if (Mat [i][j] > N*N)
					{
						Mat[i][j] = Mat[i][j] - N*N;
					}	
				}
			}	
		}		
	}
	printf("\n");
} 

/*DEFINICION DE FUNCIONES*/
void Imprimir_Cua (int Mat[N][N])
/*IMPRIME EL CONTENIDO DE LA MATRIZ*/
{
	int i, j;
	printf("\n");
	printf("El cuadro mágico tiene los siguientes valores:\n");
	for (i=0; i < N; i++)
	{	
		for (j = 0; j < N; j++)
		{	
			printf("   %d", Mat[i][j]); 
		}
		printf("\n");
	}
	printf("\n");
} 


