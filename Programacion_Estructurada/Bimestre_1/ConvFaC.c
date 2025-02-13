/* UNSIS- Licenciatura en Informática
	Nombre: Conversion.C
	Descripcion: Convirte grados Farhengint(°F) a Celcius(°C) las veces que el usuario 
		quiera realizar la acción y el usuario mismo indica el finalizamiento del programa.  
	Autor: Raul (MEGA)
	fecha: 15 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	float f,c;
	int opc=1;
	while (opc==1)
	{
		printf("Introduce la cantidad de grados °F:\n");
		scanf("%f",&f);
		c=(f-32.0)*(5.0/9.0);
		printf("Los grados son:  %f",c);
		printf(" °C");
		printf("\n");
		printf("¿desea realizar otro cálculo? si=1 y no=0\n");
		scanf("%d",&opc);
	}
	return 0;
}
  
