/*
 *  Pila.h
 *  
 *
 *  Created by Víctor Gómez on 21/10/11.
 *  Copyright 2011 UNSIS. All rights reserved.
 *
 */

#include <stdio.h>
#define MAX 30


typedef struct{
	char frase[MAX];
	int tope;
}Pila;

void PilaVacia (Pila *a);
int EsVacia (Pila *a);
int Cima (Pila a);
void Push (char x, Pila *a);
char Pop (Pila *a); 
