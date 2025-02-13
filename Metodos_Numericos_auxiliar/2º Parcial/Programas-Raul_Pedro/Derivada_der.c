#include <stdio.h>
#include <stdlib.h>

float f(float x){
	return x*x;
}

int main (){
	float x, xi, xf, fun, dfun, delta, der;
	int n, i;
	FILE *salida;
	char archivo[30];
	printf("Introduce el valor de x inicial\n");
	scanf("%f", &xi);
	printf("Introduce el valor de x final\n");
	scanf("%f", &xf);
	printf("Introduce número de interacciones\n");
	scanf("%d", &n);
	printf("Introduce el nombre del archivo : \n");
	scanf("%s", archivo);
	delta = (xf - xi) / n;
	x = xi;
	salida = fopen(archivo, "w");
	for(i = 0; i < n; i++)
	{
		//fun = x * x;
		//dfun = (x + delta) * (x + delta);
  		//der = (dfun - fun) / delta;
  		der = (f(x + delta) - f(x)) / delta;
		fprintf(salida,"%f	%f\n", x , der);
		x = x + delta;
	}
	fclose(salida);
	return 0;
}

