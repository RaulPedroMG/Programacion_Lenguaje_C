#include "formato.h"

void pintar(char *name,char *name1)
{
	int c1=21,c2=22;
	int j1[2][32]={{44,55,65,80,90,105,117,117,105,90,80,65,55,55,65,80,90,105,117,117,105,90,80,65,55,55,65,80,90,105,117,129},
				   {31,31,31,31,31,31,31,25,25,25,25,25,25,19,19,19,19,19,19,13,13,13,13,13,13,7,7,7,7,7,7,7}};
	int j2[2][32]={{44,55,65,80,90,105,117,117,105,90,80,65,55,55,65,80,90,105,117,117,105,90,80,65,55,55,65,80,90,105,117,129},
					{33,33,33,33,33,33,33,27,27,27,27,27,27,21,21,21,21,21,21,15,15,15,15,15,15,9,9,9,9,9,9,9}};
	echo();
	refresh();
	init_curses();
	bkgd(COLOR_PAIR(1));
	attron(COLOR_PAIR(3));
	echo();
	marco(3,13,120,34,' ',' '); //marco principal de color rojo
	attron(COLOR_PAIR(16));
	mvprintw(4,67,"SERPIENTES Y ESCALERAS");
	mvprintw(4,99,"s = serpientes e = escaleras");
	attroff(COLOR_PAIR(16));
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(12));
	marco(5,15,116,31,' ',' '); //ventana de color verde fondo del tablero
	attroff(COLOR_PAIR(12));
	refresh();
	cuadritos();
	attron(COLOR_PAIR(9));
	marco(5,15,31,31,' ',' '); // ventana del dado y mensajes a los jugadores color blanco
	attroff(COLOR_PAIR(9));
	marco(30,42,8,5,' ',' ');
	mvprintw(34,43,"Salida");
	marco(6,123,8,5,' ',' ');
	mvprintw(6,126,"Meta");
	monitos(j1,c1,0);
	monitos(j2,c2,0);
	numeracion();
	escaleras();
	attron(COLOR_PAIR(24));
	mvprintw(12,23,"%s",name);
	mvprintw(14,23,"%s",name1);
	attron(COLOR_PAIR(24));
	refresh();
	
	dado(name,name1,j1,j2,c1,c2);
}
void monitos(int mat[2][32],int color,int i)
{
	attron(COLOR_PAIR(color));
	mvprintw(mat[1][i],mat[0][i],"  ");
	attron(COLOR_PAIR(color));
}

void dado(char *name,char *name1,int j1[2][32],int j2[2][32],int c1,int c2)
{
	int b,band1=1,band3=0,band2=0,cont1=0,cont2=0,o1=0,o2=0;
	srand(time(NULL));
	while((band3==0)){
		attron(COLOR_PAIR(24));
		mvprintw(10,24,"Nombre de jugadores");
		mvprintw(12,23,"%s %d",name,o1);
		mvprintw(14,23,"%s %d",name1,o2);
		mvprintw(25,20,"Para tirar presiona enter");
		if(band1==1){
			mvprintw(23,28,"                 ");
			mvprintw(23,23,"Turno de %s ",name);
		}else{
			mvprintw(23,28,"                 ");
			mvprintw(23,23,"Turno de %s",name1);
		}
		attroff(COLOR_PAIR(24));
		refresh();
		getch();
		b=rand()%(6)+1;
		//efecto de ir cambiando numeros en la pantalla
		contadores(b,&band1,&band2,&cont1,&cont2);
		giradado(b);
		attron(COLOR_PAIR(24));
		mvprintw(10,24,"Nombre de jugadores");
		mvprintw(12,23,"%s %d",name,o1);
		mvprintw(14,23,"%s %d",name1,o2);
		attroff(COLOR_PAIR(24));
		/*proceso para avanzar en las casillas*/
		refresh();
		band3=process(b,j1,j2,c1,c2,&o1,&o2,band1);
		if(band3==1){
			ganador(o1,o2,band1,name,name1);
		}
	}
}
int process(int b,int j1[2][32],int j2[2][32],int c1,int c2,int *o1,int *o2,int band)
{
	int tabla[31][31],i;
	llenado(tabla);
	aristas(tabla);
	agregarari(2,11,tabla,50);
	agregarari(12,23,tabla,10);
	agregarari(15,26,tabla,100);
	agregarari(17,29,tabla,120);
	agregarari(16,5,tabla,-50);
	agregarari(20,7,tabla,-100);
	agregarari(21,10,tabla,-30);
	agregarari(28,22,tabla,-50);
	i=movermat(tabla,o1,o2,band,b,j1,j2);
	return i;
}

