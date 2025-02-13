#include <stdio.h>
#include <math.h>


float funcion(float x)
{
	return  (x*x-x+1)*cos(x*x); //(x-sin(x)); 
}
int main()
{
	float a,b,m,error,eps;
	int N,i;

	printf("\n***METODO DE BISECCION***\n");
	printf ("Introduce los extremos: ");
	scanf("%f %f",&a, &b);
	printf("Introduce el numero de iteraciones: ");
	scanf ("%d",&N);
	printf ("Tolerancia del error: ");
	scanf ("%f",&eps);
	FILE *cmd = fopen("Comandos.dat","wt");
	fprintf(cmd, "plot sin(x)\n");
	fprintf(cmd,"set xrange[2:5]\n");
	fprintf(cmd,"set yrange[-2:2]\n");
	fprintf(cmd,"replot\n");
	fprintf(cmd,"unset key\n");
	fprintf(cmd,"set title \"Metodos numericos                     Graficación del Método de Newton\"\n");
	fprintf(cmd, "plot sin(x)\n");
	fprintf(cmd, "replot 0\n");
	i = 1;
	error = eps*10;
	while (error>eps && i < N)
	{
		m = (a+b)/2;
		printf ("Solucion:%f\n",m);
		if (funcion(a)*funcion(m)<0)
			b = m;
		else
			a = m;
		i++;
		error = fabs(funcion(m));
		fprintf(cmd,"set arrow from %f,0 to %f,%f\n",a,a, funcion(a));
		fprintf(cmd,"set arrow from %f,0 to %f,%f\n",b,b, funcion(b));
		fprintf(cmd, "replot\n");
	}
	printf ("La solucion alcanzada para la funcion es: %f\n",m);
	printf("Numero de iteraciones: %d de %d\n",i,N);
	return 0;
}

