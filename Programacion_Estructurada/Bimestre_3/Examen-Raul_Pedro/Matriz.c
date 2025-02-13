/* Nombre: Matriz.c
  Descripción: Uso de archivos. Tipo de archivo: texto. Modo de apertura: lectura.
  * Funciones usadas: fopen, fscanf. Calcula la suma de cada fila de una matriz.
  Autor: Raul(M3G@)
  Fecha: 16/jun/2011
*/
#include <stdio.h>
#include <stdlib.h>

void SumaFil (int **mat, int f, int c);

int main()
{
	FILE *archivo;
	int i,j,f,c,**mat, ele;
	printf("\n          ****ARCHIVOS****   \n");
	if ((archivo = fopen("Matriz.txt", "r"))	 == NULL)/*Usa una funcion para abrir el archivo y se lo asigna a arch y verifica si
													el arch = NULL, este archivo es igual a NULL cuando el archivo no existe*/
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return 1;
	}
	fscanf(archivo,"%d",&f);
	fscanf(archivo,"%d",&c);
	mat = (int **)malloc(f * sizeof(int *));
	for (i = 0; i < f;i++)
		mat[i] = (int *)malloc(c * sizeof(int));
	printf("\n\nLlenando la matriz con el contenido del archivo Matriz.txt\n");
	for (i = 0; i < f; i ++)
	{
		for (j=0;j<c;j++)
		{
			if (fscanf(archivo,"%d",&ele) > 0)
				mat[i][j] = ele;
		}
	}
	fclose(archivo);
	SumaFil (mat, f, c);
	return 0;
}

void SumaFil (int **mat, int f, int c)
{
	int i,j,suma;
	for (i = 0; i < f; i++)
	{
		suma = 0;
		for (j = 0; j < c; j++)
			suma = suma + mat[i][j];
		printf("La suma de la columna %d es :  %d", i+1, suma);
		printf("\n");
	}
}


