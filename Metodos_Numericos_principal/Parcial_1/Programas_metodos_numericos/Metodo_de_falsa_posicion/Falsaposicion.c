#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float funcion(float x)
{
	return sin(x);
}	

int main()
{
	
	int i=0;
	float x0, x1, tol,f0, f1, x;
	system("reset");
	printf("\n\tMÉTODO DE FALSA POSICIÓN\n");
	printf("Introduce un rango en donde crees que puede haber una solución de la función.\n");
	scanf("%f", &x0);
	scanf("%f", &x1);
	printf("Introduce una tolerancia del error\n");
	scanf("%f", &tol);
	FILE *cmd = fopen("Comandos.dat","wt");
	fprintf(cmd, "plot sin(x)\n");
	fprintf(cmd,"set xrange[1.5:4]\n");
	fprintf(cmd,"set yrange[-0.5:1]\n");
	fprintf(cmd,"replot\n");
	fprintf(cmd,"unset key\n");
	fprintf(cmd,"set title \"Graficación del Método de falsa posición\"\n");
	fprintf(cmd,"set label \"Metodos numericos\" at 2.6,1.02\n");
	fprintf(cmd, "plot sin(x)\n");
	fprintf(cmd, "replot 0\n");
	f0 = funcion(x0);
	f1 = funcion(x1);
	if(f0 * f1 <=0)
	{
		while(f1 * f1 > tol * tol)
		{
				i++;
				fprintf(cmd,"set arrow from %f,%f to %f,%f\n",x0,f0,x1, f1);
				x = x0 - ((f0 * (x1 - x0))/(f1 - f0));
				printf("%d° Aproximacion = %f\n",i, x);
				f1 = funcion(x);
				x1 = x;
				fprintf(cmd, "replot\n");
		}
	}
	if(f1 * f1 > tol * tol)
		printf("\nNo se ha encontrado ningúna solución o hay mas de dos soluciones, por favor intente con otro rango");
	else
		printf("\nLa raíz de la función sin(x) es aproximadamente de : %f\n\n",x);
	fclose(cmd);
	return 0;
}
