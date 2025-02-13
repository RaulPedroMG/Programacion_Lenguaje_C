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
	int opc 1;
	While (opc==1)
	{
		printf("Introduce la cantidad de grados °F:");
		scanf("%f",&f);
		c=f+32;
		printf("Los grados son:%f",c);
		printf("¿desea realizar otro cálculo? si=1 y no=0");
		scanf("%d",&opc);
	}
	return 0;
}
  
