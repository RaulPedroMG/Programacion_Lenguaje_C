#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
	//return (1/x);
	return (x*x*x)-(6*(x*x))+(8*x);
}

float df(float x)
{
	//return (-1/(x*x));
	return (3*(x*x))-(12*x)+8;
}

int main()
{
	float fun, dfun, xo, x;
	int i=0;
	printf("\nIntroduce el valor de x inicial : \n");
	scanf("%f",&xo);
	fun = f(xo);
	while((fun * fun) < 0.0001)
	{
		dfun = df(xo);
		x = xo - fun / dfun;
		fun = f(x);
		xo = x;
		i++;
	}
	printf("\n\n\tLa raiz aproximada es : %f \n\n\tNum de iteracciones : %d\n\n", xo, i);
	return 0;
}


