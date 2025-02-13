#include <stdio.h>
#include <math.h>

float fun(float x)
{
	
	return x*sin(x)-x;
}

float main()
{
	float Xi, Xd, X, Fi, Fd, F;
	int i=0, band=0;
	FILE *Archivo;
	
	printf("\nIngrese el valor inicial:  ");
	scanf("%f",&X);
	F=fun(X);
	
	while(band==0){
		i++;
		printf("\nIteraciones: %d X: %f con f(X)= %f\n",i,X,F);
		if (F-X<.00001 && F-X>-.0001)
			band=1;
		else{
			
			X=F;
			F=fun(X);
			
		}
	}
	printf("\nValor aproximado de la raiz:\n");
	printf("\nIteraciones : %d X: %f con f(X)= %f\n",i,X,F);
	return 0;
}
