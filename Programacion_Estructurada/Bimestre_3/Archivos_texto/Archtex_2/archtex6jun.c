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
	 FILE *archsal;
	 int i,x;
	 //char cad[81];
	 srand(rand()%30+1);
	 printf("\nCreando el archivo...\n");
	 if ((archsal = fopen("./valores.dat", "wt+"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return 1;
	 }

	 for (i = 0; i < 15; i++)
	 {
		x = rand()%100+15;
		//fprintf(archsal,"\n%2d. El valor generado es : %3d",i+1,x);
		fprintf(archsal,"%d %d\n",i+1,x);
	 }
	//fseek(archsal,0,SEEK_SET); /*Indice del archivo*/ 
	rewind(archsal);
	printf("\n\nImprimiendo el contenido del archivo valores.dat\n");
	/*while (!feof(archsal))
	{
			if (fgets(cad,81,archsal) != NULL)
				puts(cad);
	}*/
	while (!feof(archsal))
	{
		fscanf(archsal,"%d %d",&x, &i);
		printf("%d + %d = %d\n",x,i,x+i);
	}
	fclose(archsal);
	return 0;
}
