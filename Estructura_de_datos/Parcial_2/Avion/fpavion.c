#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "cola.h"
#include "fpavion.h"

void ingresardatos()
{
	int menor, ind,np,opc,i,nua=0;
	Cola pis1, pis2, pis3, aux1, aux2, aux3;
	Vuelos lista[V];
	init_curses();
	bkgd(COLOR_PAIR(5));
	do{
	opc=MenuAd();
	switch(opc){
		case 1:
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
				Quitarmenor(&aux1, &aux2, &aux3, &pis1, &pis2, &pis3, menor, &ind, lista,&np);
				Pantalla(lista,ind,np,nua);
				nua++;
			}while(colavacia(&aux1) == 0 || colavacia(&aux2) == 0 || colavacia(&aux3) == 0);//Hasta q las 3 esten vacias
			clear();
			echo();
			attron(COLOR_PAIR(10));
			marco(12,53,42,10,' ',' ');
			attron(COLOR_PAIR(10));
			mvprintw(14,57,"EL TOTAL DE AVIONES DESPEGADOS DEL");
			mvprintw(16,63,"AEROPUERTO Glonan-RJ");
			mvprintw(18,67,"FUERON %d",nua);
			mvprintw(20,58,"*Presione una tecla para salir*");
			getch();
			attroff(COLOR_PAIR(10));
			nua=0;
		break;
		case 2:
			LeerVuelos(lista);
			clear();
			echo();
			attron(COLOR_PAIR(7));
			mvprintw(2,40,"IMPRESIóN DE LOS DATOS DE AVIONES");
			attron(COLOR_PAIR(3));
			mvprintw(5,4,"	CLAVE		DESTINO			CAPITAN DE VUELO		AEROLíNEA");
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
			for(i=0;i<V;i++){
				echo();
				mvprintw(5+i+2,4,"\t%d\t\t%s\t\t\t%s\t\t\t%s",lista[i].clave_v,lista[i].destino,lista[i].cap_vuelo,lista[i].aerolinea);
			}
			attroff(COLOR_PAIR(2));
			mvprintw(5+i+5,18,"Presione una tecla para regresar al menú");
			attroff(COLOR_PAIR(7));
			getch();
			break;
		}
	}while(opc!=3);
}

