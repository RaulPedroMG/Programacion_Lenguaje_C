#include <stdio.h>
#include <stdlib.h>

float f(float x, float a, float b){
	return a*x+b;
}

float SumaF(float A, float B, float a, float b, float n){
	float form, err;
	form = (a/2)*(B*B - A*A) + b*(B-A);
	err = (a/2)*((B - A)*(B - A) / n);  
	return form - err;
}

float Integral(float A, float B, float a, float b){
	return (a/2)*(B*B - A*A) + b*(B-A);
}

float Err(float A, float B, float a, float b, float n){
	return (a/2)*(B - A)*(B - A) / n;  
}

int main(){
	float a, b, A, x, B, d, suma, sumaf, integ, err;
	int n, i;
	printf("\nIntroduce el coeficiente de x : \n");
	scanf("%f",&a);
	printf("\nIntroduce el último coeficiente de la recta : \n");
	scanf("%f",&b);
	printf("\nIntroduce el límite inferior de la integral : \n");
	scanf("%f",&A);
	printf("\nIntroduce el límite superior de la integral : \n");
	scanf("%f",&B);
	printf("\nIntroduce el número de intervalos a evaluar : \n");
	scanf("%d",&n);
	d = (B - A) / n;
	x = A;
	//printf("\n%f",d);
	suma = 0;
	for(i = 0; i < n; i++)
	{
		suma+= d * f(x+d, a, b);
		x+=d;
	} 
	sumaf = SumaF(A, B, a, b, n);
	integ = Integral(A, B, a, b);
	err = Err(A, B, a, b, n);
	printf("\n\n\tIntegral : %f \n\tSuma : %f \n\tFórmula : %f \n\tError : %f\n\n", integ, suma, sumaf, err);
	
	return 0;
}
