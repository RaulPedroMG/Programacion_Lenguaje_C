#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <time.h>
#define D 5
#define MAX 8
#define RET 127
#define ENT 10

typedef struct{
int arreglo[MAX];
int tope;
}Pila;

void PilaVacia (Pila *a);
int EsVacia (Pila *a);
int Cima (Pila a);
void Push (int x, Pila *a);
int Pop (Pila *a); 

void llenarpila(Pila *p1);

void Centrar(char *cad, int r);

void Derecha(char *cad, int r);

void Error(char *cad, int r);
void LeeEntero(char *cad,int max,int r, int c);
int LeeInt(int r, int c);

/*Declaración de funciones y procedimientos*/
void Hanoi(char a,char b, char c,int n);
void build_torres(void);/*En esta función se crea una matriz de Nfilas x 3columnas la cual simula el juego de las torres de hanoi.*/
void mover_disco(int x_origen, int x_destino, int* topeOrigen, int* topeDestino);
/*Este bloque de módulos genara una torre indice de donde se puede seleccionar un nivel y imprimirlo.*/
void definir_planos(void);
void draw_planos(void);
void draw_torres(void);

void jugarha(int *numdiscos,char nom[15]);
/*Esta funciones imprimen las torres*/
void show_hanoi(int origen, int destino);
void pintar_torre(void);
void imprimir_nivel(int nivel, int fila, int columna);
void iniciar_esquinas(void);
void paleta_colores(void);
void mensaje(int estado);
void leerdiscos(int *numdiscos);
void LeeNombre(char *cad,int max,int r, int c);
void leertorre(int *tor);
/*Declaración de variables globales*/
int **torres, topeA, topeB, topeC;
int m=0;

/*Declaración de variables globales*/
char **torre;
int **planostorres, numdiscos, filas, columnas;
int esquinaA, esquinaB,esquinaC;
/*Variables de los mensajes*/
char origen, destino;
int disco;

int main()
{
	char a='a', b='b',nom[15], c='c',tor,tor1;
	int opc,aux,i;
	initscr();
	start_color();
	paleta_colores();
	do{
		bkgd(COLOR_PAIR(8));
		//̣erase();
		Centrar("BIENVENIDOS AL JUEGO DE LAS TORRES DE HANOI",0);
		printw("\n\n\t\t\t\t INSTRUCCIONES\n");
		printw("\n\t\t Debes pasar los discos de la torre 1 \n \t\t a cualquiera de  las torres (torre2, torre3)\n \t\t evitando poner un disco de menor tamaño \n\t\t debajo de otro de mayor tamaño.\n");
		printw("\n\t\t Puedes auxiliarte de las torres 2 y 3 \n \t\t para hacer los movimientos que consideres necesarios.\n\n");		
		Centrar("Presione una tecla para continuar",20);
		getch();
		clear();
		mvprintw(7,10,"Ingresa tu nombre de jugador");
		LeeNombre(nom,15,7,40);
		mvprintw(10,10,"¿Con cuantos discos deseas jugar? 1 -8 ");
		//scanw("%d",&numdiscos);
		leerdiscos(&numdiscos);
		erase();
		definir_planos();
		draw_planos();
		draw_torres();
		build_torres();
		iniciar_esquinas();
		
		//mvprintw(1,0,"INICIO");
		pintar_torre();
		//mensaje(0);
		//sleep(1);
		refresh();
		//erase();
		jugarha(&numdiscos,nom);
		mvprintw(filas+3,0,"¿Desea jugar de nuevo?\n1.Si\n2.No\n");
		scanw("%d",&opc);
		refresh();
		erase();
		m=0;
	}while(opc==1);
	getch();
	endwin();
	return 0;
}

