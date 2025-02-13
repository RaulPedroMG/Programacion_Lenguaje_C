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

void jugarha(int numdis,char nom[15],time_t *now,time_t *des)
{
	char a='a', b='b',c='c';
	Pila p1,p2,p3;
	int i,mv=2,band=0,tin=0,nunv=0,aux,aux2,aux3,tor,tor1;
	PilaVacia(&p1);
	PilaVacia(&p2);
	PilaVacia(&p3);
	for (i=numdis-1; i>=0;i--){
        Push(i,&p1);
    }
    for(i=1;i<numdis;i++){
		mv=mv*2;
	}
	mv--;
	while(band==0){
		echo();
		refresh();
		Centrar("JUEGO LAS TORRES DE HANOI",1);
		mvprintw(2,50,"Player: %s ",nom);
		mvprintw(filas+3,24,"Mínimo de movimientos %d ",mv);
       	mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
		echo();
		imtorres(numdis);
		leertorre(&tor,6,"Mover disco de torre ");
		if(tin==0){
			*now=time(0);
			tin=1;
		}
		leertorre(&tor1,7,"A   la   torre ");
		if(tor==tor1){
			Error("Moviemiento no válido",filas+10);
			mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
		}else{
			switch(tor){
				case 1:
					if(tor1==2){
						//ponersac(p1,p2,a,b,nunv);
						if(!EsVacia(&p1)){
							if(EsVacia(&p2)){
								aux3=Pop(&p1);
								Push(aux3,&p2);
								show_hanoi(a%97,b%97);
							}else{
								if(!EsVacia(&p2)){
									aux=Cima(p1);
									aux2=Cima(p2);
									if(aux<aux2){
										aux3=Pop(&p1);
										Push(aux3,&p2);
										show_hanoi(a%97,b%97);
									}else{
										echo();
										Error("Moviemiento no valido",filas+15);
									}
								}
							}
						}else{
							echo();
							Error("Moviemiento no valido",filas+15);
						}
					}else{
						if(!EsVacia(&p1)){
							if(EsVacia(&p3)){
								aux3=Pop(&p1);
								Push(aux3,&p3);
								show_hanoi(a%97,c%97);
							}else{
								if(!EsVacia(&p3)){
									aux=Cima(p1);
									aux2=Cima(p3);
									if(aux<aux2){
										aux3=Pop(&p1);
										Push(aux3,&p3);
										show_hanoi(a%97,c%97);
									}else{
										echo();
										Error("Moviemiento no valido",filas+15);
									}
								}
							}
						}else{
							echo();
							Error("Moviemiento no valido",filas+15);
						}
					}
					break;
				case 2:
					if(tor1==1){
						if(!EsVacia(&p2)){
							if(EsVacia(&p1)){
								aux3=Pop(&p2);
								Push(aux3,&p1);
								show_hanoi(b%97,a%97);
							}else{
								if(!EsVacia(&p1)){
									aux=Cima(p2);
									aux2=Cima(p1);
									if(aux<aux2){
										aux3=Pop(&p2);
										Push(aux3,&p1);
										show_hanoi(b%97,a%97);
									}else{
										Error("Moviemiento no valido",filas+15);
									}
								}
							}
						}else{
							Error("Moviemiento no valido",filas+15);
						}
					}else{
						if(!EsVacia(&p2)){
							if(EsVacia(&p3)){
								aux3=Pop(&p2);
								Push(aux3,&p3);
								show_hanoi(b%97,c%97);
							}else{
								if(!EsVacia(&p3)){
									aux=Cima(p2);
									aux2=Cima(p3);
									if(aux<aux2){
										aux3=Pop(&p2);
										Push(aux3,&p3);
										show_hanoi(b%97,c%97);
									}else{
										echo();
										Error("Moviemiento no valido",filas+15);
									}
								}
							}
						}else{
							echo();
							Error("Moviemiento no valido",filas+15);
						}
					}
					break;
				case 3:
					if(tor1==1){
						if(!EsVacia(&p3)){
							if(EsVacia(&p1)){
								aux3=Pop(&p3);
								Push(aux3,&p1);
								show_hanoi(c%97,a%97);
							}else{
								if(!EsVacia(&p1)){
									aux=Cima(p3);
									aux2=Cima(p1);
									if(aux<aux2){
										aux3=Pop(&p3);
										Push(aux3,&p1);
										show_hanoi(c%97,a%97);
									}else{
										Error("Moviemiento no valido",filas+15);
									}
								}
							}
						}else{
							echo();
							Error("Moviemiento no valido",filas+15);
						}
					}else{
						if(!EsVacia(&p3)){
							if(EsVacia(&p2)){
								aux3=Pop(&p3);
								Push(aux3,&p2);
								show_hanoi(c%97,b%97);
							}else{
								if(!EsVacia(&p2)){
									aux=Cima(p3);
									aux2=Cima(p2);
									if(aux<aux2){
										aux3=Pop(&p3);
										Push(aux3,&p2);
										show_hanoi(c%97,b%97);
									}else{
										Error("Moviemiento no valido",filas+15);
									}
								}
							}
						}else{
							Error("Moviemiento no valido",filas+15);
						}
					}
					break;
			}//llave de casos
		}
		nunv++;
		mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
		if(EsVacia(&p1)==1){
			if(EsVacia(&p2)==1){
				band=1;
				*des=time(0);
				echo();
				//refresh();
				Centrar("Ganaste",14);
				Centrar(nom,16);
			}
		}
		if(EsVacia(&p1)==1){
			if(EsVacia(&p3)==1){
				band=1;
				*des=time(0);
				echo();
				//refresh();
				Centrar("Ganaste",14);
				Centrar(nom,16);
			}
		}
	}
	Error("Presiona una tecla para salir",filas+11);
}

