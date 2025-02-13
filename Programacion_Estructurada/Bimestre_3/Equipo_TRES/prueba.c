# include <ncurses.h>
#include "validanc.h"
#include "formato.h"
#include "estruct.h"
#define MAX 40
#define MM 11
int main ()
{
	Alumno lista[ML],auxi[ML];
	int total=0,opc,r;
	char nombre[MAX], aux[MAT],cad[MM];
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	//mvprintw(4,4,"T	mvprintw(12,12,"OPCIONES A REALIZAR");otal: %d",total);
	//getch();
	mvprintw(2,1,"ingrese su contraseña");
	LeeContra(cad,11,6,5);
	do{
		opc=menu();
		switch(opc){
			case 1:
				clear();
				InsertarOrd(lista,&total);
				break;
			case 2:
				clear();
				ImpDatos(lista,total);
				break;
			case 3:
				clear();
				mvprintw(2,1,"intruduce una matrícula");
				LeeMatricula(aux,5,15);
				r = Buscar(lista,total, aux);
				Imprimir(lista,r);
				break;
			case 4:
				clear();
				mvprintw(2,1,"intruduce una matrícula");
				LeeMatricula(aux,5,15);
				Eliminar(lista,&total, aux);
				break;
			case 5:
				clear();
				ModifiCalif(lista,total,aux);
				break;
			case 6:
				clear();
				OrdenCalif(lista,total,auxi);
				ImpDatos(auxi,total);
				break;
			case 7:
				clear();
				break;
		} 
	}while(opc!=7);
	//mvprintw(5,4,"Total: %d",total);
	//getch();
	endwin();
	return 0;
} 
