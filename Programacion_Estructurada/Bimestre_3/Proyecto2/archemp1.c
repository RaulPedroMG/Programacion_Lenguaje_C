/* Nombre: archemp.c
  Descripción: Cargar datos del catálogo de empresas
  Autor: SKRV
  Fecha: 1/jun/2011
*/
#include <stdio.h>

//void SeparaCad(Empresa *catemp,int *cont,char *cad);

int main()
{
	 FILE *arch;
	 int cont=0;
	 char cad[426];
	 printf("\nAbriendo el archivo...\n");
	 if ((arch = fopen("./empresas1.txt", "r"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return 1;
	 }

	while (!feof(arch))
	{
		if (fgets(cad,425,arch) != NULL)
		{
			printf("\nRegistro %d",cont++);
			printf("\ncad: <<%s>>",cad);
		}
		else
			printf("\nFIN del archivo...");
		
	}
	fclose(arch);
	
	return 0;
}

