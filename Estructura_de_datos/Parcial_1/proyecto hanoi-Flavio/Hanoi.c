# include "Hanoi.h"
# include "string.h"
# include <math.h>
# include <time.h>
#include "ncurses.h"
#include <ctype.h>
#include <stdlib.h>
void IniciarColor()
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_CYAN);
	init_pair(2,COLOR_YELLOW,COLOR_YELLOW);
	init_pair(3,COLOR_GREEN,COLOR_GREEN);
	init_pair(4,COLOR_RED,COLOR_RED);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_BLUE, COLOR_BLUE);
	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(12, COLOR_GREEN, COLOR_BLACK);
	init_pair(13, COLOR_BLUE, COLOR_BLACK);
	init_pair(14, COLOR_CYAN, COLOR_BLACK);
	init_pair(15, COLOR_YELLOW, COLOR_BLACK);
	init_pair(16, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(17, COLOR_WHITE, COLOR_BLACK);
}

void Error(char *cad, int r)
{
	int ren,col;
	getmaxyx(stdscr,ren,col);
	col=(col/2)-(strlen(cad) / 2);
	mvprintw(r,col,"%s",cad);
}

int Menu()
{
	clear();
	int opcion;
	mvprintw(3,3,"**MENU**");
	mvprintw(5,3,"1.- JUGAR");
	mvprintw(6,3,"2.- REGLAS DEL JUEGO");
	mvprintw(7,3,"3.- RANKINGS");
	mvprintw(8,3,"4.- LEYENDA DE LAS TORRES DE HANOI");
	mvprintw(9,3,"5.- CREDITOS");
	mvprintw(10,3,"6.- SALIR");
	mvprintw(13,3,"Introduce su opción:");
	mvscanw(13,25,"%d",&opcion);
	return opcion;
}

int Menu2()
{
	clear();
	int opc;
	mvprintw(3,3,"**RANKING**");
	mvprintw(5,3,"1.- con 1 disco");
	mvprintw(6,3,"2.- con 2 disco");
	mvprintw(7,3,"3.- con 3 disco");
	mvprintw(8,3,"4.- con 4 disco");
	mvprintw(9,3,"5.- con 5 disco");
	mvprintw(10,3,"6.- con 6 disco");
	mvprintw(11,3,"7.- con 7 disco");
	mvprintw(12,3,"8.- con 8 disco");
	mvprintw(13,3,"9.- SALIR");
	mvprintw(15,3,"Introduce su opción:");
	mvscanw(15,25,"%d",&opc);
	return opc;
}

void JugarHanoi(int numdisco, Rankin *reg)
{
	int disco=numdisco,tiempo,tororigen,tordestino;
	Pila P1,P2,P3;
	time_t first, second;
	int movim=0;
	PilaVacia(&P1);
	PilaVacia(&P2);
	PilaVacia(&P3);
	first= time (NULL);
	do
	{
		Push(&P1,disco);
		disco--;
	}while(disco!=0);
	do
	{
		clear();
		PintarDisco(P1,P2,P3);
		Ranking(numdisco,movim);
			do
			{
				clear();
				PintarDisco(P1,P2,P3);
				Ranking(numdisco,movim);
				mvprintw(27,4,"Introdusca torre origen:");
				mvscanw(27,34,"%d",&tororigen);
				if(tororigen>=1 || tororigen<=3)
				{
					mvprintw(28,4,"Introdusca torre destino:");
					mvscanw(28,34,"%d",&tordestino);
					mvprintw(28,4,"Introdusca torre destino:");
				}
				movim++;
	
			}while(tordestino<1 || tordestino>3 || tordestino==tororigen);
			if(tororigen==1 && tordestino==2)
				Movimientos(&P1,&P2);
			if(tororigen==2 && tordestino==1)
				Movimientos(&P2,&P1);	
			if(tororigen==1 && tordestino==3)
				Movimientos(&P1,&P3);
			if(tororigen==3 && tordestino==1)
				Movimientos(&P3,&P1);
			if(tororigen==2 && tordestino==3)
				Movimientos(&P2,&P3);
			if(tororigen==3 && tordestino==2)
				Movimientos(&P3,&P2);
	}while(!(DiscosCont(P2)==numdisco || DiscosCont(P3)==numdisco));
	clear();
	PintarDisco(P1,P2,P3);	
	attron(COLOR_PAIR(10));
	Error("HAS GANADO",6);
	Ranking(numdisco,movim);
	second = time(NULL);
	tiempo=difftime(second,first);
	Tiemp(tiempo,numdisco,reg);
	attroff(COLOR_PAIR(10));
}

