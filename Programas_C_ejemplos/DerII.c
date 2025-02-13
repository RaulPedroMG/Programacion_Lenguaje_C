#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
	return x*sin(2*x);
}

int main(){
	float x, xf, A, DerI, DerII;
	int n, i;
	printf("\nIntroduce el primer extremo del intervalo : \n");
	scanf("%f",&x);
	printf("\nIntroduce el último extremo del intervalo : \n");
	scanf("%f",&xf);
	printf("\nIntroduce el número de veces a evaluar : \n");
	scanf("%d",&n);
	
	A = (xf - x) / n;
	for(i = 0; i < n; i++)
	{
		DerI = (f(x) - f(x-A)) / A;
		DerII = (f(x) - 2*f(x-A) + f(x-2*A)) / A*A;
		x+ = A;
	} 
}
