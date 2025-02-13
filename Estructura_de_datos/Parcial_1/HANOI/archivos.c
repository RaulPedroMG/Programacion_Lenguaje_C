#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "torres.h"
#include "variables.h"
#include "pilas.h"
#include "formato.h"
#include "archivos.h"


void InsertarDato(Rancking *lista, char *cad, int time, int disco)
{
	int i, j = - 1, band;
	for (i = 0, band = 0; i < P && band == 0; i++)
	{
		if (time <= lista[i].tiempo)
		{
			if(time == lista[i].tiempo)
			{
				j=i;
			}
			if(time < lista[i].tiempo && j == - 1)
			{
				RecorrerDato(lista, i);
				lista[i].nombre = (char *) malloc(strlen(cad));
				lista[i].tiempo = time;
				strcpy(lista[i].nombre, cad);
				lista[i].posicion = i + 1;
				band = 1;
			}
		}
	}
	if(j != -1)
	{
		RecorrerDato(lista, j);
		lista[j+1].nombre = (char *) malloc(strlen(cad));
		lista[j+1].tiempo = time;
		strcpy(lista[j+1].nombre, cad);
		lista[i+1].posicion = j+1;
		
	}
}

void RecorrerDato(Rancking *lista, int ind)
{
	int i;
	for(i= P-2; i >= 0 && i >= ind; i--)
	{
		lista[i+1]=lista[i];
		lista[i+1].posicion = i + 2; 
	}
}

void LeeImpreRancking(Rancking *lista,int ndisco, int opc)
{
	char ndisco1[]="./rancking1.exe";
	char ndisco2[]="./rancking2.exe";
	char ndisco3[]="./rancking3.exe";
	char ndisco4[]="./rancking4.exe";
	char ndisco5[]="./rancking5.exe";
	char ndisco6[]="./rancking6.exe";
	char ndisco7[]="./rancking7.exe";
	char ndisco8[]="./rancking8.exe";
	switch (ndisco)
	{
		case 1:
			if(opc == 1)
			{
				LeerRancking(lista, ndisco1);
			}
			else
			{
				LeerRancking(lista, ndisco1);
				clear();
				ImprimirRancking(lista, ndisco, opc, ndisco1, "Pincipiante");
			}
		break;
		
		case 2:
			if(opc == 1)
			{
				LeerRancking(lista, ndisco2);
			}
			else
			{
				LeerRancking(lista, ndisco2);
				clear();
				ImprimirRancking(lista, ndisco, opc, ndisco2, "Pincipiante");
			}
		break;
		
		case 3:
			if(opc == 1)
			{
				LeerRancking(lista, ndisco3);
			}
			else
			{
				LeerRancking(lista, ndisco3);
				clear();
				ImprimirRancking(lista, ndisco, opc, ndisco3, "Pincipiante");
			}
		break;
		
		case 4:
			if(opc == 1)
			{
				LeerRancking(lista, ndisco4);
			}
			else
			{
				LeerRancking(lista, ndisco4);
				clear();
				ImprimirRancking(lista, ndisco, opc, ndisco4, "Intermedio");
			}
		break;
		
		case 5:
			if(opc == 1)
			{
				LeerRancking(lista, ndisco5);
			}
			else
			{
				LeerRancking(lista, ndisco5);
				clear();
				ImprimirRancking(lista, ndisco, opc, ndisco5, "Intermedio");
			}
		break;
		
		case 6:
			if(opc == 1)
			{
				LeerRancking(lista, ndisco6);
			}
			else
			{
				LeerRancking(lista, ndisco6);
				clear();
				ImprimirRancking(lista, ndisco, opc, ndisco6, "Intermedio");
			}
		break;
		
		case 7:
			if(opc == 1)
			{
				LeerRancking(lista, ndisco7);
			}
			else
			{
				LeerRancking(lista, ndisco7);
				clear();
				ImprimirRancking(lista, ndisco, opc, ndisco7, "Avanzado");
			}
		break;
		
		case 8:
			if(opc == 1)
			{
				LeerRancking(lista, ndisco8);
			}
			else
			{
				LeerRancking(lista, ndisco8);
				clear();
				ImprimirRancking(lista, ndisco, opc, ndisco8, "Avanzado");
			}
		break;
	}
}	

