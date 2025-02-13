/* Nombre: archemp.c
  Descripción: Cargar datos del catálogo de empresas
  Autor: SKRV
  Fecha: 1/jun/2011
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
	char clave[10];
	char nom[100];
	char giro[50];
	char dom[160];
	char edo[20];
	int cp;
	char tel[50];
	char fax[15];
	char cont[60];
	char correo[15];
	char visita;
	char est;
	char ss;
}Empresa;


void SeparaCad(Empresa *catemp,int *cont,char *cad);
void ImprimeEmp(Empresa *catemp,int cont);

int main()

{
	 FILE *arch;
	 Empresa catemp[100];
	 int cont=0;
	 char cad[426];
	 printf("\nAbriendo el archivo...\n");
	 if ((arch = fopen("./empresas3.txt", "r"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return 1;
	 }

	while (!feof(arch))
	{
		if (fgets(cad,425,arch) != NULL)
		{
			printf("\nRegistro %d",cont+1);
			printf("\ncad: <<%s>>",cad);
			SeparaCad(catemp,&cont,cad);
		}
		else
			printf("\nFIN del archivo...");
	}
	fclose(arch);
	
	ImprimeEmp(catemp,cont);
	return 0;
}

void SeparaCad(Empresa *catemp,int *cont,char *cad)
{
	int campo,i,j;
	char subc[170];
	for (campo=0,i=0, j=0; i < strlen(cad);i++)
	{
		if (cad[i] != '\t' && cad[i] != '\n')
			subc[j++]= cad[i];
		else
		{
			subc[j] = '\0';
			j = 0;
			campo++;
			switch (campo)
			{
				case 1 : //printf("\nClave: %s",subc);
						strcpy(catemp[*cont].clave,subc);
						break;
				case 2 : //printf("\nNombre: %s",subc);
						strcpy(catemp[*cont].nom,subc);
						break;
				case 3 : //printf("\nGiro: %s",subc);
						strcpy(catemp[*cont].giro,subc);
						break;
				case 4 : //printf("\nDomicilio: %s",subc);
						strcpy(catemp[*cont].dom,subc);
						break;
				case 5 : //printf("\nEstado: %s",subc);
						strcpy(catemp[*cont].edo,subc);
						break;
				case 6 : //printf("\nCP: %s",subc);
						catemp[*cont].cp = atoi(subc);
						break;
				case 7 : //printf("\nTelefono: %s",subc);
						strcpy(catemp[*cont].tel,subc);
						break;
				case 8 : //printf("\nFax: %s",subc);
						strcpy(catemp[*cont].fax,subc);
						break;
				case 9 : //printf("\nContacto: %s",subc);
						strcpy(catemp[*cont].cont,subc);
						break;
				case 10 : //printf("\nCorreo: %s",subc);
						strcpy(catemp[*cont].correo,subc);	
			}
		}
		
	}
	(*cont)++;
}

void ImprimeEmp(Empresa *catemp,int cont)
{
	int i;
	printf("\n\t\tEmpresas en el catalogo\n");
	for (i=0; i < cont; i++)
	{
		printf("\n\nRegistro: %d",i+1);
		printf("\nClave: %s",catemp[i].clave);
		printf("\tNombre: %s",catemp[i].nom);
		printf("\nGiro: %s",catemp[i].giro);
		printf("\nDomicilio: %s",catemp[i].dom);
		printf("\nEstado: %s",catemp[i].edo);
		printf("\tCP: %d",catemp[i].cp);
		printf("\tTelefono: %s",catemp[i].tel);
		printf("\tFax: %s",catemp[i].fax);
		printf("\nContacto: %s",catemp[i].cont);
		printf("\nCorreo: %s",catemp[i].correo);
	}
}
