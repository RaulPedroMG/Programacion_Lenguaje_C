/* UNSIS- Licenciatura en Informática
	Nombre: FuncionFecha.c
	Descripcion: El algoritmo manda lee una fecha en el orden del dia, mes y año, 
		posteriormente manda estos valores a una funcion la cual verifica si 
		la fecha es valida o invalida tomando el rango de 01/01/1900 al 17/03/2011, 
		si esta en este rango es valida de lo contrario es invalida.
	Autor: Raul (MEGA)
	fecha: 15 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int Fecha (int d, int m, int a);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	int dia,mes,ano,dma;
	printf("Introduce el número del dia:\n");
	scanf("%d",&dia);
	printf("Introduce el número del mes:\n");
	scanf("%d",&mes);
	printf("Introduce el año (4 digitos):\n");
	scanf("%d",&ano);
	dma=Fecha(dia, mes, ano);

	if(dma == 1)
		printf("La fecha es valida\n");
	else
		printf("La fecha es invalida\n");
	printf("\n");
	return 0;
}


/*DEFINICION DE FUNCIONES*/
int Fecha (int d, int m, int a)
/*VERIFICA SI LA FECHA ES VALIDA O NO*/
{
	int fec=0;
	if(a >= 1900 && a <= 2010)
	{
		if(m >= 1 && m <= 12)
		{
			if(m == 2)
			{
				if(a % 400 == 0 && a % 4 == 0)
				{
					if(d >= 1 && d <= 29)
					{
						fec=1;
					}
				}	
				else	
				{
					if(d >= 1 && d <= 28)
					{
						fec=1;
					}
				}
			}
			else
			{
				if(m ==4  || m == 6 || m == 9 || m == 11)
				{
					if(d >= 1 && d <= 30)
					{
						fec=1;
					}
				}
				else
				{	
					if(m ==1  || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
					{
						if(d >= 1 && d <= 31)
						{
						fec=1;
						}
					}	
				}		
			}
		}
	}	
	else
	{
		if(a == 2011)
		{
			if(m >= 1 && m <=3)
			{
				if(m == 1)
				{
					if(d >= 1 && d <= 31)
					{
						fec=1;
					}
				}
				else
				{
					if(m == 2)
					{
						if(d >= 1 && d <= 28)
						{
							fec=1;
						}
					}	
					else
					{
						if(m == 3)
						{
							if(d >= 1 && d <= 17)
							{
								fec=1;
							}
						}	
					}	
				}
			}
		}
	}
	return fec;
}
