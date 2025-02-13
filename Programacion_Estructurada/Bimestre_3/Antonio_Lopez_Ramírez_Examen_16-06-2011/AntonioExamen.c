/* 
 * UNIVERSIDAD DE LA SIERRA SUR 
 * Licenciatura en Iformatica
 * Nombre: AntonioExamen.c
 * Descripción: Este programa pedira el numero de columnas y renglones 
 * y reservara espacio en memoria dinamica para una matriz, la llenara con el archivo Matriz.txt.
 * Autor: MadokaHellie (Antonio López Ramírez)
 * Fecha: 16-Junio-2011
 */
#include <stdio.h>
#include <stdlib.h>

void ImpMatriz(int  ** mat,int f, int c);

int main()
{
	FILE *arch;
	int vacio,i,j,fil,col,**mat,cont=0;
	if ((arch = fopen("./Matriz.txt", "r"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return 1;
	}
	printf("Introduce el numero de filas: ");
	if (scanf("%d",&fil)>0)
	{
		mat = (int **)malloc(fil * sizeof(int *));
	    printf("\nIntroduce el numero de columnas: ");
		if (scanf("%d",&col)>0)
		{
			for (i = 0; i < fil;i++)
				*(mat+i) = (int *)malloc(col * sizeof(int));
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
	{
		printf("\nError, archivo incompleto!");
	}
	i=j=0;
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			cont=cont+mat[i][j];
		}
		printf("\nLa suma de la fila %d es: %d\n",i+1,cont);
		cont=0;
	}
			
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
		{
		   if(mat[i][j]==120)
		   {
			   printf("%4c",mat[i][j]);
		   }
		   else
		   {
			printf("%4d",mat[i][j]);
		   }
	    }
	}
}
