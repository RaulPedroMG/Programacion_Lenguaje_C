#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <time.h>
#include "torres.h"
#include "variables.h"
#include "pilas.h"
#include "formato.h"
#include "archivos.h"

int main()
{
	WINDOW *menubar,*messagebar;
	char nom[15];
	Ranking lista[ML];
	time_t now,des;
    double DIF;
	int opm,nd,av2,indice=0;
	initscr();
	start_color();
	paleta_colores();
	do{
		bkgd(COLOR_PAIR(8));
		clear();
		menubar=subwin(stdscr,1,80,0,0);
		messagebar=subwin(stdscr,1,19,13,1);
		draw_menubar(menubar);
		Centrar("TORRES DE HANOI",1);
		opm=Menu1();
		switch(opm){
		case 1:
				bkgd(COLOR_PAIR(8));
				clear();
				av2=AvisoConfirmacion("¿Leer instrucciones? s para leer,cualquier tecla para salir");
				if(av2==1){
					imprimirprese();
				}
				clear();
				mvprintw(7,10,"Ingresa tu nombre de jugador");
				LeeNombre(nom,15,7,40);
				mvprintw(10,10,"¿Con cuántos discos deseas jugar? 1-8 ");
				leerdiscos(&numdiscos);
				nd=numdiscos;
				todis=nd;
				erase();
				definir_planos();
				draw_planos();
				draw_torres();
				build_torres();
				iniciar_esquinas();
				pintar_torre();
				refresh();
				now = time(0);
				jugarha(nd,nom);
				des = time(0);
				DIF = difftime( des,now);
				ingresardatos(lista,nd,nom,DIF,&indice);
				GuardarEmp(lista,indice,"lis1.dat");
				ImprimirDatos(lista,&indice,"Nivel de principiantes");
				break;
			case 2:
				clear();
				break;
			case 3:
				break;
		}
		refresh();
		erase();
		m=0;
	}while(opm!=3);
	getch();
	endwin();
	return 0;
}
