# include <ncurses.h>
#include "validanc.h"
#include "formato.h"
#include "estruct.h"
#define MAX 40

int main ()
{	
	FILE *arch;
	Empresa catemp[100];
	int totalemp=0;
	char cad[450];
	Alumno lista[ML];
	int total=0, opcion;
	//char nombre[MAX];
	
	initscr();
	keypad(stdscr, TRUE);
	
	 if ((arch = fopen("./empresas3.txt", "r"))	 == NULL)
	 {
			fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			return 1;
	 }

	while (!feof(arch))
	{
		if (fgets(cad,449,arch) != NULL)
		{
			printf("\nRegistro %d",totalemp+1);
			printf("\ncad: <<%s>>",cad);
			SeparaCad(catemp,&totalemp,cad);
		}
	}
	fclose(arch);
	do
	{
		initscr();
		keypad(stdscr, TRUE);
		noecho();
		clear();
		Centrar("Abriendo el archivo...",2);
		mvprintw(4,2,"\n\t\tFIN del archivo...");
		opcion = MenuP ();
		if(opcion>=1 && opcion <=6)
		{
			switch (opcion)
			{
				case 1: clear();
						Empresas(catemp, totalemp);
					break;
				
				case 2:  clear();
						Alumnos();
					break;
		
				case 3: clear();
						Profesores ();
					break;
		
				case 4: Visitas();
					break;
			
				case 5: Estancias();
					break;
			
				case 6: Servicios();
					break;
			}
			
		}
		if(opcion < 1 || opcion > 7 )
		{
			Error("\tError, opción inválida",20);
		}				
	}while(opcion != 7);
	//mvprintw(4,4,"Total: %d",total);
	//getch();
	//LeeDatos(lista,&total);
	//mvprintw(5,4,"Total: %d",total);
	//getch();
	/*ImpDatos(lista,total);*/
	
	
	
	endwin();
	return 0;
} 
