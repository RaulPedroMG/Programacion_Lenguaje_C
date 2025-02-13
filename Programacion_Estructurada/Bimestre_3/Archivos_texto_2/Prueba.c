/* Nombre: archtex2.c
  Descripción: Uso de archivos. Tipo de archivo: texto. Modo de apertura: lectura y escritura.
  * Funciones usadas: fopen, fprintf, fscanf, fgets
  Autor: SKRV
  Fecha: 1/jun/2011
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	 FILE *archivo;
	 int x,cont,f,c;
	 printf("\nAbriendo el archivo...\n");
	 if ((archivo = fopen("./Matriz.txt", "r"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return 1;
	 }
	printf("\n\nImprimiendo el contenido del archivo Matriz.txt\n");
	cont=0;
	while (!feof(archivo) && x != 0)
	{
		fscanf(archivo,"%d" ,&x);
		printf("\n%d  ",x);
		if (cont==0)
		{
			f=x;
		}
		if (cont==1)
		{
			c=x;
		}
		cont++;
		printf("\n");
		printf("                 cont %d , f %d , c %d",cont,f,c);
	}
	fclose(archivo);
	return 0;
}
