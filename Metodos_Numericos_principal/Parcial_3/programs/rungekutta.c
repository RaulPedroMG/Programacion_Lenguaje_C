#include <math.h>  
#include <stdio.h>  
#include <stdlib.h> 
#define M 40  
float fx(float x,float y){  
	float f,s;  
	//f=sqrt(pow(x,2)+pow(y,2));  
	s=(-(x*x))/2;
	f=exp(s);
	return f;  
}   
int main()  
{  
	float x[M],y[M],xf,h,k1,k2,k3,k4;  
	int N,i;    
	printf("Valor inicial de x \n");  
	scanf("%f",&x[0]);  
	printf("Valor final de x \n");  
	scanf("%f",&xf);  
	printf("Valor inicial de y \n");  
	scanf("%f",&y[0]);  
	printf("No. de divisiones a realizar:\n");  
	scanf("%d",&N);  
	h=(xf-x[0])/N;  
	printf("\n%f\n",h);  
	for(i=0;i<=N;i++){  
		x[i]=x[0]+h*i;  
		printf("\n%f",x[i]);  
	}  
	printf("\n Yi \n");  
	for(i=1;i<=N;i++){  
		k1=fx(x[i-1],y[i-1]);  
		k2=fx(x[i-1]+(h/2),y[i-1]+(k1/2));  
		k3=fx(x[i-1]+(h/2),y[i-1]+(k2/2));  
		k4=fx(x[i-1]+h,y[i-1]+k3);  
		y[i]=y[i-1]+(h/6)*(k1+2*k2+2*k3+k4);  
		printf("\n y[%d]=%f\n",i,y[i]);  
	}  
	printf("\n Y[%.1f]= %f\n",xf,y[N]);  
	return 0;  
}  
