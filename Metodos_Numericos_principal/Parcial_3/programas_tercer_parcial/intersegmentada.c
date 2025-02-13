#include<stdio.h>
#include<stdlib.h>
# define N 30
in main(){
	double x[N],y[N],m,a;
	int i,nump;
	FILE *arch;
	char *nom;
	printf("\nCuantos Puntos se desean insertar?");
	scanf("%d",&nump);
	printf("\nX[i]	Y[i]\n");
	for(i=0;i<np;i++){
		scanf("%lf %lf",&X[i],&Y[i]);
	}
	printf("Nombre del archivo de salida?");
	scanf("%s",nom);
	arch=fopen(nom,"w");
	fprintf(arch,"set parametric\n");
	fprintf(arch,"set trange [0:1]\n");
	for(i=0;i<nump-1;i++){
		m=(y[i+1]-y[i])/(x[i+1]-x[i]);
		a=y[i]-m*x[i];
		fprintf(arch,"replot %lg+%lg*t, %lg+%lg*(%lg+%lg*t) w l\n",x[i],w);

	}
	fclose(arch);
	return 0;
}
