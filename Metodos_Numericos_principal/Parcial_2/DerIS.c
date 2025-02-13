#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
	return sin(x);
	//return 2*x*x+3*x;
}

int main(){
	float x, xi, xf, A, DerI, DerIS;
	int n, i;
	char archivo[30];
	FILE *salida;
	printf("\nIntroduce el primer extremo del intervalo : \n");
	scanf("%f",&xi);
	printf("\nIntroduce el último extremo del intervalo : \n");
	scanf("%f",&xf);
	printf("\nIntroduce el número de veces a evaluar : \n");
	scanf("%d",&n);
	printf("\nIntroduce el nombre del archivo de salida : \n");
	scanf("%s", archivo);
	A = (xf - xi) / n;
	x = xi;
	salida = fopen(archivo, "w");
	for(i = 0; i < n; i++)
	{
		DerI = (f(x) - f(x-A)) / A;
		DerIS = (f(x+A/2) - 2*f(x-A/2) + f(x-(3*A)/2)) / A*A;
		fprintf(salida,"%f %f \n",x, DerIS);
		x += A;
	} 
	fclose(salida);
}