void PintarDisco(Pila P1,Pila P2,Pila P3)
{
	
	int tamaniodisco,discos1,discos2,discos3;
	Pila aux1;
	Pila aux2;
	Pila aux3;
	PilaVacia(&aux1);
	PilaVacia(&aux2);
	PilaVacia(&aux3);        
	discos1=DiscosCont(P1);
	discos2=DiscosCont(P2);
	discos3=DiscosCont(P3);
	PintarTorre();
	while(!EsVacia(&P1) || !EsVacia(&P2) || !EsVacia(&P3))
	{	
		if(!EsVacia(&P1))
		{
			tamaniodisco=Pop(&P1);
			Push(&aux1,tamaniodisco);
			AsignarColor(tamaniodisco,1,discos1);
			discos1=discos1-1;
		}
		if(!EsVacia(&P2))
		{			
			tamaniodisco=Pop(&P2);
			Push(&aux2,tamaniodisco);
			AsignarColor(tamaniodisco,2,discos2);
			discos2=discos2-1;
		}
		if(!EsVacia(&P3))
		{	
			tamaniodisco=Pop(&P3);
			Push(&aux3,tamaniodisco);
			AsignarColor(tamaniodisco,3,discos3);
			discos3=discos3-1;
		}
	}
	while(!EsVacia(&aux1) || !EsVacia(&aux2) || !EsVacia(&aux3))
	{		
		if(!EsVacia(&aux1))
			Colocar(&aux1,&P1);			
		if(!EsVacia(&aux2))
			Colocar(&aux2,&P2);			
		if(!EsVacia(&aux3))
			Colocar(&aux3,&P3);
	}
}

void CargarArchivo(FILE *archivo)
{
	char carac;
	attron(COLOR_PAIR(13));	
	while(!feof(archivo))
	{
		fscanf(archivo,"%c",&carac);
		printw("%c",carac);
	}
	attroff(COLOR_PAIR(13));
}

void PintarTorre()
{
      int i=25;
      int j=8;
      j=j*2;
     attron(COLOR_PAIR(7));
    do{
		mvprintw(i,20,"   ");//torre 1
		mvprintw(i,64,"   ");//torre 2
        mvprintw(i,108,"   ");//torre 3
		mvprintw(25,2,"                TORRE 1                ");	
		mvprintw(25,45,"                TORRE 2                ");
		mvprintw(25,88,"                 TORRE 3                ");
		j=j-1;
		i=i-1;
	}while(j!=0);
	attroff(COLOR_PAIR(7)); 
}

void AsignarColor(int tamaniodisco,int num,int discos)
{
	
	int fila,i;
	
	if(num==1)
		fila=19-(2*tamaniodisco);
	if(num==2)
		fila=63-(2*tamaniodisco);
	if(num==3)
		fila=107-(2*tamaniodisco);
	for(i=1;i<=(tamaniodisco*4)+3;i++)
	{
		if(tamaniodisco!=8)
		{
			attron(COLOR_PAIR(tamaniodisco));		
			mvprintw(25-discos,fila+i," ");	
			attron(COLOR_PAIR(tamaniodisco));
		}
		else
		{
			attron(COLOR_PAIR(4));		
			mvprintw(25-discos,fila+i," ");	
			attron(COLOR_PAIR(4));
		}
	}
	
}

int DiscosCont(Pila p)
{
	Pila ayuda;
	int  ndisco=0;
	PilaVacia(&ayuda);
	while(!EsVacia(&p))//mientras que p no este vacia
	{
	  ndisco=ndisco+1;
	  Colocar(&p,&ayuda);
	}
	while(!EsVacia(&ayuda))//mientras que la ayuda no este vacia
		Colocar(&ayuda,&p);
	return ndisco;
}

void Movimientos(Pila *origen,Pila *destino)
{
	if(!EsVacia(origen))
	{
		if(EsVacia(destino))
			Colocar(origen,destino);
		if(Cima(*destino)>Cima(*origen))
			Colocar(origen,destino);
	}
}	

void Colocar(Pila *origen,Pila *destino)
{
	int d;
	d=Pop(origen);
	Push(destino,d);
}

void Ranking(int numdisco,int movim)
{
	attron(COLOR_PAIR(14));
	mvprintw(5,4,"MOVIMIENTOS:");
	mvprintw(5,14," %d/%3.f",movim,(pow(2,numdisco))-1);
	if(numdisco==1 || numdisco== 2 || numdisco==3)
		Error("Nivel principiante",4);
	else 
		if(numdisco==4 || numdisco==5 || numdisco==6)
			Error("Nivel intermedio",4);
		else
			Error("Nivel avanzado",4);
	attroff(COLOR_PAIR(14));
}

