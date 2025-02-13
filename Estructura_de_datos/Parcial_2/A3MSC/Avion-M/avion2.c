#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cola.h"
#define V 20
#define P 5


typedef struct 
{
	int clave_v;
	char *destino;
	char *cap_vuelo;
	char *aerolinea;
	int asignado;
}Vuelos;
//Archivos
//uno
void LeerVuelos(Vuelos *lista);
void LlenandoEstruc(Vuelos *lista, char *cad, int *total);

//Cola
void LlenaCola(Cola *pis1, Cola *pis2, Cola *pis3);
void InsertarAlea(Cola *Pista, int j, int *i);

void AgregarVuelo(Cola *aux1, Cola *aux2, Cola *aux3, Vuelos *turno);
//dos
void Obtenermenor(Cola *pis1, Cola *pis2, Cola *pis3, int *menor);//Obtiene el elemento menor de la pis1, pis2 y pis3
void Quitarmenor(Cola *aux1, Cola *aux2, Cola *aux3, Cola *pis1, Cola *pis2, Cola *pis3, int menor, int *ind, Vuelos *turno);
int BuscarVuelo(Vuelos *turno, int clave);

void ImprimirVuelo(Vuelos *lista, int ind);
void diavion(int i);
//tres
void Pantalla(Vuelos *lista, int ind);
void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno);
void init_curses();
void tiempoavion(int i);
void impresio_marcos(void);

int main()
{
	int menor, ind;
	Cola pis1, pis2, pis3, aux1, aux2, aux3;
	Vuelos lista[V];
	initscr();
	init_curses();
	bkgd(COLOR_PAIR(7));
	crearcola(&pis1);
	crearcola(&pis2);
	crearcola(&pis3);
	crearcola(&aux1);
	crearcola(&aux2);
	crearcola(&aux3);
	LeerVuelos(lista);
	LlenaCola(&pis1, &pis2, &pis3);
	AgregarVuelo(&aux1, &aux2, &aux3, lista);
	do{
		menor=16;
		Obtenermenor(&pis1, &pis2, &pis3, &menor);
		Quitarmenor(&aux1, &aux2, &aux3, &pis1, &pis2, &pis3, menor, &ind, lista);
		//clear();
		//mvprintw(25,25,"%d  %d", menor, ind);
		//mvprintw(26,25,"%d", i);
		//getch();
		Pantalla(lista, ind);
	}while(colavacia(&aux1) == 0 || colavacia(&aux2) == 0 || colavacia(&aux3) == 0);//Hasta q las 3 esten vacias
	getch();
	endwin();
	return 0;
}

//Archivos
void LeerVuelos(Vuelos *lista)
{
	FILE *arch;
	int total = 0;
	char cad[200];
	 if ((arch = fopen("Vuelos.rpm", "r"))	 == NULL)
	 {
			fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
	 }
	else
	{
		while (!feof(arch))
		{
			if (fgets(cad,449,arch) != NULL)
			{
				LlenandoEstruc(lista, cad, &total);
			}
		}
	}
	fclose(arch);
}

void LlenandoEstruc(Vuelos *lista, char *cad, int *total)
{
	int campo, i, j;
	char subc[30];
	for (campo = 0, i = 0, j = 0; i < strlen(cad); i++)
	{
		if (cad[i] != '\t' && cad[i] != '\n')
			subc[j++]= cad[i];
		else
		{
			subc[j] = '\0';
			j = 0;
			campo++;
			switch (campo)
			{
				case 1 : lista[*total].clave_v = atoi(subc);
						break;
				case 2 : lista[*total].destino = (char *) malloc(strlen(subc));
						strcpy(lista[*total].destino,subc);
						break;
				case 3 : lista[*total].cap_vuelo = (char *) malloc(strlen(subc));
						strcpy(lista[*total].cap_vuelo,subc);
						break;
				case 4 : lista[*total].aerolinea = (char *) malloc(strlen(subc));
						strcpy(lista[*total].aerolinea,subc);
						break;
				case 5 : lista[*total].asignado = atoi(subc);
						break;
			}
		}
	}
	(*total)++;
}

