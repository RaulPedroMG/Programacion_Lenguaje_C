#include <stdio.h>
#include <stdlib.h>

float sumat (float x);

int main()
{
	float suma=0;
	int x;
	for(x = 1; x <= 1000; x++ )
	{
		suma = suma + sumat(x);
		printf("La suma %d es : %f \n", x, suma);
	}
	printf("\n");
	return 0;
}

float sumat (float x)
{
	return (x + (1/x) );
}
