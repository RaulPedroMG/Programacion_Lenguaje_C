#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <ctype.h>
#include "validaciones.h"
#include "formato.h"
#include "lista.h"
#include "FunCalcula.h"

int contarletras(char *palabra)
{
	int i,j=0;
	for(i=0;palabra[i]!='\0';i++){
		if(palabra[i]!='-'){
			j++;
		}
	}
	return j;
}
int MenuAd()
{
	int j;
	clear();
	keypad(stdscr, TRUE);
	echo();
	attron(COLOR_PAIR(10));
	marco(5,36,78,30,' ',' ');
	mvprintw(7,64,"Opciones de calculadora");
	mvprintw(8,68,"Lic. INFORMATICA");
	mvprintw(16,50,"1.- S U M A");
	mvprintw(18,50,"2.- R E S T A");
	mvprintw(20,50,"3.- M U L T I P L I C A C I O N");
	mvprintw(22,50,"4.- S A L I R");
	mvprintw(24,50,"ELIJE UNA OPCION");
	attroff(COLOR_PAIR(10));
	attron(COLOR_PAIR(3));
	j=Rango(1,4,24,73);
	attroff(COLOR_PAIR(3));
	return j;
}

void Leernumero(char *num1,char *num2, char *op){
	Centrar(op,2);
	attron(COLOR_PAIR(3));
	mvprintw(4,4,"Ingresa el primer número");
	LeeEntero(num1,1000,4,35);
	mvprintw(10,4,"Ingresa el segundo número");
	LeeEntero(num2,1000,10,35);
	attroff(COLOR_PAIR(3));
}

void Agregarlista(char *num1,char *num2,struct nodo **lista1,struct nodo **lista2, int opc, int *neg)
{
	int i,j,num_1,num_2,band1=0,band2=0; 
	char valor[2];
	if(opc == 1){
		crearLista(lista1);
		crearLista(lista2);
		for(i=0;band1==0 || band2 == 0;i++){
			if(num1[i]=='\0')
				band1=1;
			if(num2[i]=='\0')
				band2=1;
			if(band1 == 0){
				valor[0]=num1[i];
				valor[1]='\0';
				num_1=atoi(valor);
				InserPrim(num_1,lista1);
			}
			if(band2 == 0){
				valor[0]=num2[i];
				valor[1]='\0';
				num_2=atoi(valor);
				InserPrim(num_2,lista2);
			}
		}
	}
	if (opc == 2)
	{
		//Borrar ceros que estan inicio
		for(i = 0; num1[i] != '\0' && num1[i] == '0'; i++){
		}
		for(j = 0; num1[i] != '\0' ; j++){
			num1[j]=num1[i];
			i++;
		}
		num1[j]= '\0';
		if(strlen(num1)== 0){ //Asignar un cero si la cadena se vació
			num1[0] = '0';
			num1[1] = '\0';
		}
		//Borrar ceros que estan inicio
		for(i = 0; num2[i] != '\0' && num2[i] == '0'; i++){
		}
		for(j = 0; num2[i] != '\0' ; j++){
			num2[j]=num2[i];
			i++;
		}
		num2[j]= '\0';
		if(strlen(num2)== 0){ //Asignar un cero si la cadena se vació
			num2[0] = '0';
			num2[1] = '\0';
		}
		if(strlen(num2) > strlen(num1)){
			(*neg)=1;
		}
		if(strlen(num1) == strlen(num2)){ //Verificar si el primer unmero es menor que el segundo, si se cumple el resultado será negativo
			for(i=0;band1==0 || band2 == 0;i++){
				if(num1[i]=='\0')
					band1=1;
				if(num2[i]=='\0')
					band2=1;
				if(band1 == 0){
					valor[0]=num1[i];
					valor[1]='\0';
					num_1=atoi(valor);
				}
				if(band2 == 0){
					valor[0]=num2[i];
					valor[1]='\0';
					num_2=atoi(valor);
				}
				if(num_1 < num_2){ //Verificación de números
					band1 = 1;
					band2 = 1;
					(*neg) = 1;
				}
			}
		}
		if(*neg == 0){
			crearLista(lista1);
			crearLista(lista2);
			for(i=0;num1[i]!='\0';i++){
				valor[0]=num1[i];
				valor[1]='\0';
				num_1=atoi(valor);
				InserPrim(num_1,lista1);
			}
			for(i=0;num2[i]!='\0';i++){
				valor[0]=num2[i];
				valor[1]='\0';
				num_2=atoi(valor);
				InserPrim(num_2,lista2);
			}
		}
		if(*neg == 1){
			crearLista(lista1);
			crearLista(lista2);
			for(i=0;num1[i]!='\0';i++){
				valor[0]=num1[i];
				valor[1]='\0';
				num_1=atoi(valor);
				InserPrim(num_1,lista2);
			}
			for(i=0;num2[i]!='\0';i++){
				valor[0]=num2[i];
				valor[1]='\0';
				num_2=atoi(valor);
				InserPrim(num_2,lista1);
			}
		}
	}
	if(opc == 3){
		if(num1[0] == '-' && num2[0] == '-'){ // Verifica si los dos numeros son negativos, no se activa la veriable neg porque el resultado será positivo
			for(i = 1;num1[i] != '\0'; i++){ // Borra el signo y recorre los números para no tener problemas al llenar la lista
				num1[i-1] = num1[i];
			}
			num1[i-1] = '\0';
			for(i = 1;num2[i] != '\0'; i++){ // Borra el signo y recorre los números para no tener problemas al llenar la lista
				num2[i-1] = num2[i];
			}
			num2[i-1] = '\0';
		}
		if(num1[0] == '-' && num2[0] != '-'){ // verifica si se introdujo un número negativo
			for(i = 1;num1[i] != '\0'; i++){ // Borra el signo y recorre los números para no tener problemas al llenar la lista
				num1[i-1] = num1[i];
			}
			(*neg)=1; // Se activa la variable para indicar que el resultado será negativo
			num1[i-1] = '\0';
		}
		if(num1[0] != '-' && num2[0] == '-'){ // verifica si se introdujo un número negativo
			for(i = 1;num2[i] != '\0'; i++){ // Borra el signo y recorre los números para no tener problemas al llenar la lista
				num2[i-1] = num2[i];
			}
			(*neg)=1; // Se activa la variable para indicar que el resultado será negativo
			num2[i-1] = '\0';
		}
		//Borrar los ceros que estan inicio
		for(i = 0; num1[i] != '\0' && num1[i] == '0'; i++){
		}
		for(j = 0; num1[i] != '\0' ; j++){
			num1[j]=num1[i];
			i++;
		}
		num1[j]= '\0';
		if(strlen(num1)== 0){
			num1[0] = '0';
			num1[1] = '\0';
		}
		for(i = 0; num2[i] != '\0' && num2[i] == '0'; i++){
		}
		for(j = 0; num2[i] != '\0' ; j++){
			num2[j]=num2[i];
			i++;
		}
		num2[j]= '\0';
		if(strlen(num2)== 0){
			num2[0] = '0';
			num2[1] = '\0';
		}
		if(strlen(num1) < strlen(num2)){
			crearLista(lista1);
			crearLista(lista2);
			for(i=0;num1[i]!='\0';i++){
				valor[0]=num1[i];
				valor[1]='\0';
				num_1=atoi(valor);
				InserPrim(num_1,lista2);
			}
			for(i=0;num2[i]!='\0';i++){
				valor[0]=num2[i];
				valor[1]='\0';
				num_2=atoi(valor);
				InserPrim(num_2,lista1);
			}
		}else{
			crearLista(lista1);
			crearLista(lista2);
			for(i=0;num1[i]!='\0';i++){
				valor[0]=num1[i];
				valor[1]='\0';
				num_1=atoi(valor);
				InserPrim(num_1,lista1);
			}
			for(i=0;num2[i]!='\0';i++){
				valor[0]=num2[i];
				valor[1]='\0';
				num_2=atoi(valor);
				InserPrim(num_2,lista2);
			}
		}
	}
}

