#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float funcion(float x)
{
	return (x*x*x)-(6*(x*x))+(8*x);
}

float funderiv(float x)
{
	return (3*(x*x))-(12*x)+8;
}

int main()
{
	int i=0;
	float xo, x,f,r,re,res;
	printf("\nMÉTODO DE NEWTON\n");
	printf("Da el punto de inicio: ");
	scanf("%f",&xo);
	FILE *cmd = fopen("Comandos.dat","wt");
	fprintf(cmd, "plot sin(x)\n");
	fprintf(cmd,"set xrange[2:5]\n");
	fprintf(cmd,"set yrange[-2:2]\n");
	fprintf(cmd,"replot\n");
	fprintf(cmd,"unset key\n");
	fprintf(cmd,"set title \"Graficación del Método de Newton\"\n");
	fprintf(cmd,"set label \"Metodos numericos\" at 3.0,2.1\n");
	fprintf(cmd, "plot sin(x)\n");
	fprintf(cmd, "replot 0\n");
	do
	{
		r=xo;
		re=funcion(xo);	
		x=xo-(funcion(xo)/funderiv(xo));
		res=x;
		xo=x;
		f=funcion(x);	
		printf("Aproximadamente de : %f\n",x);
		fprintf(cmd,"set arrow from %f,%f to %f,0\n",r,re,res);
		fprintf(cmd,"set arrow from %f,0 to %f,%f\n",res,x,f);
		fprintf(cmd, "replot\n");
	}while(f*f>0.0001);

	printf("\nLa raíz de la función sin(x) es: %f\n\n",x);
	fclose(cmd);
return 0;
}

