#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>	
#define D 5
/*Declaración de funciones y procedimientos*/
void Hanoi(char a,char b, char c,int n);
void build_torres(void);/*En esta función se crea una matriz de Nfilas x 3columnas la cual simula el juego de las torres de hanoi.*/
void mover_disco(int x_origen, int x_destino, int* topeOrigen, int* topeDestino);
/*Este bloque de módulos genara una torre indice de donde se puede seleccionar un nivel y imprimirlo.*/
void definir_planos(void);
void draw_planos(void);
void draw_torres(void);

/*Esta funciones imprimen las torres*/
void show_hanoi(int origen, int destino);
void pintar_torre(void);
void imprimir_nivel(int nivel, int fila, int columna);
void iniciar_esquinas(void);
void paleta_colores(void);
void mensaje(int estado);

/*Declaración de variables globales*/
int **torres, topeA, topeB, topeC;
int m=0;

/*Declaración de variables globales*/
char **torre;
int **planostorres, numdiscos=0, filas,columnas;
int esquinaA, esquinaB,esquinaC;
/*Variables de los mensajes*/
char origen, destino;
int disco;

int main()
{
	char a='a', b='b', c='c';
	int opc;
	initscr();
	start_color();
	paleta_colores();
	do
	{
		bkgd(COLOR_PAIR(8));
		while(numdiscos<1)
		{
		erase();
		mvprintw(0,0,"Seleccione el numero de discos que desea tener:");
		scanw("%d",&numdiscos);
		}
		definir_planos();
		draw_planos();
		draw_torres();
		build_torres();
		iniciar_esquinas();

		mvprintw(1,0,"INICIO");
		pintar_torre();
		mensaje(0);
		sleep(3);
		refresh();
		erase();
		
		Hanoi(a,b,c, numdiscos);
		mvprintw(filas+2,0,"FIN DE LA SIMULACIÓN!!!\n");
		mvprintw(filas+3,0,"¿Desea realizar otro calculo?\n1.Si\n2.No\n");
		scanw("%d",&opc);
		erase();
		m=0;
	}
	while(opc==1);
	getch();
	endwin();
	return 0;
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
	  sleep(2);
	}
	else
	{
		Hanoi(a, c, b, n-1);
		origen=a-32;
		destino=c-32;
		disco=n;
		show_hanoi(a%97,c%97);
		//mvprintw(1,0,"Moviendo disco %d de la torre %c a la torre %c \n", n, a-32, c-32);
		refresh();
		erase();
		Hanoi(b, a, c, n-1);
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

/*Bloque de módulos genara una torre indice de donde se puede seleccionar un nivel y imprimirlo.*/
void	definir_planos(void)
{
	int i,j;
	planostorres=(int**)calloc(numdiscos+2, sizeof(int*));

	for(i=0;i<=numdiscos+1;i++)
		*(planostorres+i)=(int*)calloc(2, sizeof(int));
}

void	draw_planos()
{
	int i,j, caracteres=2, espacios=numdiscos+1;

	for(i=0;i<=numdiscos+1;i++)
	  {
	  for(j=0;j<2;j++)
		{
		if(j==0)
			{
			planostorres[i][j]=espacios;		 
			espacios--;
			}
		else
			{  				
		  	planostorres[i][j]=caracteres;
		  	caracteres=caracteres+2;
			}
		}		
	  }
}

void draw_torres(void)
{
	int i,j,temp, numcaracteres,centrov1,centrov2;
	
	torre=(char**)calloc(numdiscos+2, sizeof(char*));

	for(i=0;i<=numdiscos;i++)
		{
		numcaracteres=i*2+2;
		*(torre+i)=(char*)calloc(numcaracteres, sizeof(char));
		}

	*(torre+i)=(char*)calloc(numcaracteres+4, sizeof(char));
	
	for(i=0;i<(numdiscos+1)*2+2;i++)
		torre[numdiscos+1][i]='+';
	torre[numdiscos+1][i]='\0';
	
	for(i=0;i<=numdiscos;i++)
		{
	 	 //Añadir Espacios
		numcaracteres=i*2+2;
		centrov1=i;
	  	centrov2=i+1;
			  	
	  	for(j=0;j<numcaracteres;j++)
	  		{
  			if((j==centrov1 || j==centrov2)&&i==0)
  				{
 				torre[i][j]='+';
 				}
			else
				{
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
	if (has_colors())
		{
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
	mensaje(0);
	pintar_torre();
	sleep(2);
	refresh();
	erase();

	auxiliar=torres[*topeOrigen][x_origen];
	torres[*topeOrigen][x_origen]=0;
	mensaje(1);	
	pintar_torre();
	sleep(2);
	refresh();
	erase();
	*topeOrigen=*topeOrigen+1;
	/*Aquí añade el disco a la torre de destino*/
	*topeDestino=*topeDestino-1;
	torres[*topeDestino][x_destino%3]=auxiliar;
	mensaje(2);
	pintar_torre();
	sleep(2);
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
