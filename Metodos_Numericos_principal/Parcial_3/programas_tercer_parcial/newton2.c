#include <stdio.h>

int main(){

int N=100,i,j,k,np;
double X[N],Y[N],M[N][N];
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
	for(i=0;i<np;i++)
		scanf("%lf %lf",&X[i],&Y[i]);

	for(i=0;i<np-1;i++){
		for(j=0;j<np-1-i;j++){
			M[j][i]=(Y[j+1]-Y[j])/(X[i+j+1]-X[j]);
		}
		for(k=0;k<np-1-i;k++){
			Y[k]=M[k][i];
		}
	}	

		


return 0;
}