int movermat(int tabla[31][31],int *o1,int *o2,int band,int b,int j1[2][32],int j2[2][32])
{
	int i,j,p,q=0,s=0,n=0,m=0,z=0,u=0;
	for(i=b;i>=0;i--){
		if(i>0){
			if(band==0){
				if(*o1+b<=30){
				for(j=0;j<31 && q==0;j++){
					if(tabla[*o1][j]==0){
						for(z=b;z>0;z--){
							avanzarHori(1,j1,21,o1);
							system("sleep 0.3");
						}
						q=1;
					}
				}
			}
			}else{
				if(*o2+b<=30){
				for(j=0;j<31 && s==0;j++){
					if(tabla[*o2][j]==0){
						for(z=b;z>0;z--){
							avanzarHori(1,j2,22,o2);
							system("sleep 0.3");
						}
						s=1;
					}
				}
			}
			}
		}else{
			if(i==0){
				if(band==0){
					if(*o1+b<=30){
					for(p=0;p<31 && n==0;p++){
						if(tabla[*o1][p]>0){
							subesc(p,j1,o1,o2,band,j2);
							n=1;
						}else{
							if(tabla[*o1][p]<-1){
								bajser(p,j1,o1,o2,band,j2);
								n=1;
							}
						}
					}
				}
				}else{
					if(*o2+b<=30){
					for(p=0;p<31 && m==0;p++){
						if(tabla[*o2][p]>0){
							subesc(p,j1,o1,o2,band,j2);
							m=1;
						}else{
							if(tabla[*o2][p]<-1){
								bajser(p,j1,o1,o2,band,j2);
								m=1;
							}
						}
					}
				}
				}
			}
		}
	}
	if(*o1>29 || *o2>29){
		u=1;
	}
	return u;
}
void subesc(int p,int j1[2][32],int *o1,int *o2,int band,int j2[2][32])
{
	if(band==0){
		attron(COLOR_PAIR(18));
		mvprintw(j1[1][*o1],j1[0][*o1],"  ");
		attron(COLOR_PAIR(18));
		*o1=p;
		attron(COLOR_PAIR(21));
		mvprintw(j1[1][*o1],j1[0][*o1],"  ");
		attron(COLOR_PAIR(21));
		refresh();
	}else{
		attron(COLOR_PAIR(18));
		mvprintw(j2[1][*o2],j2[0][*o2],"  ");
		attron(COLOR_PAIR(18));
		*o2=p;
		attron(COLOR_PAIR(22));
		mvprintw(j2[1][*o2],j2[0][*o2],"  ");
		attron(COLOR_PAIR(22));
		refresh();
	}
}

void bajser(int p,int j1[2][32],int *o1,int *o2,int band,int j2[2][32])
{
	if(band==0){
		attron(COLOR_PAIR(18));
		mvprintw(j1[1][*o1],j1[0][*o1],"  ");
		attron(COLOR_PAIR(18));
		*o1=p;
		attron(COLOR_PAIR(21));
		mvprintw(j1[1][*o1],j1[0][*o1],"  ");
		attron(COLOR_PAIR(21));
		refresh();
	}else{
		attron(COLOR_PAIR(18));
		mvprintw(j2[1][*o2],j2[0][*o2],"  ");
		attron(COLOR_PAIR(18));
		*o2=p;
		attron(COLOR_PAIR(22));
		mvprintw(j2[1][*o2],j2[0][*o2],"  ");
		attron(COLOR_PAIR(22));
		refresh();
	}
}
void avanzarHori(int nc,int j2[2][32],int c2 ,int *o2)
{
	if(*o2==0){
		attron(COLOR_PAIR(10));
		mvprintw(j2[1][0],j2[0][0],"  ");
		attron(COLOR_PAIR(10));
		*o2=*o2+nc;
		attron(COLOR_PAIR(c2));
		mvprintw(j2[1][*o2],j2[0][*o2],"  ");
		attron(COLOR_PAIR(c2));
		refresh();
	}else{
		*o2=*o2+nc;
		attron(COLOR_PAIR(18));
		mvprintw(j2[1][*o2-1],j2[0][*o2-1],"  ");
		attron(COLOR_PAIR(18));
		attron(COLOR_PAIR(c2));
		mvprintw(j2[1][*o2],j2[0][*o2],"  ");
		attron(COLOR_PAIR(c2));
		refresh();
	}
}

