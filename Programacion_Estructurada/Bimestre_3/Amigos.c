#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#define MAX 50

typedef struct 
	{
		char *nom;
		int mes;
		int dia;
	}Amigo;

void Error(char *cad, int r);
int Menu();
void LeerArchivo(Amigo *lista, int *t);
void LeerAmigo();
void ImprimirArchivo (Amigo *lista,int t);
void GuardarArchivo();


int main ()
{
	Amigo lista[MAX];
	int total=0, opc;
	
	LeerArchivo(lista, &total);
	do
	{
		opc = Menu();
		if (opc > 0 && opc < 4)
		{
			switch (opc)
			{
				case 1: //LeerAmigo();
				break;
				
				case 2: clear();
						ImprimirArchivo(lista, total);
				break;
	
				case 3://GuardarArchivo();
				break;
			}
		}
		if (opc < 1 || opc > 4)
		{
			printf("\n\n\n\t\tOpción inválida, vuelva a introducirla");
		}
	}while(opc != 4);	 
	return 0;
}


int Menu()
{
	int opc;
	printf("\t\t\t**A M I G O S**\n\n");
	printf("\t\t1 : A G R E G A R   A M I G O \n");
	printf("\t\t2 : I M P R I M I R   L I S T A\n");
	printf("\t\t3 : G U A R D A R   A R C H I V O\n");
	printf("\t\t\t4 : S A L I R\n\n");
	printf("\tIntroduzca el número de opción : ");
	scanf("%d\n",&opc);
	return opc;
}

void LeerArchivo (Amigo *lista, int *t)
{
	FILE *archivo;
	if ((archivo = fopen("./Amigos.dat", "rb"))	 == NULL)
	{
			fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			//return 1;
	}
	printf("\n\nLeyendo el contenido del archivo Amigos.dat\n");
	while (!feof(archivo) && *t < MAX)
	{
		if (fread(&lista[*t],sizeof(Amigo),1,archivo) > 0 )
		{
			(*t)++;
		}
	}
	fclose(archivo);
}

void ImprimirArchivo (Amigo *lista, int t)
{
	int i;		
	printf("\n\t\tAmigos en la lista");
	for (i=0; i < t; i++)
	{
		printf("\n\nNum %d",i+1);
		printf("\nNombre: %s",lista[i].nom);
		printf("\nMes de nacimiento: %d",lista[i].mes);
		printf("\nDia de nacimiento: %d",lista[i].dia);
	}
}
