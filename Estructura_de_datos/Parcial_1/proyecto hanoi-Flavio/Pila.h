/*
 *  Pila.h
 *  
 *
 *  Created by Víctor Gómez on 21/10/11.
 *  Copyright 2011 UNSIS. All rights reserved.
 *
 */
#include "ncurses.h"
#include <stdio.h>
#define MAX 8


typedef struct
{
	int arreglo[MAX];
	int tope;
}Pila;

void PilaVacia (Pila *a);
int EsVacia (Pila *a);
int EsLlena(Pila *a);
int Cima (Pila a);
void Push (Pila *a,int x );
int Pop (Pila *a); 
