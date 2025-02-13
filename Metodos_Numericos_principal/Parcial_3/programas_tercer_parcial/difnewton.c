#include <stdio.h>

#define MAX 100

int main(){
double X[MAX],Y[MAX],F[MAX],dif[MAX][MAX];
int i,j,k,l,np;

	printf("\n\tAproximacion polinomial de Newton");
	printf("\n\nCuantos Puntos se desean calcular?");
	scanf("%i",&np);

	//	Lectura de los Puntos
	printf("\n");
	for(i=0;i<np;i++){
		printf("punto%i ",i);
		scanf("%lf %lf",&X[i],&Y[i]);	
		F[i]=Y[i];
		printf("\n");
	}

	//	Tabla de diferencias divididas
	for(i=0;i<np-1;i++){
		for(j=0;j<np-1-i;j++){
			dif[j][i]=(F[j+1]-F[j])/(X[i+j+1]-X[j]);
			F[j]=dif[j][i];
		}
	}

	//	Mostrar Tabla
	printf("\n\n");	
	for(i=0;i<np-1;i++){
		for(j=0;j<np-1-i;j++){
			printf("%lg\t",dif[i][j]);
		}	printf("\n");
	}

	//	Desarrollo del polinomio de newton
	printf("\nP(x)=%lg",Y[0]);
	for(i=0;i<np-1;i++){
		if(dif[0][i]!=0){
			if(dif[0][i]>0)
				printf("+%lg",dif[0][i]);
			else
				printf("%lg",dif[0][i]);
			for(j=0;j<=i;j++){
				if(X[j]<0)
					printf("*(x+%lg)",X[j]*-1);
				else
					if(X[j]>0)
						printf("*(x-%lg)",X[j]);
					else
						printf("*x");
			}
		}
	}printf("\n\n");

return 0;
}
