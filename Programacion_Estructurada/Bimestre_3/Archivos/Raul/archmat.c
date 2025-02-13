/* Nombre: archmat.c
  Descripción: Uso de archivos. Tipo de archivo: texto. Modo de apertura: lectura y escritura.
  * Funciones usadas: fopen, fprintf, fscanf, fgets. El programa lee el nombre del archivo, el
  * el numero de filas y el numero de columnas.
  Autor: Raul(M3G@)
  Fecha: 9/jun/2011
*/
#include <stdio.h>
#include <stdlib.h>

void ImpMatriz(int  ** mat,int f, int c);

int main()
{
	FILE *arch;
	int vacio,i,j,fil,col,**mat;
	char archivo[15];
	printf("\n          ****ARCHIVOS****   \n");
	printf("\nEscribe el nombre del archivo:\n     ");
	scanf("\n%s",&*archivo);
	if ((arch = fopen(archivo, "r"))	 == NULL)/*Usa una funcion para abrir el archivo y se lo asigna a arch y verifica si
													el arch = NULL, este archivo es igual a NULL cuando el archivo no existe*/
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return 1;
	}
	printf("\nIntroduce el número de filas:\n     ");
	scanf("%d",&fil);
	printf("\nIntroduce el número de columnas:\n     ");
	scanf("%d",&col);
	mat = (int **)malloc(fil * sizeof(int *));
	for (i = 0; i < fil;i++)
		mat[i] = (int *)malloc(col * sizeof(int));
	printf("\n\nLlenando la matriz con el contenido del archivo %s\n",archivo);
	vacio=0;
	for (i=0; i<fil; i++)
	{
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
	fclose(arch);
	ImpMatriz(mat, fil, col);
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