void sumar(struct nodo *lista1,struct nodo *lista2)
{
	int acarreo=0,suma=0, band;
	struct nodo *lista3;
	crearLista(&lista3);
	while(lista1 != NULL || lista2 != NULL)	/*; lista1=lista1->sig, lista2=lista2->sig){*/
	{
		if(lista1==NULL && lista2!=NULL)
		{
			if(acarreo==1)
			{
				lista2->info = lista2->info + acarreo;
			}
			suma=lista2->info;
			acarreo = suma / 10;
			suma = suma % 10;
			InserPrim(suma,&lista3);
			lista2=lista2->sig;
		}
		if(lista1!=NULL && lista2==NULL)
		{
			if(acarreo==1)
			{
				lista1->info = lista1->info + acarreo;
			}
			suma=lista1->info;
			acarreo = suma / 10;
			suma = suma % 10;
			InserPrim(suma,&lista3);
			lista1=lista1->sig;
		}
		if(lista1!=NULL && lista2!=NULL)
		{
			if(acarreo==1)
			{
				lista1->info = lista1->info + acarreo;
			}
			suma = lista1->info+lista2->info;
			acarreo = suma / 10;
			suma = suma % 10;
			InserPrim(suma,&lista3);
			lista1 = lista1->sig;
			lista2=lista2->sig;
		}
	}
	if(acarreo==1)
	{
		InserPrim(acarreo,&lista3);
	}
	band=0;
	do
	{
		if (lista3->info == 0)
			lista3=lista3->sig;
		else
			band=1;
	}while(lista3 != NULL && band==0);
	if(lista3 == NULL)
		InserPrim(0,&lista3);
	acarreo=0;
	attron(COLOR_PAIR(3));
	mvprintw(20,4,"La suma es:");
	implista(lista3);
	attroff(COLOR_PAIR(3));
}
void restar(struct nodo *lista1,struct nodo *lista2, int negativo)
{
	int prestamo=0, resta=0,band;
	struct nodo *lista3;
	crearLista(&lista3);
	while(lista1 != NULL || lista2 != NULL)	
	{
		if(lista1!=NULL && lista2==NULL)
		{
			if(prestamo==1)
			{
				if(lista1->info == 0)
				{
					prestamo=1;
				}
				lista1->info = lista1->info + 10;
				lista1->info = lista1->info - prestamo;
				lista1->info = lista1->info % 10;
			}
			resta=lista1->info;
			InserPrim(resta,&lista3);
			lista1=lista1->sig;
		}
		if(lista1!=NULL && lista2!=NULL)
		{
			if(lista1->info < lista2->info)
			{
				lista1->info = lista1->info + 10;
				if(prestamo==1)
				{
					lista1->info = lista1->info - prestamo;
				}
				resta=lista1->info - lista2->info;
				InserPrim(resta,&lista3);
				prestamo=1;
				lista1=lista1->sig;
				lista2=lista2->sig;
			}
			else
			{
				if(prestamo==1)
				{
					lista1->info = lista1->info - prestamo;
				}
				resta=lista1->info - lista2->info;
				InserPrim(resta,&lista3);
				lista1=lista1->sig;
				lista2=lista2->sig;
			}
		}
	}
	band=0;
	do
	{
		if (lista3->info == 0)
			lista3=lista3->sig;
		else
			band=1;
	}while(lista3 != NULL && band==0);
	if(lista3 == NULL)
		InserPrim(0,&lista3);
	if(negativo==1)
	{
		lista3->info = lista3->info * - 1; 
	}
	prestamo = 0;
	attron(COLOR_PAIR(3));
	mvprintw(20,4,"La resta es:");
	implista(lista3);
	printf("\n");
	attroff(COLOR_PAIR(3));
}