void agregarari(int p1,int p2,int mat[31][31],int peso)
{
	mat[p1][p2]=peso;
}
void llenado(int mat[31][31]){
	int j,i;
	for(i=0;i<31;i++){
		for(j=0;j<31;j++){
			mat[i][j]=-1;
		}
	}
}
void aristas(int mat[31][31]){
	int i,j;
	for(i=0;i<31;i++){
		for(j=0;j<31;j++){
			if(i==0){
				mat[i][1]=0;
			}else{
				mat[j][j+1]=0;	
			}
		}
	}
}
void giradado(int b)
{
	int i,g;
	srand(time(NULL));
	for(i=1;i<20;i++){
		refresh();
		g=rand()%(6)+1;
		finalnumero(g);
	}
	finalnumero(b);
}
void finalnumero(int b)
{
	switch(b){
		case 1:
			attron(COLOR_PAIR(b+1));
			marco(27,27,6,3,' ',' ');
			attroff(COLOR_PAIR(b+1));
			attron(COLOR_PAIR(b));
			marco(28,26,6,3,' ',' ');
			mvprintw(29,29,"*");
			system("sleep 0.06");
			attroff(COLOR_PAIR(b));
			refresh();
			break;
		case 2:
			attron(COLOR_PAIR(b+1));
			marco(27,27,6,3,' ',' ');
			attroff(COLOR_PAIR(b+1));
			attron(COLOR_PAIR(b));
			marco(28,26,6,3,' ',' ');
			mvprintw(28,30,"*");
			mvprintw(30,28,"*");
			system("sleep 0.06");
			attroff(COLOR_PAIR(b));
			refresh();
			break;
		case 3:
			attron(COLOR_PAIR(b+1));
			marco(27,27,6,3,' ',' ');
			attroff(COLOR_PAIR(b+1));
			attron(COLOR_PAIR(b));
			marco(28,26,6,3,' ',' ');
			mvprintw(28,30,"*");
			mvprintw(29,29,"*");
			mvprintw(30,28,"*");
			system("sleep 0.06");
			attroff(COLOR_PAIR(b));
			refresh();
			break;
		case 4:
			attron(COLOR_PAIR(b+1));
			marco(27,27,6,3,' ',' ');
			attroff(COLOR_PAIR(b+1));
			attron(COLOR_PAIR(b));
			marco(28,26,6,3,' ',' ');
			mvprintw(28,28,"* *");
			mvprintw(30,28,"* *");
			system("sleep 0.06");
			attroff(COLOR_PAIR(b));
			refresh();
			break;
		case 5:
			attron(COLOR_PAIR(b+1));
			marco(27,27,6,3,' ',' ');
			attroff(COLOR_PAIR(b+1));
			attron(COLOR_PAIR(b));
			marco(28,26,6,3,' ',' ');
			mvprintw(28,28,"* *");
			mvprintw(29,29,"*");
			mvprintw(30,28,"* *");
			system("sleep 0.06");
			attroff(COLOR_PAIR(b));
			refresh();
			break;
		case 6:
			attron(COLOR_PAIR(b+1));
			marco(27,27,6,3,' ',' ');
			attroff(COLOR_PAIR(b+1));
			attron(COLOR_PAIR(b));
			marco(28,26,6,3,' ',' ');
			mvprintw(28,28,"* *");
			mvprintw(29,28,"* *");
			mvprintw(30,28,"* *");
			system("sleep 0.06");
			attroff(COLOR_PAIR(b));
			refresh();
			break;
		}
}
void contadores(int b,int *band1,int *band2,int *cont1,int *cont2)
{
	if(*band1==1 && *band2==0){
		*cont1=*cont1+b;
		*band2=1;
		*band1=0;
	}else{
		if(*band1==0 && *band2==1){
			*cont2=*cont2+b;
			*band1=1;
			*band2=0;
		}
	}
}

void escaleras()
{
	int i;
	refresh();
	for(i=1;i<12;i++){
		attron(COLOR_PAIR(16));
		marco(9+i,68+i,1,1,'e','e');
		attroff(COLOR_PAIR(16));
		refresh();
	}
	for(i=1;i<12;i++){
		attron(COLOR_PAIR(8));
		marco(20+i,93+i,1,1,'s','s');
		attroff(COLOR_PAIR(8));
		refresh();
	}
	for(i=0;i<12;i++){
		attron(COLOR_PAIR(8));
		marco(27-i,78+i,1,1,'s','s');
		attroff(COLOR_PAIR(8));
		refresh();
	}
	attron(COLOR_PAIR(16));
	marco(10,103,1,9,'e','e');
	attroff(COLOR_PAIR(16));
	refresh();
	for(i=0;i<10;i++){
		attron(COLOR_PAIR(16));
		marco(25-i,56+i,1,1,'e','e');
		attroff(COLOR_PAIR(16));
		refresh();
	}
	for(i=1;i<12;i++){
		attron(COLOR_PAIR(8));
		marco(15+i,106+i,1,1,'s','s');
		attroff(COLOR_PAIR(8));
		refresh();
	}
	for(i=0;i<7;i++){
		attron(COLOR_PAIR(8));
		marco(14-i,83+i,1,1,'s','s');
		attroff(COLOR_PAIR(8));
		refresh();
	}
	attron(COLOR_PAIR(16));
	marco(27,64,1,5,'e','e');
	attroff(COLOR_PAIR(16));
}

