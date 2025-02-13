/*
 *  Pila.h
 *  
 *
 *  Created by Víctor Gómez on 21/10/11.
 *  Copyright 2011 UNSIS. All rights reserved.
 *
 */

#include <stdio.h>
#define MAX 10


typedef struct{
int arreglo[MAX];
int tope;
}Pila;

void PilaVacia (Pila *a);
int EsVacia (Pila *a);
int Cima (Pila a);
void Push (int x, Pila *a);
int Pop (Pila *a); 