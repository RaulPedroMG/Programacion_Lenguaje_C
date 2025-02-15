#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
	//return ((x*x) - 4);
	//return  (x*x-x+1)*cos(x*x);
	return exp(x)*sin(x);
}

int main()
{
	float t, m, xi, xf, d, x, fxi, fxf;
	int n, i = 0;
	printf("\nIntroduce el punto  inicial : \n");
	scanf("%f",&xi);
	printf("\nIntroduce el punto  final : \n");
	scanf("%f",&xf);
	printf("\nIntroduce el valor de delta : \n");
	scanf("%f",&d);
	printf("\nIntroduce la tolerancia en el error : \n");
	scanf("%f",&t);
	fxi = f(xi);
	while( fxi * fxi > t)
	{
		printf("\niteracción: %d  |  raiz: %f  |  error: %f ", i+1, x, xf - x);
		//xi = xf;
		//xf = x;	
		fxi = f(xi);
		fxf = f(xf);
		m = (fxf - fxi) / (xf - xi);
		x = xf - (fxf / m);
		xf+=d;
		i++;
	}
	if(i != 0)
		printf("\n\n\tLa raiz aproximada es : %f\n\n", xf);
	else
		printf("\n\tNo es posible encontrar raiz con ese entervalo \n\n");
	return 0;
}

