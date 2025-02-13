/* UNSIS- Licenciatura en Informática
	Nombre: Cambio.c
	Descripcion:   
	Autor: Raul (MEGA)
	fecha: 6 de mayo del 2011
*/

/* DIRECTIVA DE PREPROCESAMIANTOS*/
#include <stdio.h>
#define M 1001
#define N 3

/* DECLARACION DE VARIABLES GLOBALES Y FUNCIONES*/
void Cambio (int x, float mt, float p, float Mat[M][N]);
void Imprimir (int x, float Mat[M][N]);

/*DEFINICION DE LA FUNCION PRINCIPAL*/
int main() 
{
	float mon_to, pago; 
	float Mat[M][N];
	int opc2, i=0;
	char opc;
	do
	{
		printf("\n                       MENÚ  \n");
		printf("                 1 :  Calcular cambio\n");
		printf("            2 :  Ver registro de ventas y cambios\n");
		printf("\n¿Qué desea hacer?\n");
		scanf("\n%d",&opc2);
		if (opc2 > 0 && opc2 < 3)
		{
			if (opc2 == 1)
			{	
				printf("Introduce la cantidad del monto total:\n");
				scanf("\n%f",&mon_to);
				printf("Introduce la cantidad pagada:\n");
				scanf("\n%f",&pago);
				Cambio (i, mon_to, pago, Mat);
			}
			if (opc2 == 2)
			{
				Imprimir( i, Mat);
			}
		}
		else
		{
			printf("\n E L	   N Ú M E R O   D E   L A   O P C I Ó N   E S   I N C O R R E C T A\n");
		}

				
			printf("\n¿Desea realizar otro cálculo? s/n \n");
			scanf("\n%c",&opc);
			if (opc == 's' || opc == 'S')
			{
				i++;
			}
	}while (opc == 's' || opc == 'S' || i < M );
	return 0;
}
  
  
  
  
void Cambio (int x, float mt, float p, float Mat[M][N])

{
	int mil=0, qui=0, dosc=0, cien=0, cinc=0, vein=0, diez=0, cinco=0, dos=0, peso=0, cicc=0;
	float res;
	res = p - mt;

	if (res > 0)
	{  
		Mat[x][0]= mt;
		Mat[x][1]=p;
		Mat[x][2]=res;
		printf("El cambio total es: %f\n",res);
		while(res>=1000)
		{
			res=res-1000;
			mil=mil+1;
		}
	
		while (res>=500)
		{
			res=res-500;
			qui=qui+1;
		}
	
		 while(res>=200)
		 {
			res=res-200;
			dosc=dosc+1;
		 }
	
		while(res>=100)
		{
			res=res-100;
			cien=cien+1;
		}
	
		while(res>=50)
		{
			res=res-50;
			cinc=cinc+1;
		}
	
		while(res>=20) 
		{
			res=res-20;
			vein=vein+1;
		}
	
		while(res>=10)
		{
			res=res-10;
			diez=diez+1;
		}
	
		while (res>=5)
		{
			res=res-5;
			cinco=cinco+1;
		}
	
		while (res>=2) 
		{
			res=res-2;
			dos=dos+1;
		}
	
		while (res>=1) 
		{
			res=res-1;
			peso=peso+1;
		}
	
		while (res>=0.5)
		{ 
			res=res-0.5;
			cicc=cicc+1;
		}
		printf("\n    B I L L E T E S \n");
		printf("Billetes de a mil: %d\n",mil);
		printf("Billetes de a quinientos: %d\n",qui);
		printf("Billetes de a doscientos: %d\n",dosc);
		printf("Billetes de a cien: %d\n",cien);
		printf("Billetes de a cincuenta: %d\n",cinc);
		printf("Billetes de a veinte: %d\n",vein);
		printf("\n     M O N E D A S \n");
		printf("Monedas de a diez: %d\n",diez);
		printf("Monedas de a cinco: %d\n",cinco);
		printf("Monedas de a dos: %d\n",dos);
		printf("Monedas de a peso: %d\n",peso);
		printf("Monedas de a cincuenta centavos: %d\n",cicc);
	}
	else
	{
		printf("        N O   H A Y   D E V O L U C I Ó N   D E   C A M B I O \n ");
	}
}	


void Imprimir (int x, float Mat[M][N])

{
	int ind1, ind2;
	
	if (x == 0)
	{
		printf("\n           N O   H A Y   E L E M E N T O S");
	}
	else
	{
		printf("\nLista                   Venta                           Pago                      cambio         ");
		for (ind1 = 0; ind1 < x; ind1++)	
		{
			printf("\n%d",ind1);
			for (ind2 = 0; ind2 < N; ind2++)
			{
				printf("                      %f ", Mat[ind1][ind2]);
			}
			printf("\n");
		}
		printf("Total");
		for (ind1 = 0; ind1 < x; ind1++)
		{
			for (ind2 = 0; ind2 < N; ind2++)
			{
				if(ind2==0)
				{
					Mat[x][0]= Mat[x][0] + Mat[ind1][ind2];
				}
				if(ind2==1)
				{
					Mat[x][1]= Mat[x][1] + Mat[ind1][ind2];
				}
				if(ind2==2)
				{
					Mat[x][2]= Mat[x][2] + Mat[ind1][ind2];
				}
			}
		}
		for (ind2 = 0; ind2 < N; ind2++)
		{
			printf("                       %f ", Mat[x][ind2]);
		}
	}
}
			
