#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
	return 2 * x + 1;
}

int main(){
	float A, B, Del, Suma, x;
	int N, i;
	
	printf("\nIntroduce el limite inferior de la integral : \n");
	scanf("%f",&A);
	printf("\nIntroduce el limite superior de la integral : \n");
	scanf("%f",&B);
	printf("\nIntroduce número de interacciones : \n");
	scanf("%d",&N);
	Del = (B - A) / N;
	//Suma = (f(A) + f(B)) / 2;
	Suma = 0;
	x = A;
	for(i = 0; i < N; i++){
		Suma += (Del/2)*(f(x)+f(x+Del));
		x += Del;
	}
	printf("\nEl valor de la integral es %f\n\n", Suma);
}
