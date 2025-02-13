/* Nombre: archemp.c
  Descripción: Cargar datos del catálogo de empresas
  Autor: SKRV
  Fecha: 1/jun/2011
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

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


void SepararCad(Empresa *catemp,int *cont,char *cad);
void ImprimirEmp(Empresa *catemp,int cont);
void LeerEmpText(Empresa *catemp,int *cont);
void GuardarEmpText(Empresa *catemp,int cont);
void GuardarEmpBin(Empresa *catemp,int cont);
void LeerEmpBin(Empresa *catemp,int *cont);

int main()

{
	Empresa catemp[MAX];
	int cont=0;
	
	LeerEmpText(catemp,&cont);
 	GuardarEmpText(catemp,cont);
	ImprimirEmp(catemp,cont);
	
	printf("\nGUARDANDO DATOS DE UN ARCHIVO BINARIO\n");
	GuardarEmpBin(catemp,cont);
	printf("\nLEYENDO DATOS DE UN ARCHIVO BINARIO\n");
	LeerEmpBin(catemp,&cont);
	ImprimirEmp(catemp,cont);
	return 0;
}

void LeerEmpText(Empresa *catemp,int *cont)
{
	FILE *arch;
	char cad[450];
	printf("\nAbriendo el archivo...\n");
	 if ((arch = fopen("./empresas3.txt", "r"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return;
	 }

	while (!feof(arch) && *cont < MAX)
	{
		if (fgets(cad,449,arch) != NULL)
		{
			printf("\nRegistro %d",*(cont+1));
			printf("\ncad: <<%s>>",cad);
			SepararCad(catemp,cont,cad);
		}
		else
			printf("\nFIN del archivo...");
	}
	fclose(arch);
}
void SepararCad(Empresa *catemp,int *cont,char *cad)
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

void ImprimirEmp(Empresa *catemp,int cont)
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

void GuardarEmpText(Empresa *catemp,int cont)
{
	int i;
	FILE *arch;
	printf("\nAbriendo el archivo...\n");
	if ((arch = fopen("./archemptbest.txt", "w"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return;
	}

	printf("\nGuardando Empresas del catalogo\n");
	for (i=0; i < cont; i++)
		fprintf(arch,"%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s",catemp[i].clave,catemp[i].nom,catemp[i].giro,catemp[i].dom,catemp[i].edo,catemp[i].cp,catemp[i].tel,catemp[i].fax,catemp[i].cont,catemp[i].correo);
	fclose(arch);
}

void GuardarEmpBin(Empresa *catemp,int cont)
{
	int i;
	FILE *arch;
	printf("\nAbriendo el archivo...\n");
	if ((arch = fopen("./archemptbest.dat", "wb"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return;
	}
	printf("\nGuardando Empresas del catalogo ==> archemptbest.dat\n");
	for (i=0; i < cont; i++)
		fwrite(&catemp[i],sizeof(catemp[i]),1,arch);
	fclose(arch);
}

void LeerEmpBin(Empresa *catemp,int *cont)
{
	FILE *arch;
	printf("\nAbriendo el archivo...\n");
	if ((arch = fopen("./archemptbest.dat", "rb"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return;
	}

	printf("\nLeyendo datos de Empresas del catalogo <== archemptbest.dat\n");
	while(!feof(arch) && *cont < MAX)
	{
		if (fread(&catemp[*cont],sizeof(catemp[*cont]),1,arch) > 0 )
			(*cont)++;
	}
	fclose(arch);
}
