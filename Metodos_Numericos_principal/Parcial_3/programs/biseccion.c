#include <stdio.h>
#include <math.h>

float fun(float x){
//	float j=x*x;
	//j=(-0.25*(x*x*x))+2.1375*(x*x)-1.11875*x+0.15;
	//return 2*x-16;
	//return x*x*x-6*x*x+8*x;
	return exp(x)*sin(x);
}

int main()
{
	float XI,XD;
	float x;
	float fi, fd,f;
	int n=50,i;
	printf("Igresa los valores iniciales de x1 y x2\n");
	scanf("%f %f",&XI,&XD);
	fi=fun(XI);
	fd=fun(XD);
	//if(fi*fd < 0){
		for(i=0;i<n;i++){
			x=(XI+XD)/2;
			//printf("X: %f\n",x);
			f=fun(x);
			fi=fun(XI);
			
			if(f*fi<0.0001){
				XI=x;
			}else{
				XD=x;
			}
			if((f*fi)==0){
				return 0;
			}
		}
	//}
	printf("el resultado es %f ",x);
	return 0;
}