void numeracion()
{
	int i,j=25;
	attron(COLOR_PAIR(18));
	for(i=10;i<80;i=i+13){
		mvprintw(10,i+43,"%d",j);
		j++;
	}
	j=24;
	for(i=10;i<80;i=i+13){
		mvprintw(16,i+43,"%d",j);
		j--;
	}
	j=13;
	for(i=10;i<80;i=i+13){
		mvprintw(22,i+43,"%d",j);
		j++;
	}
	j=12;
	for(i=10;i<80;i=i+13){
		mvprintw(28,i+43,"%d",j);
		j--;
	}
	j=1;
	for(i=10;i<80;i=i+13){
		mvprintw(34,i+43,"%d",j);
		j++;
	}
	attroff(COLOR_PAIR(18));
}
void ganador(int o1,int o2,int band,char *name,char *name1)
{
	if(band==0){
		clear();
		attron(COLOR_PAIR(18));
		marco(6,58,34,8,' ',' ');
		mvprintw(7,62,"El ganador es %s",name);
		Centrar("Presiona una tecla para salir",9);
		attroff(COLOR_PAIR(18));
		getch();
		refresh();
	}else{
		clear();
		attron(COLOR_PAIR(18));
		marco(6,58,34,8,' ',' ');
		mvprintw(7,62,"El ganador es %s",name1);
		Centrar("Presiona una tecla para salir",9);
		attroff(COLOR_PAIR(18));
		getch();
		refresh();
	}
}
void cuadritos()
{
	int i;
	attron(COLOR_PAIR(10));
	mvprintw(8,50,">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	marco(11,53,2,1,'^','^');
	mvprintw(14,50,"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
	marco(17,118,2,1,'^','^');
	mvprintw(20,50,">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	marco(23,53,2,1,'^','^');
	mvprintw(26,50,"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
	marco(29,118,2,1,'^','^');
	mvprintw(32,50,">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	attroff(COLOR_PAIR(10));
	attron(COLOR_PAIR(18));
	for(i=50;i<119;i=i+13){
		marco(6,i,8,5,' ',' ');
	}
	for(i=50;i<119;i=i+13){
		marco(12,i,8,5,' ',' ');
	}
	for(i=50;i<119;i=i+13){
		marco(18,i,8,5,' ',' ');
	}
	for(i=50;i<119;i=i+13){
		marco(24,i,8,5,' ',' ');
	}
	for(i=50;i<119;i=i+13){
		marco(30,i,8,5,' ',' ');	
	}
	attroff(COLOR_PAIR(18));
}


void init_curses()
{
    initscr();
    cbreak();
    start_color();
    //los primeros seis colores son para el dado
    init_pair(1,COLOR_WHITE,COLOR_MAGENTA);
    init_pair(2,COLOR_WHITE,COLOR_BLUE);
    init_pair(3,COLOR_WHITE,COLOR_RED);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    init_pair(5,COLOR_BLACK, COLOR_GREEN);
    init_pair(6,COLOR_BLUE,COLOR_YELLOW);
    //terminaciones de los colores del dado
    init_pair(7,COLOR_WHITE,COLOR_MAGENTA);
    init_pair(8,COLOR_YELLOW,COLOR_BLACK);
    init_pair(9,COLOR_WHITE,COLOR_WHITE);
    init_pair(10,COLOR_WHITE,COLOR_MAGENTA);
    init_pair(11,COLOR_WHITE,COLOR_GREEN);
    init_pair(12,COLOR_WHITE,COLOR_GREEN);
    init_pair(13,COLOR_MAGENTA,COLOR_WHITE);
    init_pair(14,COLOR_WHITE,COLOR_BLACK);
    init_pair(15,COLOR_WHITE,COLOR_GREEN);
    init_pair(16,COLOR_WHITE,COLOR_RED);
    init_pair(17,COLOR_RED,COLOR_RED);
    init_pair(18,COLOR_BLUE,COLOR_WHITE);
    init_pair(19,COLOR_BLACK, COLOR_WHITE);
    init_pair(20,COLOR_BLUE, COLOR_WHITE);
    init_pair(21,COLOR_BLACK, COLOR_YELLOW);
    init_pair(22,COLOR_BLUE, COLOR_CYAN);
    init_pair(23,COLOR_RED, COLOR_WHITE);
    init_pair(24,COLOR_RED, COLOR_WHITE);
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