void imtorres(int numdis){
	if(numdis==1){
			mvprintw(filas+1,2,"Torre 1   Torre 2  Torre  3");
	}
	if(numdis==2){
		mvprintw(filas+1,2,"Torre 1    Torre 2   Torre  3");
	}
	if(numdis==3){
		mvprintw(filas+1,4,"Torre 1       Torre 2      Torre  3");
	}
	if(numdis==4){
		mvprintw(filas+1,5,"Torre 1        Torre 2       Torre  3");
	}
	if(numdis==5){
		mvprintw(filas+1,6,"Torre 1          Torre 2         Torre  3");
	}
	if(numdis==6){
		mvprintw(filas+1,7,"Torre 1          Torre 2         Torre  3");
	}
	if(numdis==7){
		mvprintw(filas+1,8,"Torre 1            Torre 2             Torre  3");
	}
	if(numdis==8){
		mvprintw(filas+1,9,"Torre 1               Torre 2              Torre  3");
	}
}

void leerdiscos(int *numdiscos)
{
	int band=0;
	do{
		mvprintw(10,49,"      ");
		*numdiscos=LeeInt(10,50);
		if(*numdiscos>=1 && *numdiscos<=8){
			band=1;
		}else{
			Error("Número de discos no valido",filas+15);	
		}
	}while(band!=1);
}
void leertorre(int *tor,int i,char *me)
{
	int band=0;
	do{
		refresh();
		mvprintw(filas+i,24," %s ",me);
		mvprintw(filas+i,48,"        ");
		*tor=LeeInt(filas+i,48);
		if(*tor>=1 && *tor<=3){
			band=1;
		}else{
			Error("Número de torre no valido",filas+15);	
		}
	}while(band!=1);
}

/*Bloque de módulos genarar una torre indice de donde se puede seleccionar un nivel e imprimirlo.*/
void definir_planos(void)
{
	int i;
	//planostorres es una matriz y contiene el numero de discos mas 2
	planostorres=(int**)calloc(numdiscos+2, sizeof(int*));

	for(i=0;i<=numdiscos+1;i++)
		*(planostorres+i)=(int*)calloc(2, sizeof(int));
}

void draw_planos()
{
	int i,j, caracteres=2, espacios=numdiscos+1;

	for(i=0;i<=numdiscos+1;i++){
	  for(j=0;j<2;j++){
		if(j==0){
			planostorres[i][j]=espacios;		 
			espacios--;
		}else{  				
		  	planostorres[i][j]=caracteres;
		  	caracteres=caracteres+2;
		}
	   }		
	}
}

void draw_torres(void)
{
	int i,j,numcaracteres,centrov1,centrov2;
	
	torre=(char**)calloc(numdiscos+2, sizeof(char*));

	for(i=0;i<=numdiscos;i++){
		numcaracteres=i*2+2;
		*(torre+i)=(char*)calloc(numcaracteres, sizeof(char));
	}

	*(torre+i)=(char*)calloc(numcaracteres+4, sizeof(char));
	
	for(i=0;i<(numdiscos+1)*2+2;i++)
		torre[numdiscos+1][i]=' ';
	torre[numdiscos+1][i]='\0';
	
	for(i=0;i<=numdiscos;i++){
	 	 //Añadir Espacios
		numcaracteres=i*2+2;
		centrov1=i;
	  	centrov2=i+1;
			  	
	  	for(j=0;j<numcaracteres;j++){
  			if((j==centrov1 || j==centrov2)&&i==0){
 				torre[i][j]=' ';
 			}else{
				torre[i][j]=' ';
			}
	  	}
	  	torre[i][j]='\0';
	}	 
}

void iniciar_esquinas(void)
{
	esquinaA=2;
	esquinaB=esquinaA+planostorres[numdiscos][1]+D;
	esquinaC=esquinaB+planostorres[numdiscos][1]+D;
}

