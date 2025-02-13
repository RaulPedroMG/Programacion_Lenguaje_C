#include <stdio.h>
#include "Hanoi.h"
#include "ncurses.h"

int main()
{
	setlocale(LC_ALL," " );
	FILE *archivo;
	Rankin reg;//registra el nombre y tiempo 
	int disco=0,respuesta,res;
	initscr();
	IniciarColor();	
	attron(A_BOLD);
	do
	{
		attron(COLOR_PAIR(16));
		respuesta=Menu();
		clear();
		switch(respuesta)
		{
			case 1:
				do{
					  clear();
					  attron(COLOR_PAIR(13));
					  mvprintw(4,2,"Introduzca el número de discos con los que desea jugar:");
		              mvscanw(4,58,"%d",&disco);
					  attroff(COLOR_PAIR(13));
					  if(disco<=0 || disco>=9)
					  {
							clear();
							attron(COLOR_PAIR(14));
							Error("El rango de discos es de 1-8",20);
							attroff(COLOR_PAIR(14));
						}
					  else 
							JugarHanoi(disco,&reg);
							GuardarRanking(&reg,disco);	
	                }while(disco<=0 || disco>=9);
	                disco=0;				    
			break;
			case 2:
					archivo=fopen("Reglas.txt","r");
					CargarArchivo(archivo);
			break;
			case 3:
					res=0;
					do 
					{
						attron(COLOR_PAIR(16));
						res=Menu2();
						clear();
						switch(res)
						{
							case 1:
								mvprintw(2,2,"\nNivel 1\n\n");
								archivo=fopen("N1cd1.txt","r");
								CargarArchivo(archivo);
							break;
							case 2:
								mvprintw(2,2,"\nNivel 1\n\n");
								archivo=fopen("N1cd2.txt","r");
								CargarArchivo(archivo);
							break;
							case 3:
								mvprintw(2,2,"\nNivel 1\n\n");
								archivo=fopen("N1cd3.txt","r");
								CargarArchivo(archivo);
							break;
							case 4:
								mvprintw(2,2,"\nNivel 2\n\n");
								archivo=fopen("N2cd4.txt","r");
								CargarArchivo(archivo);
							break;
							case 5:
								mvprintw(2,2,"\nNivel 2\n\n");
								archivo=fopen("N2cd5.txt","r");
								CargarArchivo(archivo);
							break;
							case 6:
								mvprintw(2,2,"\nNivel 2\n\n");
								archivo=fopen("N2cd6.txt","r");
								CargarArchivo(archivo);
							break;
							case 7:
								mvprintw(2,2,"\nNivel 3\n\n");
								archivo=fopen("N3cd7.txt","r");
								CargarArchivo(archivo);
							break;
							case 8:
								mvprintw(2,2,"\nNivel 3\n\n");
								archivo=fopen("N3cd8.txt","r");
								CargarArchivo(archivo);
							break;
							case 9: 
								attron(COLOR_PAIR(10));
								mvprintw(2,12,"Saliendo del Ranking....");
								attroff(COLOR_PAIR(10));
							break;
							default :	
								attron(COLOR_PAIR(10));
								Error("opcion incorrecta",10);
								attroff(COLOR_PAIR(10));
					}
					attroff(COLOR_PAIR(16));
					getch();
					}while(res!=9);
					refresh();
			break;
			case 4:
					archivo=fopen("Leyenda.txt","r");
					CargarArchivo(archivo);
			break;		
			case 5:
					archivo=fopen("Creditos.txt","r");
					CargarArchivo(archivo);
			break;
			case 6: 
					attron(COLOR_PAIR(10));
					mvprintw(2,12,"Saliendo de la aplicacion....");
					attroff(COLOR_PAIR(10));
			break;
			default :	
						attron(COLOR_PAIR(10));
						Error("opcion incorrecta",10);
						attroff(COLOR_PAIR(10));
		}
		attroff(COLOR_PAIR(13));
		getch();
	}while(respuesta!=6);
	attroff(A_BOLD);
	refresh();
	endwin();
	return 0;
}
