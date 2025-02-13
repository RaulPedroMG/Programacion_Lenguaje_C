/* Nombre: Amigos.c
  Descripción: Programa para capturar e imprimir los datos de la estructura
			   Amigos, tambien guardara y leera unh archivo binario.
  Autor: ESTEBAN "EL MAGO"
  Fecha: 14-06-2011
*/
#include <stdio.h>
#include <string.h>
typedef struct 
{
	char nom[10];
	int dia;
	int mes;
	
}Amigos;

//Declaración de funciones
void LeerAmigos(Amigos lis[50], int *cont);
void ImprimirAmigos(Amigos lis[50], int cont);
void LeerArchivo(Amigos lis[50], int *cont);
void GuardarArchivo(Amigos lis[50], int cont);

int main()

{
	Amigos lis[50];
	int cont=0;
	
	LeerArchivo(lis,&cont);
	printf("\nTOTAL DE AMIGOS DE ESTEBAN: %d",cont);
	ImprimirAmigos(lis,cont);
	
	LeerAmigos(lis,&cont); //Llamada de las funciones
	ImprimirAmigos(lis,cont);
	//LeerArchivo(lis,&cont);
	//GuardarArchivo(lis,cont);
	
	printf("\nGUARDANDO DATOS DE UN ARCHIVO BINARIO\n");
	GuardarArchivo(lis,cont);
	printf("\nTOTAL DE AMIGOS DE ESTEBAN: %d",cont);
	
	printf("\nLEYENDO DATOS DE UN ARCHIVO BINARIO\n");
	LeerArchivo(lis,&cont);
	ImprimirAmigos(lis,cont);
	return 0;
}

void LeerAmigos(Amigos lis[50], int *cont)
{
	char nom [10];
	int salir=0;
	do
	{
		printf("\nIntroduce el nombre de tu amigo\n");
		scanf("%s",nom);
		if (nom[0] != 'x')
		{
			strcpy(lis[*cont].nom,nom);
			printf("\nIntroduce el dia de nacimiento de tu amigo\n");
			scanf("%d",&lis[*cont].dia);
			printf("\nIntroduce el mes de nacimiento de tu amigo\n");
			scanf("%d",&lis[*cont].mes);
			(*cont)++;
		}
		else
			salir = 1;
	}while (salir != 1);
	
}

void ImprimirAmigos(Amigos lis[50], int cont)
{
	int i;
	printf("\nLISTA DE AMIGOS DE ESTEBAN\n");
	for(i=0;i<cont;i++)
		{
			printf("\nAmigos %d", i);
			printf("\nNombre: %s", lis[i].nom);
			printf("\nDia: %d",lis[i].dia );
			printf("\nMes: %d",lis[i].mes);
		}
}

void LeerArchivo(Amigos lis[50], int *cont)
{
	FILE *arch;
	printf("\nAbriendo el archivo...\n");
	 if ((arch = fopen("./Amigos.dat", "rb"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return;
	 }

	while (!feof(arch) && (*cont) < 50)
	{
		if (fread(&lis[*cont],sizeof(Amigos),1,arch) > 0)
		{
			(*cont)++;
		}
	}
	fclose(arch);
}

void GuardarArchivo(Amigos lis[50], int cont)
{
	FILE *arch;
	int i;
	printf("\nAbriendo el archivo...\n");
	 if ((arch = fopen("./Amigos.dat", "wb"))	 == NULL)
	 {
			fprintf(stderr, "No se puede abrir el archivo de salida.\n");
			return;
	 }
	i=0;
	while (i < cont)
	{
		fwrite(&lis[i],sizeof(Amigos),1,arch);
		i++;
	}
	fclose(arch);
}