//Cola
void LlenaCola(Cola *pis1, Cola *pis2, Cola *pis3)
{
	int i, j, r;
	for (i=1; i<=15;i++)
	{
		srand((unsigned) time(NULL));
		system ("sleep 0.5");
		j=rand() % 3+1;
		r = i % 3;
		clear();
		if(r==0)
		{
			mvprintw(30,70," Llenando Colas ");
			mvprintw(30,87,".");
			refresh();
		}
		if(r==1)
		{
			mvprintw(30,70," Llenando Colas ");
			mvprintw(30,87,"..");
			refresh();
		}
		if(r==2)
		{
			mvprintw(30,70," Llenando Colas ");
			mvprintw(30,87,"...");
			refresh();
		}
		switch (j)
		{
			case 1:
				InsertarAlea(pis1, j, &i);
				break;
			case 2:
				InsertarAlea(pis2, j, &i);
				break;
			case 3:
				InsertarAlea(pis3, j, &i);
				break;
			}
	}
}

void InsertarAlea(Cola *Pista, int j, int *i)
{
	if (!colallena (*Pista))
		insertar(Pista,*i);
	else
		(*i)--;
}

void Obtenermenor(Cola *pis1, Cola *pis2, Cola *pis3, int *menor)
{
	if(!colavacia(pis1))
	{
		if(*menor > frente(*pis1))
		{
			*menor=frente(*pis1);
		}
	}
	//clear();
	//mvprintw(25,50,"%d  %d",frente(*pis1),*menor);
	//getch();
	if(!colavacia(pis2))
	{
		if((*menor) > frente(*pis2))
		{
			(*menor)=frente(*pis2);
		}
	}
	if(!colavacia(pis3))
	{
		if((*menor) > frente(*pis3))
		{
			(*menor)=frente(*pis3);
		}
	}
}

void Quitarmenor(Cola *aux1, Cola *aux2, Cola *aux3, Cola *pis1, Cola *pis2, Cola *pis3, int menor, int *ind, Vuelos *turno)
{
	int clave;
	if(menor == frente(*pis1))
	{
		quitar(pis1);
		clave = frente(*aux1);
		quitar(aux1);
		*ind=BuscarVuelo(turno, clave);
	}
	if(menor == frente(*pis2))
	{
		quitar(pis2);
		clave = frente(*aux2);
		quitar(aux2);
		*ind=BuscarVuelo(turno, clave);
	}
	if(menor == frente(*pis3))
	{
		quitar(pis3);
		clave = frente(*aux3);
		quitar(aux3);
		*ind=BuscarVuelo(turno, clave);
	}
}

int BuscarVuelo(Vuelos *turno, int clave)
{
	int i, ind;
	for(i = 0; i < V; i++)
	{
		if(clave == turno[i].clave_v)
		{
			ind = i;
		}
	}
	return ind;
}

void AgregarVuelo(Cola *aux1, Cola *aux2, Cola *aux3,  Vuelos *turno)
{
	int num;
	do{
		srand((unsigned) time(NULL)); 
		system ("sleep 0.5");
		num=rand() % 20 + 1;
		if(!colallena(*aux1) && turno[num].asignado != 1){
			insertar(aux1,num);
			turno[num].asignado=1;
		}
		if(!colallena(*aux2) && colallena(*aux1)==1 && turno[num].asignado!=1){
			insertar(aux2,num);
			turno[num].asignado=1;
		}
		if(!colallena(*aux3)  && colallena(*aux2)==1 && turno[num].asignado!=1){
			insertar(aux3,num);
			turno[num].asignado=1;
		}
		//clear();
		//mvprintw(25,75,"%d",turno[num].asignado);
		//refresh();
	}while(colallena(*aux3)!=1);
}


void ImprimirVuelo(Vuelos *lista, int ind)
{
	//refresh();
	attron(COLOR_PAIR(7));
	mvprintw(5,91,"A E R O P U E R T O");
	mvprintw(6,93,"H U A T U L C O");
	mvprintw(8, 70,"C L A V E : %d ", lista[ind].clave_v);
	mvprintw(12, 110,"D E S T I N O : %s ", lista[ind].destino);
	mvprintw(16,70 ,"C A P I T A N : %s ", lista[ind].cap_vuelo);
	mvprintw(20,80,"A E R O L I N E A : %s", lista[ind].aerolinea);
}

