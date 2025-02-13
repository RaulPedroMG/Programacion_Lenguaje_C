#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
	/*return sin(x);*/
	return exp(x)*sin(x);
	
}

int main()
{
	float xi, xf, fxi, fxr, xr;
	int n, i = 0, band = 0;
	printf("\nIntroduce el primer punto del  extremos del intervalo : \n");
	scanf("%f",&xi);
	printf("\nIntroduce el punto final : \n");
	scanf("%f",&xf);
	printf("\nIntroduce el número de iteracciones : \n");
	scanf("%d",&n);
	fxi = f(xi);
//	if((fxi * f(xf)) < 0.0001)
//	{
		while( band == 0 &&  i < n)
		{
			xr = (xi + xf) / 2;
			fxr = f(xr);
			fxi = f(xi);
			printf("\niteracción: %d  |  raiz: %f  |  error: %f \n\n", i+1, xr, fxr);
			if((fxi * fxr) < 0)
			{
				xf = xr;
			}
			else
			{
				xi = xr;
			}
			if(fxr == 0.)
				band = 1;
			i++;
		}
		printf("\n\n\tLa raiz aproximada es : %f \n\n\tNum de iteracciones : %d\n\n", xr, i);
//	}
/*	else
	{
		printf("\n\tNo es posible encontrar raiz con ese entervalo \n\n");
	}*/
	return 0;
}

