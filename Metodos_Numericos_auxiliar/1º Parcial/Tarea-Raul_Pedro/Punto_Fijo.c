#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float g(float x)
{
	//return ((x*x) - 4);
	
	// f(x) = x * x - 4
	//g(x) = x - f(x)
	return (x * x - 4);
}

int main()
{
	float t, xo, x, e;
	int n, i = 0, band = 0;
	printf("\nIntroduce el punto inicial : \n");
	scanf("%f",&xo);
	printf("\nIntroduce la tolerancia en el error : \n");
	scanf("%f",&t);
	printf("\nIntroduce el número de iteracciones : \n");
	scanf("%d",&n);
	while(band == 0 && i < n)
	{
		//printf("\niteracción: %d  |  raiz: %f  |  error: %f ", i+1, x, xf - x);
		x = g(xo) + xo;
		e = x - xo;
		xo = x;
		if(e < t)
		{
			band = 1;
		}
		i++;
	}
	printf("\n\n\tLa raiz aproximada es : %f\n\n\tNum de iteracciones : %d \n\n", x, i);
	return 0;
}