void LeerRancking (Rancking *lista, char *disco)
{
	FILE *arch;
	int total = 0;
	char cad[200];
	 if ((arch = fopen(disco, "r"))	 == NULL)
	 {
			fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
	 }
	else
	{
		while (!feof(arch))
		{
			if (fgets(cad,449,arch) != NULL)
			{
				LlenandoEstruc(lista, cad, &total);
			}
		}
	}
	fclose(arch);
}

void LlenandoEstruc(Rancking *lista, char *cad, int *total)
{
	int campo, i, j;
	char subc[30];
	for (campo = 0, i = 0, j = 0; i < strlen(cad); i++)
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
				case 1 : lista[*total].posicion = atoi(subc);
						break;
				case 2 : lista[*total].nombre = (char *) malloc(strlen(subc));
						strcpy(lista[*total].nombre,subc);
						break;
				case 3 : lista[*total].tiempo = atoi(subc);
						break;
			}
		}
	}
	(*total)++;
}

void ImprimirRancking (Rancking *lista, int ndisco, int opc, char *disco, char *nivel)
{
	int col = 9,i,h,m,s,t;
	clear();
	mvprintw(3,28,"R A N C K I N K");
	mvprintw(5, 10,"Numero de Discos : %d ", ndisco);
	mvprintw(5, 38," NIVEL : %s ", nivel);
	mvprintw(7, 16,"Pos");
	mvprintw(7, 25,"Nombre");
	mvprintw(7, 45,"Tiempo H:M:S");
	for(i = 0; i < P; i++)
	{
		//mvprintw(col + i, 2,"%d",i+1);
		mvprintw(col + i, 16,"%d",lista[i].posicion);
		mvprintw(col + i, 25,"%s", lista[i].nombre);
		t = lista[i].tiempo;
		h = t / 3600;
		t = t % 3600;
		m = t / 60;
		t = t % 60;
		s = t % 60;
		mvprintw(col + i, 45,"%d:%d:%d",h,m,s);
	}
	getch();
	if (opc == 1)
	{
		GuardarRancking(lista, disco);
	}
}

void GuardarRancking(Rancking *lista, char *disco)
{
	clear();
	int i;
	FILE *arch;
	printf("\nAbriendo el archivo...\n");
	if ((arch = fopen(disco, "w"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return;
	}

	printf("\nGuardando Profesores del catalogo\n");
	for (i=0; i < P; i++)
		fprintf(arch,"%d\t%s\t%d\n",lista[i].posicion,lista[i].nombre,lista[i].tiempo);
	fclose(arch);
}

void MandarImpress(Rancking *lista, int nd, int opm)
{
					switch(nd)
					{
						case 1:
							ImprimirRancking(lista, nd, opm, "./rancking1.exe", "Pincipiante");
						break;
						
						case 2:
							ImprimirRancking(lista, nd, opm, "./rancking2.exe", "Pincipiante");
						break;
						
						case 3:
							ImprimirRancking(lista, nd, opm, "./rancking3.exe", "Pincipiante");
						break;
						
						case 4:
							ImprimirRancking(lista, nd, opm, "./rancking4.exe", "Intermedio");
						break;
						
						case 5:
							ImprimirRancking(lista, nd, opm, "./rancking5.exe", "Intermedio");
						break;
						
						case 6:
							ImprimirRancking(lista, nd, opm, "./rancking6.exe", "Intermedio");
						break;
						
						case 7:
							ImprimirRancking(lista, nd, opm, "./rancking7.exe", "Avanzado");
						break;
						
						case 8:
							ImprimirRancking(lista, nd, opm, "./rancking8.exe", "Avanzado");
						break;
	}
}