void Pantalla(Vuelos *lista, int ind)
{
	int i;
		for(i=40; i>-2; i--){ 
			clear();
			impresio_marcos();
			mvprintw(1+i,19,"Destino %s", lista[ind].destino);
			/*Aqui se imprime el avion ojo avion*/
			diavion(i);
			ImprimirVuelo(lista, ind);
			tiempoavion(i);
		}
}
void impresio_marcos(void)
{
		attron(COLOR_PAIR(2));
		marco(2,60,80,37,'*',' ');
		attron(COLOR_PAIR(7));
		attron(COLOR_PAIR(4));
		marco(-1,11,30,60,'#',' ');
		attron(COLOR_PAIR(9));
		marco(3,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(12,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(21,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(30,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(39,25,1,5,' ',' ');
		attron(COLOR_PAIR(9));
		marco(48,25,1,5,' ',' ');
		attron(COLOR_PAIR(8));
}
void tiempoavion(int i)
{
		if(i == 40){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion en espera");
			refresh();
			system("sleep 4");
		}
		if(i < 40 && i > 38){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion despegando");
			refresh();
			system("sleep 2");
		}
		if(i < 39 && i > 37){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion despegando");
			refresh();
			system("sleep 1");
		}
		if(i < 38 && i > 36){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion despegando");
			refresh();
			system("sleep 0.8");
		}
		if(i < 37 && i > 34){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion despegando");
			refresh();
			system("sleep 0.6");
		}
		if(i < 35 && i > 31){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion despegando");
			refresh();
			system("sleep 0.4");
		}
		if(i < 32 && i > 27){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion despegando");
			refresh();
			system("sleep 0.3");
		}
		if(i < 28 && i > 24){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion despegando");
			refresh();
			system("sleep 0.2");
		}
		if(i < 25 && i > 20){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion volando");
			refresh();
			system("sleep 0.15");
		}
		if(i < 21 && i > 15){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion volando");
			refresh();
			system("sleep 0.1");
		}
		if(i < 16 && i > 10){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion volando");
			refresh();
			system("sleep 0.05");
		}
		if(i < 11 && i > -3){
			attron(COLOR_PAIR(7));
			mvprintw(35,100,"Estado: Avion volando");
			refresh();
			system("sleep 0.03");
		}
}
void diavion(int i)
{
		mvprintw(-17+i,25,"/\\");
		mvprintw(-16+i,24,"/--\\");
		mvprintw(-15+i,23,"||--||");
		mvprintw(-14+i,23,"||--||");
		mvprintw(-13+i,21,"|||/--\\|||");
		mvprintw(-12+i,23,"|/--\\|");
		mvprintw(-11+i,23,"|/--\\|");
		mvprintw(-10+i,21,"//|/--\\|\\\\");
		mvprintw(-9+i,19,"//--|/--\\|--\\\\");
		mvprintw(-8+i,16,"//-----|/--\\|-----\\\\");
		mvprintw(-7+i,14,"//-------|/--\\|-------\\\\");
		mvprintw(-6+i,12,"//||||||||||/--\\||||||||||\\\\");
		mvprintw(-5+i,22,"||/--\\||");
		mvprintw(-4+i,22,"||/--\\||");
		mvprintw(-3+i,22,"||/--\\||");
		mvprintw(-2+i,21,"/||/--\\||\\");
		mvprintw(-1+i,19,"/--||/--\\||--\\");
		mvprintw(0+i,22,"||/--\\||");
		refresh();
}

void init_curses()
{
    initscr();
    cbreak();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    init_pair(4,COLOR_WHITE,COLOR_BLACK);
    init_pair(5,COLOR_CYAN, COLOR_WHITE);
    init_pair(6,COLOR_BLUE,COLOR_YELLOW);
    init_pair(7,COLOR_YELLOW,COLOR_BLUE);
    init_pair(8,COLOR_YELLOW,COLOR_BLACK);
    init_pair(9,COLOR_WHITE,COLOR_WHITE);
    curs_set(0);
}

void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno)
{
	int i,j;

	for(i=filaO; i<filaO+ancho;i++)	
		for(j=columnaO; j<columnaO+largo;j++){
			if(i==filaO || i==filaO+ancho-1)		
				mvprintw(i,j,"%c",borde);
			else 
				if(j==columnaO || j==columnaO+largo-1)
					mvprintw(i,j,"%c",borde);
				else 
					mvprintw(i,j,"%c",relleno);
		}		
}
