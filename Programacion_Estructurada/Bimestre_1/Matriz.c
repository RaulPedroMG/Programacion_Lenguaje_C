/* UNSIS- Licenciatura en Informática
	Nombre: Matrices.c
	Descripcion: Este programa lee e imprime el contenido de un vector.
	Autor: Raul (MEGA)
	fecha: 8 de abril del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define F 3
#define C 3

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int menu();
void Leer_Matriz (int Mat[F][C]);
void Imprimir_Matriz (int Mat[F][C]);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int Matriz[F][C];
	Leer_Matriz (Matriz);
	Imprimir_Matriz (Matriz);

	printf("\n &&&&&&&&&&&&&&  S A L I E N D O  &&&&&&&&&&&&&&                  \n");
	printf("\n	                  ** *                                   \n");
	printf("	                  **   **                                \n");
	printf("	                  **     **                              \n");
	printf("    ********************      **                             \n");
	printf("    ********************      **                             \n");
	printf("                      **     **	                             \n");
	printf("	                  **   **                        	     \n");
	printf("                      *** *                                  \n");

	return 0;
}



/*DEFINICION DE FUNCIONES*/
void Leer_Matriz (int Mat[F][C])
/*LEE VALORES PARA LA MATRIZ*/
{
	int i, j;
	printf("\n");
	for (i = 0; i < F; i++)
	{	
		for (j=0; j < C; j++)
		{	
			printf("Introduce un numero para la Matriz[%d][%d]\n", i,j);
			scanf("%d",&Mat[i][j]);
		}	 
	}
	printf("\n");
} 


/*DEFINICION DE FUNCIONES*/
void Imprimir_Matriz (int Mat[F][C])
/*IMPRIME EL CONTENIDO DE LA MATRIZ*/
{
	int i, j;
	printf("\n");
	printf("La Matriz tiene los siguientes valores:\n");
	for (i=0; i < F; i++)
	{	
		for (j = 0; j < C; j++)
		{	
			printf("    %d", Mat[i][j]); 
		}
		printf("\n");
	}
	printf("\n");
} 



