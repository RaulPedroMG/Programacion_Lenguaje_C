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
	char nom[15];
	Rancking lista[ML];
	time_t now,des;
    double DIF;
	int opm,nd,av2,dis;
	initscr();
	start_color();
	paleta_colores();
	//iniciando();
	do{
		bkgd(COLOR_PAIR(8));
		clear();
		Centrar("TORRES DE HANOI",1);
		opm=Menu1();
		switch(opm){
		case 1:
				bkgd(COLOR_PAIR(8));
				clear();
				titulo("Hanoi-0224",0,2,4);
				av2=AvisoConfirmacion("¿Leer instrucciones? s para leer,cualquier tecla para salir");
				if(av2==1){
					imprimirprese();
				}
				clear();
				titulo("Hanoi-0224",0,2,4);
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
				jugarha(nd,nom,&now,&des);
				DIF = difftime( des,now);
				LeeImpreRancking(lista, nd,opm);
				InsertarDato(lista,nom,DIF,nd);
				clear();
				MandarImpress(lista, nd, opm);
				break;
			case 2:
				clear();
				titulo("Ranking del juego de hanoi",2,3,5);
				mvprintw(8,6,"\tIntroduzca el número de disco del rancking que deesa ver : ");
				echo();
				scanw("%d",&dis);
				LeeImpreRancking(lista,dis, opm);
				break;
			case 3:
				break;
		}
		refresh();
		erase();
		m=0;
	}while(opm!=3);
	endwin();
	return 0;
}
