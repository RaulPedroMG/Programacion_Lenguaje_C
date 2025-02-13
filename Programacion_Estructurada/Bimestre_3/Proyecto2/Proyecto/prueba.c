/*
 * Nombre:principal.c
 * Descripción:Es el programa principal y tiene la finalidad de llamar
 *  a todas las funciones que se utilizan en el programa.
 * autor:Equipo 1
*/
#include <ncurses.h>
#include "validanc.h"
#include "formato.h"
#include "estruct.h"

	
	
	
int main ()
{
	Empresa catemp[ML];
	int totalemp=0;
	Alumno catalumn[ML];
	int totalalumn=0, opcion;
	Profesor catprofe[ML];
	//Visita lisvisita[ML];
	int totalprofe=0;//,totalvisita=0;
	char nombre[MAX];
	LeerArchivo(catemp, &totalemp);
	LeerArchivoAlumn(catalumn, &totalalumn);
	LeerArchivoProfe(catprofe, &totalprofe);
	//LeerArchivoVisita(lisvisita, &totalvisita);
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
						Empresas(catemp, &totalemp);
					break;
				
				case 2:  clear();
						Alumnos(catalumn, &totalalumn);
					break;
		
				case 3: clear();
						Profesores (catprofe, &totalprofe);
					break;
		
				case 4: clear();
						Visitas();//lisvisita,&totalvisita,catprofe,&totalprofe,catemp,&totalemp);
					break;
			
				case 5: Estancias();
					break;
			
				case 6: Servicios();
					break;
			}
			
		}
		if(opcion < 1 || opcion > 7 )
		{
			Error("\tError, opción inválida",22);
		}
		GuardarEmpText(catemp,totalemp);
		GuardarAlumText(catalumn,totalalumn);
		GuardarProfeText(catprofe,totalprofe);				
	}while(opcion != 7);
	endwin();
	return 0;
} 
