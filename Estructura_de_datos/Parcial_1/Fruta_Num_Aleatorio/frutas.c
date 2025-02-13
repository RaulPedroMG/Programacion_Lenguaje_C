#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 15

int main()
{
	//Declarando un arreglo de cadenas
	char frutas[N][M]={"Mango","Manzana","Sandia","Melon","Guayaba",
	                   "Naranja","Lima","Piña","Uva","Durazno"};
	int i,num,frut_elegida;                   
	
	//Imprimiendo el arreglo frutas[i] (Arreglo de Cadenas)
	printf("Imprimiendo el arreglo Frutas:\n\n");
	for (i=0;i<N;i++)
	    printf("Fruta %d: %s\n",i,frutas[i]);    
	    
	/* ponemos la semilla para generar numeros aleatorios, la semilla 
	 es la hora actual */
	srand((unsigned) time(NULL)); 
     
	/* generamos un numero aleatorio */
	num = rand(); 
	printf("\nNumero aleatorio: %d\n", num); 
    
	/* generamos un numero aleatorio entre 0 y 9 */
	frut_elegida = rand() % 10; 
	printf("Numero entre 0 y 9: %d\n", frut_elegida); 
     
	/* generamos un numero aleatorio entre 1 y 10 */
	num = (rand() % 10) + 1; 
	printf("Numero entre 1 y 10: %d\n", num); 
	
    //Imprimiendo Fruta del arreglo frutas
	printf("\nLa Fruta elegida es: %s\n",frutas[frut_elegida]);
	               
	return 0;

}
