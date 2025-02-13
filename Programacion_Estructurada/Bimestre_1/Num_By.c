/* UNSIS- LI
	Nombre: Ejercicio1.C
	Descripcion: Calcula numero de bytes que utiliza cada tipo de dato basico en C.
	Autor: Raul (MEGA)
	fecha: 10 de marzo del 2011
*/

#include <stdio.h>

int main()
{
	char c;
	int i;
	short s;
	long l;
	float f;
	double d;
	printf("\nTAMAÑO DE BYTES DE LOS TIPOS DE DATOS BASICOS EN C:");
	printf("\nTIPO DE DATO \t TAMAÑO");
	printf("\n char \t\t %2d", sizeof(c));
	printf("\n int \t\t %2d", sizeof(i));
	printf("\n short \t\t %2d", sizeof(i));
	printf("\n long \t\t %2d", sizeof(s));
	printf("\n float \t\t %2d", sizeof(f));
	printf("\n double \t %2d\n", sizeof(d));
	return 0;
}
