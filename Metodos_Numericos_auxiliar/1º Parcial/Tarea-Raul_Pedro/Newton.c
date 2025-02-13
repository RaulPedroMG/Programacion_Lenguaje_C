#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
	//return (1/x);
	return (2*x) - 2;
}

float df(float x)
{
	//return (-1/(x*x));
	return (2);
}

int main()
{
	float fun, dfun, xo, x;
	printf("\nIntroduce el valor de x inicial : \n");
	scanf("%f",&xo);
	fun = f(xo);
	while((fun * fun) >= 0.00001)
	{
		dfun = df(xo);
		x = xo - fun / dfun;
		fun = f(x);
		xo = x;
	}
	printf("\n\n\tLa raiz aproximada es : %f \n\n",xo);
	return 0;
}