void Tiemp(int tiempo,int ndisc, Rankin *reg)
{
	
	char no[20];
	int horas=0,minutos=0;
	if(tiempo>=60)
        {
            minutos=tiempo/60;
                  tiempo=tiempo%60;
        }
	else
	{
		mvprintw(6,4,"Tiempo: %d:%d:%d",horas,minutos,tiempo);
	}
    if(minutos>=60)
	{
		horas=minutos/60;
		minutos=minutos%60;
	}
	mvprintw(6,4,"Tiempo: %d:%d:%d",horas,minutos,tiempo);
	mvprintw(29,5,"Nombre:");
    //scanw("%s",reg.arreg);
    //mvprintw(29,5,"Introduce su Nombre otra vez:");
    scanw("%s",no);
    //LeerArchivoRanking(reg,ndisc);
    //strcpy(reg.arreg,no);
    //reg.arreg=no;
	//reg.t=tiempo
	LeerArchivoRanking(reg,ndisc);
	InsertarDato(reg,tiempo,no,ndisc);
	//LeerArchivoRanking(&reg,ndisc);
	
}

void LeerArchivoRanking(Rankin *nomj,int ndisc)
{
	FILE *arch;
	char cad[450];
	int cont=5;
	initscr();
	keypad(stdscr, TRUE);
	switch(ndisc)
	{
		case 1:
			if ((arch = fopen("./N1cd1.txt", "r"))	 == NULL)
			{
					fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			}
			else
			{
				while (!feof(arch))
				{
					if (fgets(cad,449,arch) != NULL)
					{
						SeparaCadRanking(nomj,&cont,cad);
				
					}
				}
			}
			fclose(arch);
		break;
		case 2:
			if ((arch = fopen("./N1cd2.txt", "r"))	 == NULL)
			{
					fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			}
			else
			{
				while (!feof(arch))
				{
					if (fgets(cad,449,arch) != NULL)
					{
						SeparaCadRanking(nomj,&cont,cad);
				
					}
				}
			}
			fclose(arch);
		break;
		case 3:
			if ((arch = fopen("./N1cd3.txt", "r"))	 == NULL)
			{
					fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			}
			else
			{
				while (!feof(arch))
				{
					if (fgets(cad,449,arch) != NULL)
					{
						SeparaCadRanking(nomj,&cont,cad);
				
					}
				}
			}
			fclose(arch);
		break;
		case 4:
			if ((arch = fopen("./N2cd4.txt", "r"))	 == NULL)
			{
					fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			}
			else
			{
				while (!feof(arch))
				{
					if (fgets(cad,449,arch) != NULL)
					{
						SeparaCadRanking(nomj,&cont,cad);
				
					}
				}
			}
			fclose(arch);
		break;
		case 5:
			if ((arch = fopen("./N2cd5.txt", "r"))	 == NULL)
			{
					fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			}
			else
			{
				while (!feof(arch))
				{
					if (fgets(cad,449,arch) != NULL)
					{
						SeparaCadRanking(nomj,&cont,cad);
				
					}
				}
			}
			fclose(arch);
		break;
		case 6:
			if ((arch = fopen("./N2cd6.txt", "r"))	 == NULL)
			{
					fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			}
			else
			{
				while (!feof(arch))
				{
					if (fgets(cad,449,arch) != NULL)
					{
						SeparaCadRanking(nomj,&cont,cad);
				
					}
				}
			}
			fclose(arch);
		break;
		case 7:
			if ((arch = fopen("./N3cd7.txt", "r"))	 == NULL)
			{
					fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			}
			else
			{
				while (!feof(arch))
				{
					if (fgets(cad,449,arch) != NULL)
					{
						SeparaCadRanking(nomj,&cont,cad);
				
					}
				}
			}
			fclose(arch);
		break;
		case 8:
			if ((arch = fopen("./N3cd8.txt", "r"))	 == NULL)
			{
					fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
			}
			else
			{
				while (!feof(arch))
				{
					if (fgets(cad,449,arch) != NULL)
					{
						SeparaCadRanking(nomj,&cont,cad);
				
					}
				}
			}
			fclose(arch);
		break;
	}
}

void SeparaCadRanking(Rankin *nomj,int *cont,char *cad)
{
	int campo,i,j;
	char subc[200];
	for (campo=0,i=0, j=0; i < strlen(cad);i++)
	{
		if (cad[i] != '\t' && cad[i] != '\n')
			subc[j++]= cad[i];
		else
		{
			subc[j] = '\0';
			j = 0;
			campo++;
			switch (campo)
			{case 1 : nomj[*cont].lugar = atoi(subc);
						break;
				case 2 :// nomj[*cont].arreg = (char *) malloc(strlen(subc));
						strcpy(nomj[*cont].arreg,subc);
						break;
				case 3 : nomj[*cont].t = atoi(subc);
						break;
			}
		}
		
	}
	(*cont)++;

}

