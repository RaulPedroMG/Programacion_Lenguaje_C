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
	 FILE *arch;
	 int i,x,j;
	 //char cad[81];
	 srand(rand()%30+1);
	 printf("\nAbriendo el archivo...\n");
	 if ((arch = fopen("./Mio.txt", "r"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return 1;
	 }
	printf("\n\nImprimiendo el contenido del archivo Mio.txt\n");
	while (!feof(arch) && x != 0)
	{
		fscanf(arch,"%d %d %d" ,&x, &i, &j);
		printf("%d %d %d\n",x,i,j);
	}
	fclose(arch);
	return 0;
}
