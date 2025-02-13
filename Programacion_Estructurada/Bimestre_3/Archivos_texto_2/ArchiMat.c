/* Nombre: archtex2.c
  Descripción: Uso de archivos. Tipo de archivo: texto. Modo de apertura: lectura y escritura.
  * Funciones usadas: fopen, fprintf, fscanf, fgets
  Autor: SKRV
  Fecha: 1/jun/2011
*/
#include <stdio.h>
#include <stdlib.h>
#define F 5
#define C 4

void LeerMatriz(int i, int x,int f, int c, int Matriz[F][C]);
void ImprimirMatriz(int f, int c, int Matriz[F][C]);

int main()
{
	 FILE *archMat;
	 int i, x, f, c=0, Mat[F][C];
	 printf("\nAbriendo el archivo...\n");
	 if ((archMat = fopen("./Matriz.txt", "r"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return 1;
	 }
	printf("\n\nLeyendo el contenido del archivo Matriz.txt\n");
	i=0;
	while (!feof(archMat) && x != 0)
	{
		fscanf(archMat,"%d" ,&x);
		if (i == 0)
		{
			f=x;
		}
		if (i == 1)
		{
			c=x;
		}
		if (i>=2)
		{ 
			LeerMatriz(i,x,f,c,Mat);
		}
		i++;	
	}
	ImprimirMatriz(f, c, Mat);
	fclose(archMat);
	return 0;
}


void LeerMatriz(int i, int x,int f, int c, int Matriz[F][C])
{
	int indf=0, indc=i-2;
	if (indc > c)
	{
		indc = 0;
		indf=(f+c)/(i-2);
	}
	if(indf < f && indc < c)
	{
		Matriz[f][c]= x;
	}
}

void ImprimirMatriz(int f, int c, int Matriz[F][C])
{
	int i,j;
	for(i = 0; i < f; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%d ",Matriz[f][c]);
		}
		printf("\n");
	}
}