//Archivos
void LeerVuelos(Vuelos *lista)
{
	FILE *arch;
	int total = 0;
	char cad[200];
	if ((arch = fopen("Vuelos.rpm", "r"))	 == NULL){
		fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
	}else{
		while (!feof(arch)){
			if (fgets(cad,70,arch) != NULL){
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
	for (campo = 0, i = 0, j = 0; i < strlen(cad); i++){
		if (cad[i] != '\t' && cad[i] != '\n')
			subc[j++]= cad[i];
		else{
			subc[j] = '\0';
			j = 0;
			campo++;
			switch (campo){
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
	int i, j;
	for (i=1; i<=15;i++){
		srand((unsigned) time(NULL));
		system ("sleep 0.5");
		j=rand() % 3+1;
		clear();
		attron(COLOR_PAIR(10));
		marco(15,58,42,10,' ',' ');
		attron(COLOR_PAIR(10));
		mvprintw(18,60,"Simulacion de vuelos en un aeropuerto");
		mvprintw(20,70,"Cargando aviones");
		mvprintw(22,86,"%d/15",i);
		attron(COLOR_PAIR(5));
		marco(22,70,15,1,' ',' ');
		attroff(COLOR_PAIR(5));
		attron(COLOR_PAIR(15));
		marco(22,70,i,1,' ',' ');
		attroff(COLOR_PAIR(15));
		refresh();
		attroff(COLOR_PAIR(10));
		switch (j){
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
	attron(COLOR_PAIR(16));
	mvprintw(22,86,"       ");
	mvprintw(20,70," Carga exitosa  ");
	attron(COLOR_PAIR(16));
	refresh();
	system("sleep 4");
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
	if(!colavacia(pis1)){
		if(*menor > frente(*pis1)){
			*menor=frente(*pis1);
		}
	}
	if(!colavacia(pis2)){
		if((*menor) > frente(*pis2)){
			(*menor)=frente(*pis2);
		}
	}
	if(!colavacia(pis3)){
		if((*menor) > frente(*pis3)){
			(*menor)=frente(*pis3);
		}
	}
}

void Quitarmenor(Cola *aux1, Cola *aux2, Cola *aux3, Cola *pis1, Cola *pis2, Cola *pis3, int menor, int *ind, Vuelos *turno,int *np)
{
	int clave;
	if(menor == frente(*pis1)){
		quitar(pis1);
		clave = frente(*aux1);
		quitar(aux1);
		*ind=BuscarVuelo(turno, clave);
		*np=1;
	}
	if(menor == frente(*pis2)){
		quitar(pis2);
		clave = frente(*aux2);
		quitar(aux2);
		*ind=BuscarVuelo(turno, clave);
		*np=2;
	}
	if(menor == frente(*pis3)){
		quitar(pis3);
		clave = frente(*aux3);
		quitar(aux3);
		*ind=BuscarVuelo(turno, clave);
		*np=3;
	}
}

int BuscarVuelo(Vuelos *turno, int clave)
{
	int i, ind;
	for(i = 0; i < V; i++){
		if(clave == turno[i].clave_v){
			ind = i;
		}
	}
	return ind;
}

void AgregarVuelo(Cola *aux1, Cola *aux2, Cola *aux3,  Vuelos *turno)
{
	int num,cont=1;
	do{
		clear();
		srand((unsigned) time(NULL)); 
		system ("sleep 0.5");
		num=rand() % 20 + 1;
		attron(COLOR_PAIR(10));
		marco(15,58,42,10,' ',' ');
		attron(COLOR_PAIR(10));
		mvprintw(18,60,"Simulacion de vuelos en un aeropuerto");
		mvprintw(20,70,"Asignando turno");
		mvprintw(22,86,"%d/15",cont);
		attron(COLOR_PAIR(5));
		marco(22,70,15,1,' ',' ');
		attroff(COLOR_PAIR(5));
		attron(COLOR_PAIR(15));
		marco(22,70,cont,1,' ',' ');
		attroff(COLOR_PAIR(15));
		refresh();
		attroff(COLOR_PAIR(10));
		if(!colallena(*aux1) && turno[num].asignado != 1){
			insertar(aux1,num);
			turno[num].asignado=1;
			cont++;
		}
		if(!colallena(*aux2) && colallena(*aux1)==1 && turno[num].asignado!=1){
			insertar(aux2,num);
			turno[num].asignado=1;
			cont++;
		}
		if(!colallena(*aux3)  && colallena(*aux2)==1 && turno[num].asignado!=1){
			insertar(aux3,num);
			turno[num].asignado=1;
			cont++;
		}
	}while(colallena(*aux3)!=1);
	attron(COLOR_PAIR(16));
	mvprintw(22,86,"       ");
	mvprintw(20,68,"Asignacion completa");
	attron(COLOR_PAIR(16));
	refresh();
	system("sleep 4");
}


void ImprimirVuelo(Vuelos *lista, int ind,int np,int nua)
{
	attron(COLOR_PAIR(12));
	marco(3,84,33,9,' ',' ');
	mvprintw(4,86,"UNIVERSIDAD DE LA SIERRA SUR");
	mvprintw(7,87,"LICENCIATURA EN INFORMATICA");
	mvprintw(9,91,"A E R O P U E R T O");
	mvprintw(10,93,"** Glonan-RJ **");
	attroff(COLOR_PAIR(12));
	attron(COLOR_PAIR(10));
	mvprintw(17,70,"Total de aviones despegados: %d",nua);
	mvprintw(19,70,"C L A V E : %d ", lista[ind].clave_v);
	mvprintw(21,70,"D E S T I N O : %s ", lista[ind].destino);
	mvprintw(23,70 ,"C A P I T A N : %s ", lista[ind].cap_vuelo);
	mvprintw(25,70,"A E R O L I N E A : %s", lista[ind].aerolinea);
	mvprintw(32,83,"Estado                       Numero pista");
	mvprintw(34,119,"%d ",np);
	attroff(COLOR_PAIR(10));
}

void Pantalla(Vuelos *lista, int ind,int np,int nua)
{
	int i;
		for(i=40; i>-2; i--){ 
			clear();
			impresio_marcos();
			mvprintw(1+i,19,"Destino %s", lista[ind].destino);
			/*Aqui se imprime el avion ojo avion*/
			diavion(i);
			ImprimirVuelo(lista, ind,np,nua);
			tiempoavion(i);
		}
}
void impresio_marcos(void)
{
		attron(COLOR_PAIR(11));
		marco(2,60,80,37,' ',' ');
		attroff(COLOR_PAIR(11));
		
		attron(COLOR_PAIR(7));
		attron(COLOR_PAIR(4));
		marco(-1,11,30,60,'#',' ');
		attroff(COLOR_PAIR(4));
		
		attron(COLOR_PAIR(9));
		marco(3,25,1,5,' ',' ');
		attroff(COLOR_PAIR(9));
		attron(COLOR_PAIR(9));
		marco(12,25,1,5,' ',' ');
		attroff(COLOR_PAIR(9));
		attron(COLOR_PAIR(9));
		marco(21,25,1,5,' ',' ');
		attroff(COLOR_PAIR(9));
		attron(COLOR_PAIR(9));
		marco(30,25,1,5,' ',' ');
		attroff(COLOR_PAIR(9));
		attron(COLOR_PAIR(9));
		marco(39,25,1,5,' ',' ');
		attroff(COLOR_PAIR(9));
		attron(COLOR_PAIR(9));
		marco(48,25,1,5,' ',' ');
		attroff(COLOR_PAIR(9));
		attron(COLOR_PAIR(8));
		
}
void tiempoavion(int i)
{
		if(i == 40){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion en espera");
			refresh();
			system("sleep 4");
			attroff(COLOR_PAIR(7));
		}
		if(i < 40 && i > 38){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion despegando");
			refresh();
			system("sleep 2");
			attroff(COLOR_PAIR(7));
		}
		if(i < 39 && i > 37){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion despegando");
			refresh();
			system("sleep 1");
			attroff(COLOR_PAIR(7));
		}
		if(i < 38 && i > 36){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion despegando");
			refresh();
			system("sleep 0.8");
			attroff(COLOR_PAIR(7));
		}
		if(i < 37 && i > 34){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion despegando");
			refresh();
			system("sleep 0.6");
			attroff(COLOR_PAIR(7));
		}
		if(i < 35 && i > 31){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion despegando");
			refresh();
			system("sleep 0.4");
			attroff(COLOR_PAIR(7));
		}
		if(i < 32 && i > 27){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion despegando");
			refresh();
			system("sleep 0.3");
			attroff(COLOR_PAIR(7));
		}
		if(i < 28 && i > 24){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion despegando");
			refresh();
			system("sleep 0.2");
			attroff(COLOR_PAIR(7));
		}
		if(i < 25 && i > 20){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion volando");
			refresh();
			system("sleep 0.15");
			attroff(COLOR_PAIR(7));
		}
		if(i < 21 && i > 15){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion volando");
			refresh();
			system("sleep 0.1");
			attroff(COLOR_PAIR(7));
		}
		if(i < 16 && i > 10){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion volando");
			refresh();
			system("sleep 0.05");
			attroff(COLOR_PAIR(7));
		}
		if(i < 11 && i > -3){
			attron(COLOR_PAIR(7));
			mvprintw(34,78,"Avion volando");
			refresh();
			system("sleep 0.03");
			attroff(COLOR_PAIR(7));
		}
}
void diavion(int i)
{
		attron(COLOR_PAIR(14));
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
		attroff(COLOR_PAIR(14));
}

void init_curses()
{
    initscr();
    cbreak();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    init_pair(5,COLOR_CYAN, COLOR_WHITE);
    init_pair(6,COLOR_BLUE,COLOR_YELLOW);
    init_pair(7,COLOR_YELLOW,COLOR_MAGENTA);
    init_pair(8,COLOR_YELLOW,COLOR_BLACK);
    init_pair(9,COLOR_WHITE,COLOR_WHITE);
    init_pair(10,COLOR_WHITE,COLOR_MAGENTA);
    init_pair(11,COLOR_RED,COLOR_MAGENTA);
    init_pair(12,COLOR_RED,COLOR_WHITE);
    init_pair(13,COLOR_MAGENTA,COLOR_WHITE);
    init_pair(14,COLOR_WHITE,COLOR_BLACK);
    init_pair(15,COLOR_WHITE,COLOR_RED);
    init_pair(16,COLOR_GREEN,COLOR_MAGENTA);
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
//para el menu 
int MenuAd()
{
	int j;
	clear();
	keypad(stdscr, TRUE);
	echo();
	attron(COLOR_PAIR(10));
	marco(5,36,78,30,' ',' ');
	mvprintw(7,64,"Simulacion de un aeropuerto");
	mvprintw(8,68,"Lic. INFORMATICA");
	mvprintw(16,67," Opciones a elegir");
	mvprintw(18,50,"1.- Simulacion de aviones");
	mvprintw(20,50,"2.- Ver lista de aviones");
	mvprintw(22,50,"3.- Salir");
	mvprintw(24,50,"ELIJE UNA OPCION");
	attroff(COLOR_PAIR(10));
	attron(COLOR_PAIR(3));
	j=Rango(1,3,24,73);
	attroff(COLOR_PAIR(3));
	return j;
}
int Rango(int men , int may,int r,int c)
{
	int h=0,valor;
	char cad[2];
	while(h==0){
		echo();
		mvprintw(r,c,"      ");
		LeeEntero(cad,3,r,c+2);
		valor = atoi(cad);
		if(valor>=men && valor<=may){
			 h=1;
		}
	}
	return valor;
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
		}while (aux != RET && aux != ENT && !isdigit(aux) && aux != '-');
		switch(aux){
			case ENT:
				band = 1;
				cad[ind] = '\0';
				break;
			case RET:
				if(ind > 0){
					ind--;
					move(r,c+ind);
					printw(" ");
					move(r,c+ind);
				}
				break;
			case '-':
				if (!ind){
					cad[ind] = aux;
					move(r,c+ind);
					printw("%c",aux);
					ind++;
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
