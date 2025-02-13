#include <stdio.h>
#include <math.h>

float fun(float x)
{
	return (1/(x*x*x*x)) - (1/(x*x));
}


float main()
{
	float Xi, Xd, M, Fi, Fd, F, X;
	int i=0, band=0;
	printf("\n INGRESE LOS DOS EXTREMOS:  ");
	scanf("%f %f",&Xi, &Xd);
	Fi=fun(Xi);
	Fd=fun(Xd);
	if(Fi*Fd<0.001)
	{
		while(band==0){
			i++;
			M=(Fd-Fi)/(Xd-Xi);
			X=Xi-Fi/M;
			F=fun(X);
			
			if(Fi*F<0)
			{
				Xd=X;
				Fd=F;
			}
			else
			{
				
				Xi=X;
				Fi=F;
			}
			printf("\nIteraciones: %d X: %f con f(X)= %f\n",i,X,F);
			if (F<=0.0001 && F>=-0.0001)
				band=1;
		}
		printf("\nValor aproximado de la raiz\n");
		printf("\nNumero de iteraciones: %d X: %f con f(X)= %f\n",i,X,F);
	}
	
	return 0;
}
