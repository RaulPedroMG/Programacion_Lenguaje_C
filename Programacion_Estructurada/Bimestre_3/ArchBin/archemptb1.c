/* Nombre: archemptb.c
  Descripción: Cargar datos del catálogo de empresas en archivo de texto y después guardarlo
  * en archivo binario
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
	char *nom;
	char *giro;
	char *dom;
	char *edo;
	int cp;
	char *tel;
	char *fax;
	char *cont;
	char *correo;
	char visita;
	char est;
	char ss;
}Empresa;

typedef struct 
{
	char clave[10];
	char nom[80];
	char giro[150];
	char dom[250];
	char edo[50];
	int cp;
	char tel[150];
	char fax[150];
	char cont[150];
	char correo[150];
	char visita;
	char est;
	char ss;
}EmpresaEst;

void SepararCad(Empresa *catemp,int *cont,char *cad);
void ImprimirEmp(Empresa *catemp,int cont);
void GuardarEmpText(Empresa *catemp,int cont);
void GuardarEmpBin(Empresa *catemp,int cont);
void LeerEmpBin(Empresa *catemp,int *cont);
void LeerEmpText(Empresa *catemp,int *cont);

int main()

{
	Empresa catemp[MAX];
	int cont=0;

	LeerEmpText(catemp,&cont);
	ImprimirEmp(catemp,cont);
	GuardarEmpText(catemp,cont);
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
	char subc[200];
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
				case 1 : strcpy(catemp[*cont].clave,subc);
						break;
				case 2 : catemp[*cont].nom = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].nom,subc);
						break;
				case 3 : catemp[*cont].giro = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].giro,subc);
						break;
				case 4 : catemp[*cont].dom = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].dom,subc);
						break;
				case 5 : catemp[*cont].edo = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].edo,subc);
						break;
				case 6 : catemp[*cont].cp = atoi(subc);
						break;
				case 7 : catemp[*cont].tel = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].tel,subc);
						break;
				case 8 : catemp[*cont].fax = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].fax,subc);
						break;
				case 9 : catemp[*cont].cont = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].cont,subc);
						break;
				case 10 :catemp[*cont].correo = (char *) malloc(strlen(subc));
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
	if ((arch = fopen("./emp3.txt", "w"))	 == NULL)
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
	EmpresaEst temp;
	printf("\nAbriendo el archivo...\n");
	if ((arch = fopen("./emp3.dat", "wb"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return;
	}
	printf("\nGuardando Empresas del catalogo ==> emp3.dat\n");
	for (i=0; i < cont; i++)
	{
		strcpy(temp.clave,catemp[i].clave);
		strcpy(temp.nom,catemp[i].nom);
		strcpy(temp.giro,catemp[i].giro);
		strcpy(temp.dom,catemp[i].dom);
		strcpy(temp.edo,catemp[i].edo);
		temp.cp = catemp[i].cp;
		strcpy(temp.tel,catemp[i].tel);
		strcpy(temp.fax,catemp[i].fax);
		strcpy(temp.cont,catemp[i].cont);
		strcpy(temp.correo,catemp[i].correo);
		temp.visita = catemp[i].visita;
		temp.est = catemp[i].est;
		temp.ss = catemp[i].ss;
		fwrite(&temp,sizeof(temp),1,arch);
	}
	fclose(arch);
}

void LeerEmpBin(Empresa *catemp,int *cont)
{
	FILE *arch;
	EmpresaEst temp;
	printf("\nAbriendo el archivo...\n");
	if ((arch = fopen("./emp3.dat", "rb"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return;
	}

	printf("\nLeyendo datos de Empresas del catalogo <== emp3.dat\n");
	while(!feof(arch) && *cont < MAX)
	{
		if (fread(&temp,sizeof(temp),1,arch) > 0 )
		{
			strcpy(catemp[*cont].clave,temp.clave);
			catemp[*cont].nom = (char *) malloc(strlen(temp.nom));
			strcpy(catemp[*cont].nom,temp.nom);
			catemp[*cont].giro = (char *) malloc(strlen(temp.giro));
			strcpy(catemp[*cont].giro,temp.giro);
			catemp[*cont].dom = (char *) malloc(strlen(temp.dom));
			strcpy(catemp[*cont].dom,temp.dom);
			catemp[*cont].edo = (char *) malloc(strlen(temp.edo));
			strcpy(catemp[*cont].edo,temp.edo);
			catemp[*cont].cp = temp.cp;
			catemp[*cont].tel = (char *) malloc(strlen(temp.tel));
			strcpy(catemp[*cont].tel,temp.tel);
			catemp[*cont].fax = (char *) malloc(strlen(temp.fax));
			strcpy(catemp[*cont].fax,temp.fax);
			catemp[*cont].cont = (char *) malloc(strlen(temp.cont));
			strcpy(catemp[*cont].cont,temp.cont);
			catemp[*cont].correo = (char *) malloc(strlen(temp.correo));
			strcpy(catemp[*cont].correo,temp.correo);
			catemp[*cont].visita = temp.visita;
			catemp[*cont].est = temp.est;
			catemp[*cont].ss = temp.ss;
			(*cont)++;
		}
	}
	fclose(arch);
}