void GuardarRanking(Rankin *nomj,int ndisc)
{
	int i;
	FILE *arch;
	int cont=5;
	switch(ndisc)
	{
		case 1:
			if ((arch = fopen("./N1cd1.txt", "w"))	 == NULL)
			{
				fprintf(stderr, "No se puede abrir el archivo de salida.\n");
				return;
			}
			for (i=0; i < cont; i++)
				fprintf(arch,"%d\t%s\t%d\n",nomj[i].lugar,nomj[i].arreg,nomj[i].t);
			fclose(arch);
		break;
		case 2:
			if ((arch = fopen("./N1cd2.txt", "w"))	 == NULL)
			{
				fprintf(stderr, "No se puede abrir el archivo de salida.\n");
				return;
			}
			for (i=0; i < cont; i++)
				fprintf(arch,"%d\t%s\t%d\n",nomj[i].lugar,nomj[i].arreg,nomj[i].t);
			fclose(arch);
		break;
		case 3:
			if ((arch = fopen("./N1cd3.txt", "w"))	 == NULL)
			{
				fprintf(stderr, "No se puede abrir el archivo de salida.\n");
				return;
			}
			for (i=0; i < cont; i++)
				fprintf(arch,"%d\t%s\t%d\n",nomj[i].lugar,nomj[i].arreg,nomj[i].t);
			fclose(arch);
		break;
		case 4:
			if ((arch = fopen("./N2cd4.txt", "w"))	 == NULL)
			{
				fprintf(stderr, "No se puede abrir el archivo de salida.\n");
				return;
			}
			for (i=0; i < cont; i++)
				fprintf(arch,"%d\t%s\t%d\n",nomj[i].lugar,nomj[i].arreg,nomj[i].t);
			fclose(arch);
		break;
		case 5:
			if ((arch = fopen("./N2cd5.txt", "w"))	 == NULL)
			{
				fprintf(stderr, "No se puede abrir el archivo de salida.\n");
				return;
			}
			for (i=0; i < cont; i++)
				fprintf(arch,"%d\t%s\t%d\n",nomj[i].lugar,nomj[i].arreg,nomj[i].t);
			fclose(arch);
		break;
		case 6:
			if ((arch = fopen("./N2cd6.txt", "w"))	 == NULL)
			{
				fprintf(stderr, "No se puede abrir el archivo de salida.\n");
				return;
			}
			for (i=0; i < cont; i++)
				fprintf(arch,"%d\t%s\t%d\n",nomj[i].lugar,nomj[i].arreg,nomj[i].t);	
			fclose(arch);
		break;
		case 7:
			if ((arch = fopen("./N3cd7.txt", "w"))	 == NULL)
			{
				fprintf(stderr, "No se puede abrir el archivo de salida.\n");
				return;
			}
			for (i=0; i < cont; i++)
				fprintf(arch,"%d\t%s\t%d\n",nomj[i].lugar,nomj[i].arreg,nomj[i].t);
			fclose(arch);
		break;
		case 8:
			if ((arch = fopen("./N3cd8.txt", "w"))	 == NULL)
			{
				fprintf(stderr, "No se puede abrir el archivo de salida.\n");
				return;
			}
			for (i=0; i < cont; i++)
				fprintf(arch,"%d\t%s\t%d\n",nomj[i].lugar,nomj[i].arreg,nomj[i].t);
			fclose(arch);
		break;
	}
}

void InsertarDato(Rankin *nomj,int tiempo,char *cad, int disco)
{
	int i, j = - 1, band,cont=5;
	for (i = 0, band = 0; i < cont && band == 0; i++)
	{
		if (tiempo <= nomj[i].t)
		{
			if(tiempo == nomj[i].t)
			{
				j=i;
			}
			if(tiempo < nomj[i].t && j == - 1)
			{
				RecorrerDato(nomj, i);
				nomj[i].arreg = (char *) malloc(strlen(cad));
				strcpy(nomj[i].arreg, cad);
				nomj[i].t = tiempo;
				nomj[i].lugar = i + 1;
				band = 1;
			}
		}
	}
	if(j != -1)
	{
		RecorrerDato(nomj, j);
		//strcpy(nomj[*cont].arreg,cad);
		nomj[j+1].arreg = (char *) malloc(strlen(cad));
		strcpy(nomj[j+1].arreg, cad);
		nomj[j+1].t = tiempo;
		nomj[i+1].lugar = j+1;
		
	}
}

void RecorrerDato(Rankin *nomj, int in)
{
	int i;
	int cont=5;
	for(i= cont-2; i >= 0 && i >= in; i--)
	{
		nomj[i+1]=nomj[i];
		nomj[i+1].lugar = i + 2; 
	}
}
