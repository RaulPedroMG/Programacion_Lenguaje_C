/*
 * cola.h
 * Autores: Heriberto López Ramirez
 * 			Flavio Juárez Martínez
 * 			Flavio Gonzalez Reyes
*/

#include <stdio.h>
#define Max 10


typedef struct{
int arreglo[Max];
int final;
int frente;
}cola;

void CrearCola (cola *c);//Crea una cola
int ColaVacia (cola *c);//Verifica si la cola esta vacia
int ColaLlena (cola *c);//Verifica si la cola esta llena.
void InsertarFinal(cola *c,int x);//Inserta un elemento al final de la cola

void InsertarFrente(cola *c,int x);//Inserta un elemento al frente de la cola

void EliminarFrente(cola *c,int *x);//Elimina "regresa" el elemento que esta al frente de  la cola

void EliminarFinal(cola *c,int *x);//Elimina "regresa" el elemento que esta al final de  la cola 
