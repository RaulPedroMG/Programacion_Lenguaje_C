/*UNSIS_li
Nombre:Amigos.c
Descripci√≥n:Programa para capturar e imprimir los datos de la estructura Amigos.
Tambien guardara y leera de un archivo binario.
Autor:Heriberto
Fecha:15-06-2011
*/

#include <stdio.h>
#include <string.h>
#define M 20 

typedef struct
{
	char nombre[10];
	int dia;
	int mes;
}Amigos;

void LeerAmigos(Amigos lis[M],int *cont);
void Imprimir(Amigos lis[M],int t);
void LeerArchivo(Amigos lis[M],int *t);
void Guardar(Amigos lis[M],int t);
int Menu();

int main()
{
	int cont=0,x=0;
	int op;
	Amigos lista[M];
	while (x==0)
    {
      op=Menu();
      switch(op)
      {
       case 1:LeerAmigos(lista,&cont);
            break;
       case 2:Imprimir(lista,cont);
            break;
       case 3:LeerArchivo(lista,&cont);
            break;
       case 4:Guardar(lista,cont);
            break;
       case 5:x=1;
            break;
      }
	}
	return 0;
}

void LeerAmigos(Amigos lis[M],int *cont)
{
	int x=1;
	char nom[10];
	int di,me;
	do
	{
		if(*cont<M)
		{
			printf("\nNombre\n");
			scanf("%s",nom);
			//fgets(nom,10,stdin);
			//printf("nom: %s\n",nom);
			if(nom[0] != '\0' && nom[0] != '\n')
			{
				strcpy(lis[*cont].nombre,nom);
				printf("Dia\n");
				scanf("%d",&di);
				lis[*cont].dia=di;
				printf("Mes\n");
				scanf("%d",&me);
				lis[*cont].mes=me;
				(*cont)+=1;	
			}
			else
				x = 0;
			//*cont+=1;
		}
		printf("\nCapturar otro amigo?si=1;no=0\n");
		scanf("%d",&x);
	}while (x==1);
}

void Imprimir(Amigos lis[M],int t)
{
	int i;
	if(t==0)
		printf("\nNo hay datos\n");
	else
	{
		printf("\nNombre\t\tDia\tMes\n");
		for (i=0;i<t;i++)
		{
			printf("%s\t\t",lis[i].nombre);
			printf("%d\t",lis[i].dia);
			printf("%d\n",lis[i].mes);
		}
	}
}

int Menu()
{
    int x;
    printf("\n\tAgenda Amigos\n\n");
    printf("\t1.-Agregar amigo\n");
    printf("\t2.-Imprimir\n");
    printf("\t3.-Ver agenda\n");
    printf("\t4.-Guardar\n");
    printf("\t5.-Salir\n");
    printf("\tElige una opciÛn\n");
    scanf("%d",&x);
    return x;
}

void LeerArchivo(Amigos lis[M],int *t)
{
     FILE *arch;
     printf("\nAbriendo el archivo...\n");
     if((arch=fopen("./Amigos.txt","rb"))==NULL)
         fprintf(stderr,"Error:El archivo no se pudo abrir\n");                                                     
     else
     {
         printf("\nLeyendo datos\n");
	     while(!feof(arch) && *t < M)
	     {
            if (fread(&lis[*t],sizeof(Amigos),1,arch) > 0 )
            {
			   (*t)++;
            }
	    }
	    fclose(arch);
     }
}

void Guardar(Amigos lis[M],int t)
{
    int i;
	FILE *arch;
	printf("\nGuardando Archivo..\n");
	if ((arch = fopen("./Amigos.txt", "wb"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
	}
	for (i=0; i < t; i++)
		fwrite(&lis[i],sizeof(lis[i]),1,arch);
	fclose(arch); 
 }
