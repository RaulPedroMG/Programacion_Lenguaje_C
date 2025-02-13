/*UNIVERSIDAD DE LA SIERRA SUR - LICENCIATURA EN INFORMATICA
 * Nombre: tamtipod.c
 * 	Descripción: Este programa despliega el n£mero de bytes que utiliza cada
							tipo de dato en C.
 * 	Autor: SKRV
 * 	Fecha: 13 de Marzo de 2009
	
*/
#include <stdio.h>

int main()
{
	int entero,*apint;
	float real, *apfloat;
	double reald, *apdouble;
	char car, *apchar;
	short entcorto, *apshort;
	long entlargo, *aplong;
	
  
	printf("\nTAMAÑO EN BYTES DE LOS TIPOS DE DATOS EN C");
	printf("\nTipo de dato      Número de bytes");
	printf("\n    char               %02d",sizeof(car));
	printf("\n    Apuntador a char   %02d",sizeof(apchar));
	printf("\n    int                %02d",sizeof(entero));
	printf("\n    Apuntador a entero %02d",sizeof(apint));
	printf("\n    short              %02d",sizeof(entcorto));
	printf("\n    Apuntador a short  %02d",sizeof(apshort));
	printf("\n    long int           %02d",sizeof(entlargo));
	printf("\n    Apuntador a long   %02d",sizeof(aplong));
	printf("\n    unsigned int       %02d",sizeof(unsigned int));
	printf("\n    float              %02d",sizeof(real));
	printf("\n    Apuntador a float  %02d",sizeof(apfloat));
	printf("\n    double             %02d",sizeof(reald));
	printf("\n    Apuntador a double %02d",sizeof(apdouble));
	return 0;
}
