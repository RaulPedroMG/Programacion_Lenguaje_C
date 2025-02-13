/*UNIVERSIDAD DE LA SIERRA SUR - LICENCIATURA EN INFORMATICA
 * Nombre: apchar.c
 * Descripción: Este programa almacena caracteres y los manipula a través
 * 				de su dirección de memoria.
 * 	Autor: SKRV
 * 	Fecha: 30 de mayo de 2011
	
*/
#include <stdio.h>

int main()
{
	char u,v,*apu, *apv;	
  	printf("\nAPUNTADORES");
  	u = 'A';
  	apv = &v;
  	*apv = u+5;
  	apu = &u;
  	printf("\nVariable u direccion: %p  contenido: %c",apu,u);
  	printf("\nVariable v direccion: %p  contenido: %c",apv,v);
	return 0;
}


/*	Preguntas.
 * ¿Que valor es asignado a apu?
 * ¿Que valor es representtado por *apv?
 * ¿Que valor es asignado a v?
 * ¿Que valor es representado por &u?
 * 
 */
