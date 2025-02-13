/* UNSIS- Licenciatura en Informática
	Nombre: FuncionFecha.c
	Descripcion: El algoritmo lee una fecha en el orden del dia, mes y año, 
		posteriormente manda estos valores a una funcion la cual imprimirá 
		la fecha siguiente.
	Autor: Raul (MEGA)
	fecha: 29 de marzo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
int V_Fecha (int d, int m, int a);
void F_Siguiente (int d, int m, int a);

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
	if (dma == 1)
	{
		F_Siguiente(dia, mes, ano);
	}
	else
	{
		printf("\nLa fecha es incorrecta\n");
	}
	printf("\n");
	return 0;
}



/*DEFINICION DE FUNCIONES*/
int V_Fecha (int d, int m, int a)
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





/*DEFINICION DE FUNCIONES*/
void F_Siguiente (int d, int m, int a)
/*VERIFICARÁ LA FECHA SIGUIENTE Y LO IMPRIMIRÁ*/
{
	
	if(m >= 1 && m <= 12)
	{
		if(m == 2)
		{
			if(a % 400 == 0 && a % 4 == 0)
			{
				if(d >= 1 && d <= 28)
				{
					d = d + 1;
				}
				else
				{
					if(d == 29)
					{
						m = m + 1;
						d = 1;
					}
				}	
			}	
			else	
			{
				if(d >= 1 && d <= 27)
				{
					d = d + 1;
				}				
				else
				{
					if(d == 28)
					{
						m = m + 1;
						d = 1;
					}
				}
			}
		}
		else
		{
			if(m ==4  || m == 6 || m == 9 || m == 11)
			{
				if(d >= 1 && d <= 29)
				{
					d = d + 1;
				}
				else
				{
					if(d == 30)
					{
						m = m + 1;
						d = 1;	
					}
				}
			}
			else
			{	
				if(m ==1  || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
				{
					if(d >= 1 && d <= 30)
					{
						d = d + 1;
					}
					else
					{
						if(d == 31)
						{
							m = m + 1;
							d = 1;	
						}
					}
				}
				else
				{
					if(m == 31)
					{
						if(d >= 1 && d <= 30)
						{
							d = d + 1;
						}
						else
						{
							if(d == 31)
							{
								m = 1;
								d = 1;
								a = a + 1;
							}	
						}
					}	
				}	
			}		
		}
	}
	printf("La fecha siguiente es:\n");
	printf("%d",d,"/","%d",m,"/","%d",a);
}
	
