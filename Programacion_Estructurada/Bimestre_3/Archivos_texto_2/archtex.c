/* Nombre: archtex.c
  Descripción: Uso de archivos. Tipo de archivo: texto. Modo de apertura: lectura y escritura.
  Autor: SKRV
  Fecha: 18/jun/2010
*/
#include <stdio.h>

int main()
{
	 FILE *archent, *archsal;

	 if ((archent = fopen("./archtex.c", "rt"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de entrada.\n");
			return 1;
	 }

	 if ((archsal = fopen("./archtex.txt", "wt"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return 1;
	 }
	printf("\nCopiando el archivo archbin.c a archbin.txt...\n\n");
	 while (!feof(archent))
			fputc(fgetc(archent), archsal);

	 fclose(archent);
	 fclose(archsal);
   return 0;
}

