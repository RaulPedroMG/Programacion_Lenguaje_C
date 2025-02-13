#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "torres.h"
#include "variables.h"
#include "pilas.h"
#include "formato.h"
#include "archivos.h"


void GuardarEmp(Ranking *Lista,int contj,char *nom)
{
	int i;
	FILE *archemp;
	if((archemp=fopen(nom,"wb"))==NULL){
		fprintf(stderr,"No se pudo abrir el archivo");
		return;
	}
	for(i=0;i<contj;i++){
		fwrite(&archemp[i],sizeof(Ranking),1,archemp);
	}
	fclose(archemp);
	return;
}

void LeerEmp(Ranking *Lista,int *contj,char *nom)
{
	FILE *archemp;
	if((archemp=fopen(nom,"rb"))==NULL){
		fprintf(stderr,"No se pudo abrir el archivo");
		return;
	}
	while(!feof(archemp) && *contj<ML){
		if(fread(&Lista[*contj],sizeof(Ranking),1,archemp)>0){
			(*contj)++;
		}
	}
	fclose(archemp);
	return;
}

void ImprimirRes(int i,Ranking lista[ML])
{
	echo();
	printw("\t%3d",i+1);
	printw("\t%3s",lista[i].nombre);
	printw("\t%3d",lista[i].nudis);
	printw("\t%3d\n",lista[i].tiempo);
	return;
}

void ImprimirDatos(Ranking lista[ML], int *contj,char *nivel)
{
	int i;
	if(*contj==0){
		echo();
		Centrar("No hay datos,presione una tecla para salir",10);
		getch();
	}else{
		echo();
		printw("\t %s \n",nivel);
		printw("\tN°\tNombre\tN° disco\tTiempo\n");
		for(i=0;i<*contj;i++){
			ImprimirRes(i,lista);
		}
	}
	getch();
	return;
}

void ingresardatos(Ranking Lista1[ML],int nd,char nom[15],int DIF,int *indice)
{
	int i,band=0,j;
	switch (nd){
		case 1:
			if(*indice==0){
				LeerEmp(Lista1,indice,"lis1.dat");
				strcpy(Lista1[0].nombre,nom);
				Lista1[0].nudis=nd;
				Lista1[0].tiempo=DIF;
				(*indice)++;
			}else{
					for(i=0;i<*indice-1 && band==0;i++){
						if(Lista1[i].tiempo <= DIF){
							for(j=*indice-1;j>i;j--){
								Lista1[j]=Lista1[j-1];
							}
							strcpy(Lista1[i].nombre,nom);
							Lista1[i].nudis=nd;
							Lista1[i].tiempo=DIF;
							(*indice)++;
							band=1;
						}
					}	
			}
			break;
	}
}

int busm(Ranking Lista1[ML], int DIF,int indice)
{
	 int band=0,i;
	 for(i=0; i<indice && band==0; i++){
		 if (Lista1[i].tiempo==DIF){
			 band=1;
		 }
	 }
	 return i;
}
	
void MoverR(int ind, Ranking Lista1[ML], int *indice)
{
	int j;
	for(j=*indice; j>ind; j--){
		Lista1[j]=Lista1[j-1];
	}
}
