#include <stdio.h>

int main(){

int N=100,i,j,k,np;
double X[N],Y[N],Q;
char nom[30];
FILE *archivo;

	printf("\nCuantos Puntos se desean insertar?");
	scanf("%d",&np);
	//LeerPuntos(X,Y,np);
	/*printf("Nombre del archivo de salida?");
	scanf("%s",nom);
	archivo=fopen(nom,"w+");*/
	//Lectura del los vectores X y Y
	printf("\nX[i]		Y[i]\n");
	for(i=0;i<np;i++){
		scanf("%lf %lf",&X[i],&Y[i]);
	}
	
	for(i=0;i<np;i++){
		Q=Y[i];
		for(j=0;j<np;j++){
			if(i!=j)
				Q=Q/(X[i]-X[j]);
		}
		if(Q!=0){
			if(i==0)
				printf("%lg",Q);
			else{
				if(Q>0)
					printf("+%lg",Q);
				else
					printf("%lg",Q);
			}
			for(k=0;k<np;k++){
				if(i!=k){
					if(X[k]<0)
						printf("*(x+%lg)",X[k]*-1);
					else
						if(X[k]>0)
							printf("*(x-%lg)",X[k]);
						else
							printf("*x");
				}
			
			}
		}

		/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
	}printf("\n\n");

	
		
	


return 0;
}


