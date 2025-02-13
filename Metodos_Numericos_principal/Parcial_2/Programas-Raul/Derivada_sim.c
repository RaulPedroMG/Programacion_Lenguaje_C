#include <stdio.h>
#include <stdlib.h>

float f(float x){
	return x*x;
}

int main (){
	float x, xi, xf, fun, dfun, delta, sim;
	int n, i;
	char archivo[30];
	FILE *salida;
	printf("\nIntroduce el valor de x inicial : \n");
	scanf("%f",&xi);
	printf("\nIntroduce el valor de x final : \n");
	scanf("%f",&xf);
	printf("\nIntroduce número de interacciones : \n");
	scanf("%d",&n);
	printf("\nIntroduce el nombre del archivo : \n");
	scanf("%s", archivo);
	delta = (xf  - xi) / n;
	x = xi;
	salida = fopen(archivo, "w");
	for(i = 0; i < n; i++)
	{
		//fun = x * x;
		//dfun = (x - delta) * (x - delta);
  		//izq = (fun - dfun) / delta;
  		sim = (f(x + delta / 2) - f(x - delta / 2)) / delta;
		fprintf(salida,"%f	%f\n", x, sim);
		x = x + delta;
	}
	fclose(salida);
	return 0;
}

