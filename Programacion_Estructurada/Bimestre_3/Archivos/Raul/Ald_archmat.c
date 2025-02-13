/* Nombre: archmat.c
  Descripción: Uso de archivos. Tipo de archivo: texto. Modo de apertura: lectura y escritura.
  * Funciones usadas: fopen, fprintf, fscanf, fgets. El programa lee el nombre del archivo, el
  * el numero de filas y el numero de columnas, ademas de mostrar la matriz pide un numero para encontrar
  * sus alderedores.
  Autor: Raul(M3G@)
  Fecha: 9/jun/2011
*/
#include <stdio.h>
#include <stdlib.h>

void ImpMatriz(int  ** mat,int f, int c);
void Buscarnum(int *i, int *j, int num, int **mat, int f, int c);
void ImpAlderedor(int **mat, int f, int c, int fil, int col);

int main()
{
	FILE *arch;
	int vacio,num,indi,indj,i,j,fil,col,**mat;
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
	printf("\n\nIntroduce el numero para imprimir sus alderedores:\n     ");
	scanf("%d",&num);
	Buscarnum(&indi, &indj, num, mat, fil, col);
	printf("\nNumeros alderedores...\n");
	ImpAlderedor( mat, indi, indj,fil,col);
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

void Buscarnum(int *indf, int *indc, int num, int **mat, int f, int c)
{
	int i, j;
	for (i = 0; i < f; i++)
	{
		for (j = 0; j < c; j++)
		{
			if(mat[i][j] == num)
			{
				*indf = i;
				*indc = j;
				i = f; /* Se le asigna a i el valor de f y a j el valor de c para poder salir de los ciclos
						y así imprimir los alderedores del primer número que encuentre en caso de que haya números repetidos*/
				j = c;
			}
		}	
	}
}

void ImpAlderedor(int **mat, int f, int c, int fil, int col)
{
	int i, j, s=0;
	for (i = f-1; i <= f+1; i++)
	{
		printf("\n");
		for (j = c-1; j <= c+1; j++)
		{	
			if(i >= 0 && i < fil && j < col && j >= 0)
			{
				if(i == f && j== c)
				{
					printf("%4d*",mat[i][j]);
				}
				else
				{
					printf("%4d",mat[i][j]);
				}
			}
			else
			{
				s++; /*Variable que cuenta la cantidad de numeros que no rodean a num*/
			}
		}
	}
	if(s > 0)
		printf("\n\nNo existen %d numeros que rodén al número %d ",s, mat[f][c]);
}
