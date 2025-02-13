#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float fun(float x)
{
	return x-sin(x);
}

int main()
	{
	int i, N;
	float X0, X1, x, delta, fi, fo, f, Eps;
	printf("\nPROGRAMA MÉTODO POR BARRIDAS\n");

	printf("Da los extremos de la region: \n");
	scanf("%f %f", &X0, &X1);
	printf("En cuantas secciones: ");
	scanf("%d", &N);
	printf("Tolerancia: ");
	scanf("%f", &Eps);
	delta=(X1-X0)/N;
	fi=fun(X1);
	fo=fun(X0);
	x=X0;
	if(fo*fi<0)
	{
		for(i=0; i<N; i++)
		{
			x=x+delta;
			f=fun(x);
			if(f*f<Eps*Eps)
			{
				printf("Solución %f  %f\n", x, f);
			}
		}
	}
	else
		printf("NO existe solución, o existe dos posibles soluciones\n");
	return 0;
}

