#include <stdio.h>
#include <stdlib.h>

float f(float x, float y){
	return -x*y;
}

/*float SumaF(float A, float B, float a, float b, float n){
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
}*/

int main(){
	float m, h, xi ,yi, x, y, xf;
	int i, n;
	printf("\nIntroduce el valor inicial de x : \n");
	scanf("%f",&xi);
	printf("\nIntroduce el valor final de x : \n");
	scanf("%f",&xf); 
	printf("\nIntroduce el valor inicial de y : \n");
	scanf("%f",&yi); 
	printf("\nIntroduce el número de intervalos: \n");
	scanf("%d",&n); 
	h =(xf - xi) / n;
	x = xi;
	y = yi;
	for(i = 0; i <= n; i++)
	{
		m = f(x, y);
		y = y + m * h;
		x += h;
	} 
	printf("\nEl valor de la ecuacion diferencial es :%f \n", y);
	return 0;
}
