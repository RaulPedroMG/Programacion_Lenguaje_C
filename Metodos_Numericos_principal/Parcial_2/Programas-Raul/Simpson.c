#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
	return x/sqrt(1+x*x*x*x);
}

int main (){
	float x, A, B, H, suma, sumat;
	int N, i;
	//char archivo[30];
	//FILE *salida;
	printf("\nIntroduce el limite inferior de la integral : \n");
	scanf("%f",&A);
	printf("\nIntroduce el limite superior de la integral : \n");
	scanf("%f",&B);
	printf("\nIntroduce número de interacciones : \n");
	scanf("%d",&N);
	//printf("\nIntroduce el nombre del archivo : \n");
	//scanf("%s", archivo);
	H = (B  - A) / N;
	sumat = 0;
	x = A;
	//salida = fopen(archivo, "w");
	for(i = 0; i <= N; i++)
	{
		if(i == 0)
			suma = f(x);
		if(i % 2 != 0)
			suma = 4*f(x);
		if(i % 2 == 0)
			suma = 2*f(x);
		if(i == N)
			suma = f(x);
		x += H;
		sumat += suma;
		printf("La suma %d : %f \n",i, suma);
	}
	//fclose(salida);
	printf("\nLa suma es : %f \n", sumat);
	printf("La integral es : %f \n\n", sumat*H/3);
	return 0;
}