void multip(struct nodo *lista1,struct nodo *lista2,int negativo,char *num)
{
	int recorrer=0, acarreo=0, mult, suma, i;
	struct nodo *lista3;
	struct nodo *sumas;
	struct nodo *lista4;
	crearLista(&lista3);
	crearLista(&lista4);
	while(lista2 != NULL)
	{
		crearLista(&sumas);
		for(i=0;i < recorrer; i++)
			InserPrim(0,&sumas);
		do
		{
			mult = acarreo;
			mult = mult + (lista2->info * lista1->info); 
			acarreo = mult / 10;
			mult = mult % 10;
			InserPrim(mult,&sumas);
			lista1 = lista1->sig;
		}while(lista1 != NULL);
		if(acarreo > 0){
			InserPrim(acarreo,&sumas);
		}
		acarreo=0;
		// Volver a Lenar la lista2 por que ya no tiene elementos
		
		do
		{
			InserPrim(sumas->info,&lista3);
			sumas = sumas->sig;
		}while(sumas != NULL);
		LlenarL(num,&lista1);
		
	//**************************************************
		// Sumar la lista3 y la lista4
	//**************************************************
		while(lista3 != NULL || lista4 != NULL)	/*; lista1=lista1->sig, lista2=lista2->sig){*/
		{
			if(lista3==NULL && lista4!=NULL)
			{
				if(acarreo==1)
				{
					lista4->info = lista4->info + acarreo;
				}
				suma=lista4->info;
				acarreo = suma / 10;
				suma = suma % 10;
				InserPrim(suma,&sumas);
				lista4=lista4->sig;
			}
			if(lista3!=NULL && lista4==NULL)
			{
				if(acarreo==1)
				{
					lista3->info = lista3->info + acarreo;
				}
				suma=lista3->info;
				acarreo = suma / 10;
				suma = suma % 10;
				InserPrim(suma,&sumas);
				lista3=lista3->sig;
			}
			if(lista3!=NULL && lista4!=NULL)
			{
				if(acarreo==1)
				{
					lista3->info = lista3->info + acarreo;
				}
				suma = lista3->info+lista4->info;
				acarreo = suma / 10;
				suma = suma % 10;
				InserPrim(suma,&sumas);
				lista3 = lista3->sig;
				lista4 =lista4->sig;
			}
		}
		if(acarreo==1)
		{
			InserPrim(acarreo,&sumas);
		}
		do
		{
			InserPrim(sumas->info,&lista4);
			sumas = sumas->sig;
		}while(sumas != NULL);
		recorrer++;
		lista2 = lista2->sig;
	}
	do{
		InserPrim(lista4->info,&sumas);
		lista4 = lista4->sig;
	}while(lista4 != NULL);
	
	if(negativo==1)
	{
		sumas->info = sumas->info * - 1; 
	}
	
	attron(COLOR_PAIR(3));
	mvprintw(20,4,"La Multiplicación es:");
	implista(sumas);
	printf("\n");
	attroff(COLOR_PAIR(3));
}

void LlenarL(char *num,struct nodo **lista)
{
	int i, n;
	char valor[2];
	for(i = 0; num[i] != '\0'; i++){
		valor[0] = num[i];
		valor[1]='\0';
		n = atoi(valor);
		InserPrim(n,lista);
	}
}
