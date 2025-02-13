# include <ncurses.h>
#include "validanc.h"
#include "formato.h"
#include "estruct.h"
#define MAX 10

int main ()

{
	Alumno lista[ML];
	Alumno aux_l[ML];
	int total=0, i; 
	int opc, cont2[ML], x;
	char aux[MAT];
	
	clear();
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	do
	{
	
		opc = menu();
/*		
		mvprintw(2,2,"        ***MENÚ***    ");
		mvprintw(4,4,"1:Llenar lista");
		mvprintw(6,4,"2:Imprimir lista");
		mvprintw(8,4,"3:Buscar el mayor");
		mvprintw(10,4,"4:Buscar el menor");
		mvprintw(12,4,"5:Buscar aprobados");
		mvprintw(14,4,"6:Buscar reprobados");
		mvprintw(16,4,"7:Insertar otro dato para la lista");
		mvprintw(18,4,"8:Buscar un dato lista");
		mvprintw(20,4,"9:Eliminar un registro");
		mvprintw(22,4,"10:Modificar Calificación");
		mvprintw(24,4,"11:Ordenar Calificación");
		mvprintw(26,4,"12:Salir");
		mvprintw(30,2,"¿Qué desea hacer?");
		mvscanw(31,2,"%d",&opc);
*/		
		if (opc > 0 && opc < 12)
		{
			switch (opc)
			{
				case 1: 
					//mvprintw(4,4,"Total: %d",total);
					//getch();
					LeeDatos(lista,&total);
				break;
				
				case 2:	
					//mvprintw(5,4,"Total: %d",total);
					//getch();
					ImpDatos(lista,total);
				break;
				
				case 3:
					BuscarMayor(lista, total, cont2, &x);
					ImprimirVector(lista, cont2, x);
				break;
				
				case 4:
					BuscarMenor(lista, total, cont2, &x);
					ImprimirVector(lista, cont2, x);
				break;
				
				case 5:
					BuscarAprobados(lista, total, cont2, &x);
					ImprimirVector(lista, cont2, x);
				break;
				
				case 6:
					BuscarReprobados(lista, total, cont2, &x);
					ImprimirVector(lista, cont2, x);
				break;
					
				case 7:
					InsertarOrd(lista, &total);
				break;
				
				case 8:
					LeeMatricula(aux,5,15);
					i = Buscar(lista, &total, aux);
					imprimir (lista, i);
				break;
				
				case 9:
					LeeMatricula(aux,5,15);
					Eliminar(lista,&total, aux);
				break;	
				
				case 10:
					ModifiCalif ( lista, total, aux);
				break;	
				
				case 11:
					OrdenCalif ( lista, total, aux_l);
					
				break;	
					
			}
		}
		else
		{
				mvprintw(32,2,"Tu opción es inválida");
		}
	}while (opc != 12);
	
	
	endwin();

	return 0;
} 
