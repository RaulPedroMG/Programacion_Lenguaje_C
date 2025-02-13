/* Nombre: archtex3.c
  Descripción: Uso de archivos. Tipo de archivo: texto. Modo de apertura: lectura y escritura.
  * Funciones usadas: fopen, fprintf, fscanf, fgets
  Autor: SKRV
  Fecha: 1/jun/2011
*/
#include <stdio.h>
#include <stdlib.h>

void ImpMatriz(int  ** mat,int f, int c);

int main()
{
	FILE *arch;
	int vacio,i,j,fil,col,**mat;
	if ((arch = fopen("./matriz.txt", "r"))	 == NULL)/*Usa una funcion para abrir el archivo y se lo asigna a arch y verifica si
													el arch = NULL, este archivo es igual a NULL cuando el archivo no existe*/
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return 1;
	}
	if (fscanf(arch,"%d",&fil)>0)/*En este paso lee como entero un contenido de la Matriz.txt y se lo asigna a la variable fil
								y verifica si el valor > 0*/
	{
		mat = (int **)malloc(fil * sizeof(int *));
		if (fscanf(arch,"%d",&col)>0)
		{
			for (i = 0; i < fil;i++)
				mat[i] = (int *)malloc(col * sizeof(int));
			printf("\n\nLlenando la matriz con el contenido del archivo matriz.txt\n");
			vacio=0;
			for (i=0; i<fil; i++)
				for (j=0;j<col;j++)
				{
					if (!vacio && fscanf(arch,"%d",&mat[i][j]) <= 0)
					{
						mat[i][j] = 0;
						if (feof(arch))
							vacio = 1;
					}
					else
					if(vacio)
						mat[i][j] = 0;
				}
		}
		else
			printf("\nError, archivo incompleto!");
	}
	else
		printf("\nError, archivo incompleto!");
		
	fclose(arch);

	ImpMatriz(mat,fil,col);
	return 0;
}

void ImpMatriz(int  ** mat,int f, int c)
{
	int i,j;
	for (i=0; i<f; i++)
	{
		printf("\n");
		for (j=0;j<c;j++)
			printf("%4d",mat[i][j]);
	}
}