void jugarha(int *numdiscos,char nom[15])
{
	char a='a', b='b',c='c';
	Pila p1,p2,p3;
	int i,mv=2,nunv=0,aux,aux2,aux3,band=0,tor,tor1;
	PilaVacia(&p1);
	PilaVacia(&p2);
	PilaVacia(&p3);
	for (i=8; i>0;i--){
        Push(i,&p1);
    }
    for(i=1;i<*numdiscos;i++){
		mv=mv*2;
	}
	mv--;
	do{
		echo();
		refresh();
		Centrar("BIENVENIDOS AL JUEGO DE LAS TORRES DE HANOI",0);
		mvprintw(2,50,"Player: %s ",nom);
		mvprintw(filas+3,24,"Mínimo de movimientos %d ",mv);
		mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
		echo();
		if(EsVacia(&p1)==1 && EsVacia(&p2)==1){
			band=1;
			echo();
			refresh();
			mvprintw(filas+5,30,"GAME OVER");
		}else{
			if(EsVacia(&p1)==1 && EsVacia(&p3)==1){
				band=1;
				echo();
				refresh();
				mvprintw(filas+5,30,"GAME OVER");
			}
		}
		leertorre(&tor);
		leertorre(&tor1);
		if(tor==tor1){
			//echo();
			Error("Moviemiento no válido",filas+10);
			//nunv++;
			mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
		}else{
			switch(tor){
				case 1:
					if(tor1==2){
						if(!EsVacia(&p1)){
							if(EsVacia(&p2)){
								aux3=Pop(&p1);
								Push(aux3,&p2);
					//			refresh();
				//				echo();
								//nunv++;
								show_hanoi(a%97,b%97);
								mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
							}else{
								if(!EsVacia(&p2)){
									aux=Cima(p1);
									aux2=Cima(p2);
									if(aux<aux2){
										aux3=Pop(&p1);
										Push(aux3,&p2);
						//				refresh();
							//			echo();
										//nunv++;
										show_hanoi(a%97,b%97);
										mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
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
								//refresh();
								//echo();
								//nunv++;
								show_hanoi(a%97,c%97);
								mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
							}else{
								if(!EsVacia(&p3)){
									aux=Cima(p1);
									aux2=Cima(p3);
									if(aux<aux2){
										aux3=Pop(&p1);
										Push(aux3,&p3);
									//	refresh();
										//echo();
										//nunv++;
										show_hanoi(a%97,c%97);
										mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
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
								//refresh();
								//echo();
								//nunv++;
								show_hanoi(b%97,a%97);
								mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
							}else{
								if(!EsVacia(&p1)){
									aux=Cima(p2);
									aux2=Cima(p1);
									if(aux<aux2){
										aux3=Pop(&p2);
										Push(aux3,&p1);
									//	refresh();
									//	echo();
										//nunv++;
										show_hanoi(b%97,a%97);
										mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
									}else{
										//echo();
										Error("Moviemiento no valido",filas+15);
									}
								}
							}
						}else{
							//echo();
							Error("Moviemiento no valido",filas+15);
						}
					}else{
						if(!EsVacia(&p2)){
							if(EsVacia(&p3)){
								aux3=Pop(&p2);
								Push(aux3,&p3);
								//refresh();
								//echo();
								//nunv++;
								show_hanoi(b%97,c%97);
								mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
							}else{
								if(!EsVacia(&p3)){
									aux=Cima(p2);
									aux2=Cima(p3);
									if(aux<aux2){
										aux3=Pop(&p2);
										Push(aux3,&p3);
										//refresh();
										//echo();
										//nunv++;
										show_hanoi(b%97,c%97);
										mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
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
								//refresh();
								//echo();
								//nunv++;
								show_hanoi(c%97,a%97);
								mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
							}else{
								if(!EsVacia(&p1)){
									aux=Cima(p3);
									aux2=Cima(p1);
									if(aux<aux2){
										aux3=Pop(&p3);
										Push(aux3,&p1);
										//refresh();
										//echo();
										//nunv++;
										show_hanoi(c%97,a%97);
										mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
									}else{
										//echo();
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
								//refresh();
								//echo();
								//nunv++;
								show_hanoi(c%97,b%97);
								mvprintw(filas+4,24,"Movimientos realizados %d ",nunv);
							}else{
								if(!EsVacia(&p2)){
									aux=Cima(p3);
									aux2=Cima(p2);
									if(aux<aux2){
										aux3=Pop(&p3);
										Push(aux3,&p2);
									//	refresh();
										//echo();
										//nunv++;
										show_hanoi(c%97,b%97);
										mvprintw(filas+4,24,"Movimientos realizados  %d ",nunv);
									}else{
										//echo();
										Error("Moviemiento no valido",filas+15);
									}
								}
							}
						}else{
							//echo();
							Error("Moviemiento no valido",filas+15);
						}
					}
					break;
			}//llave de casos
		}
	nunv++;
	}while(band!=1);
}
void leerdiscos(int *numdiscos)
{
	int band=0;
	do{
		*numdiscos=LeeInt(10,50);
		if(*numdiscos>=1 && *numdiscos<=8){
			band=1;
		}
	}while(band!=1);
}
void leertorre(int *tor)
{
	int band=0;
	do{
		refresh();
		mvprintw(filas+6,24,"Ingresa numero de torre");
		mvprintw(filas+6,48,"        ");
		*tor=LeeInt(filas+6,48);
		if(*tor>=1 && *tor<=8){
			band=1;
		}
	}while(band!=1);
}
void Hanoi(char a,char b, char c,int n)
{
	if(n==1)
	{
	  /*Definiendo variables del mensaje:*/
	  origen=a-32;
	  destino=c-32;
	  disco=n;
	  show_hanoi(a%97,c%97);
	}
	else
	{
		Hanoi(a, c, b, n-1);
		origen=a-32;
		destino=c-32;
		disco=n;
		show_hanoi(a%97,c%97);
		refresh();
		erase();
		Hanoi(b, a, c, n-1);
	}
}

void llenarpila(Pila *p1)
{
	int i;
	for(i=numdiscos;i<0;i--){
	}
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

void mensaje(int estado)
{
	if(m>0)
	{
	  if(estado!=2)
	  	mvprintw(0,0,"Movimiento %d", m);

	switch(estado)
		{
		case 0:
		mvprintw(1,0,"Quitando el disco %d de la Torre %c",disco,origen);				
		break;

		case 1:			
		mvprintw(1,0,"Poniendo el disco %d en la torre %c",disco, destino);
		break;
		
		case 2:			
		mvprintw(0,0,"Movimiento %d terminado", m);
		break;
		}
	}
	
	mvprintw(filas+1,esquinaA+planostorres[torres[0][0]][0]," A");
	mvprintw(filas+1,esquinaB+planostorres[torres[0][1]][0]," B");
	mvprintw(filas+1,esquinaC+planostorres[torres[0][1]][0]," C");
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
	//mensaje(0);
	pintar_torre();
	//sleep(1);
	refresh();
	erase();

	auxiliar=torres[*topeOrigen][x_origen];
	torres[*topeOrigen][x_origen]=0;
	//mensaje(1);	
	pintar_torre();
	//sleep(1);
	refresh();
	erase();
	*topeOrigen=*topeOrigen+1;
	/*Aquí añade el disco a la torre de destino*/
	*topeDestino=*topeDestino-1;
	torres[*topeDestino][x_destino%3]=auxiliar;
	//mensaje(2);
	pintar_torre();
	//sleep(1);
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

void LeeNombre(char *cad,int max,int r, int c)
/*Descripci¢n: Este procedimiento permite capturar un nombre, validando
 *caracter por caracter, solo se permiten letras del alfabeto en ingls
 *y espacios en blanco.
*/
{
	int aux;
	int ind, band;
	noecho();
	keypad(stdscr, TRUE);
	ind = band =0;
	while (!band && ind < max -1){
		do{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isalpha(aux));
		switch(aux){
			case ENT://retorno de carro
					if(ind>0){
						band = 1;
						cad[ind] = '\0';
					}
					break;
			case RET://backspace <--  retroceso
				if (ind > 0){
					ind--;
					move(r,c+ind);
					printw(" ");
					move(r,c+ind);
				}
				break;
			default :		
				if(ind==0){
					cad[ind] = toupper(aux);
					aux=toupper(aux);
					move(r,c+ind);
					printw("%c",aux);
					ind++;
				}else{
					cad[ind] = aux;
					move(r,c+ind);
					printw("%c",aux);
					ind++;
				}
		}
	}
	if (ind == max -1){
		//move(r+1,c);
		//Error("Tamaño maximo de la cadena alcanzado",11);
		mvprintw(r+1,c,"Tamaño maximo de la cadena alcanzado");
		cad[ind] = '\0';
	}

}


void LeeEntero(char *cad,int max,int r, int c)
{
	int aux;
	int ind, band;
	noecho();
	keypad(stdscr, TRUE);
	ind = band =0;
	while (!band && ind < max -1){
		do{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isdigit(aux));
		switch(aux){
			case ENT:
								band = 1;
								cad[ind] = '\0';
								break;
			case RET:
								if (ind > 0)
								{
									ind--;
									move(r,c+ind);
									printw(" ");
									move(r,c+ind);
								}
								break;
			default :
								cad[ind] = aux;
								move(r,c+ind);
								printw("%c",aux);
								ind++;
		}
	}
	if (ind == max -1)
		cad[ind] = '\0';
}


int LeeInt(int r, int c)
{
	char cad[12];
	int valor;
	LeeEntero(cad,12,r,c);
	valor = atoi(cad);
	return valor;
}

void Centrar(char *cad, int r)
{
	int ren,col;
	getmaxyx(stdscr, ren, col);
	col = (col / 2) - (strlen(cad) / 2);
	mvprintw(r,col,"%s",cad);
}

void Derecha(char *cad, int r)
{
	int ren,col;
	getmaxyx(stdscr, ren, col);
	col = col- strlen(cad);
	mvprintw(r,col,"%s",cad);
}

void Error(char *cad, int r)
{
	int ren,col,i;
	getmaxyx(stdscr, ren, col);
	col = (col / 2) - (strlen(cad) / 2);
	attron(A_BLINK);
	mvprintw(r,col,"%s",cad);
	getch();
	attroff(A_BLINK);
	for (i=0;i<strlen(cad);i++)
		mvprintw(r,col+i,"  ");
	
}

void PilaVacia (Pila *a){
	a->tope=-1;
}
     
int EsVacia (Pila *a){
  if (a->tope==-1)
     return 1;
  else
     return 0;  
}
     
int Cima (Pila a){
	if (!EsVacia(&a))
		return a.arreglo[a.tope];
	else
		printf("PILA VACIA\n");
}


void Push (int x, Pila *a){
	if (a->tope==MAX-1)
		printf("PILA LLENA\n");
	else {         
		a->tope++;
		a->arreglo[a->tope]=x;
	}   
}
     
int Pop (Pila *a){
	int aux;
	if (EsVacia(a))
		printf ("PILA VACIA\n");
	else{
		aux=a->arreglo[a->tope];
		a->tope--;
		return aux;
	}    
}