void pintar_torre(void)
{
	int i;
	filas=4;
	
	//Imprimiendo niveles superiores .
	for(i=0;i<=numdiscos;i++)
		{
		imprimir_nivel(torres[i][0],filas,esquinaA+planostorres[torres[i][0]][0]);	//TorreA	
		imprimir_nivel(torres[i][1],filas,esquinaB+planostorres[torres[i][1]][0]);	//TorreB
		imprimir_nivel(torres[i][2],filas,esquinaC+planostorres[torres[i][2]][0]);	//TorreC
		filas++;
		}

	//Imprimiendo nivel base.
	imprimir_nivel(numdiscos+1,filas, esquinaA);
	imprimir_nivel(numdiscos+1,filas, esquinaB);
	imprimir_nivel(numdiscos+1,filas, esquinaC);
}

void show_hanoi(int origen, int destino)
{
	if(origen==0)
	  {
	  switch(destino)
		{
		case 1:
		mover_disco(origen, destino,&topeA,&topeB);
		break;
					  
		case 2:
		mover_disco(origen, destino,&topeA,&topeC);
		break;
		}
	  }
		  
	if(origen==1)
	  {
	  switch(destino)
		{
		case 0:
		  mover_disco(origen, destino,&topeB,&topeA);
		break;
			  
		case 2:
		  mover_disco(origen, destino,&topeB,&topeC);
		break;
		}
	  }
		  
	if(origen==2)
	  {
	  switch(destino)
		{
		case 0:
			mover_disco(origen, destino,&topeC,&topeA);
		break;
			  
		case 1:
		  mover_disco(origen, destino,&topeC,&topeB);
		break;
		}
	  }
}

void paleta_colores(void)
{
	if (has_colors()){
		init_pair(1,COLOR_RED,COLOR_GREEN);
		init_pair(2,COLOR_RED,COLOR_MAGENTA);
		init_pair(3,COLOR_RED,COLOR_CYAN);
		init_pair(4,COLOR_BLACK,COLOR_RED);
		init_pair(5,COLOR_BLACK,COLOR_BLUE);
		init_pair(6,COLOR_RED,COLOR_YELLOW);
		init_pair(7,COLOR_WHITE,COLOR_BLACK);
		init_pair(8,COLOR_BLUE,COLOR_WHITE);
		}
}

void mover_disco(int x_origen, int x_destino, int* topeOrigen, int* topeDestino)
{
  int auxiliar;
  
  /*Aquí se quita el disco de la torre de origen*/
	m++;
	pintar_torre();
	refresh();
	erase();

	auxiliar=torres[*topeOrigen][x_origen];
	torres[*topeOrigen][x_origen]=0;	
	pintar_torre();
	refresh();
	erase();
	*topeOrigen=*topeOrigen+1;
	/*Aquí añade el disco a la torre de destino*/
	*topeDestino=*topeDestino-1;
	torres[*topeDestino][x_destino%3]=auxiliar;
	pintar_torre();
	refresh();
}

void	imprimir_nivel(int nivel, int fila,int columnas)
{
		int color=nivel%6+1;
		
		if(nivel==0 || nivel==numdiscos+1)
			{
			color=7;
			}			
		attron(COLOR_PAIR(color));
		mvprintw(fila, columnas,"%s", torre[nivel]);
		attroff(COLOR_PAIR(color));
}
void imprimirprese(void ){
		Centrar("BIENVENIDOS AL JUEGO DE LAS TORRES DE HANOI",1);
		Centrar("INSTRUCCIONES",3);
		Centrar("Debes pasar todos los discos de la torre 1",5);
		Centrar("a cualquiera de  las torres (torre2, torre3)",7);
		Centrar("ojo, deben de estar en el mismo orden que al principio",8);
		Centrar("evitando poner un disco de mayor tamaño sobre uno de menor tamaño.",9);
		Centrar("Puedes auxiliarte de las torres 2 y 3 ",11);
		Centrar("para hacer los movimientos que consideres necesarios.",13);
		Centrar("*****************************************************************************",17);		
		Centrar("Presione una tecla para continuar",20);
		getch();
}

void draw_menubar(WINDOW *menubar)
{
    wbkgd(menubar,COLOR_PAIR(6));
    waddstr(menubar,"LICENCIATURA EN INFORMATICA");
    wattron(menubar,COLOR_PAIR(5));
    wattroff(menubar,COLOR_PAIR(5));
    wmove(menubar,0,0);
}

void	build_torres(void)
{
	int i,j;
	torres=(int**)calloc(numdiscos+1, sizeof(int*));

	for(i=0;i<=numdiscos;i++)
		*(torres+i)=(int*)calloc(3, sizeof(int));

	for(i=0;i<=numdiscos;i++)
	  {
	  for(j=0;j<3;j++)
		{
		if(j==0)
		  	torres[i][j]=i;
		else  				
			torres[i][j]=0;		 
		}
}	  
	/*Inicializando Topes*/
	topeA=1;
	topeB=numdiscos+1;
	topeC=numdiscos+1;
}
