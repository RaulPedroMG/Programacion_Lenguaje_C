#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
	int n, i, j;
	float Mat[MAX][MAX];
	char archivo[30], archivo2[30];
	FILE *salida, *salida2;
	printf("\nIntroduce los números de puntos de la función : ");
	scanf("%d", &n);
	/*Mat = (float **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		Mat[i] = (float *)malloc(n+1 * sizeof(int));
	for(i = 0; i < n; i++)
		for(j = 0; j < n + 1; j++)
			Mat[i][j] = 0;*/
	for(i = 0; i < n; i++){
		printf("Introduce el valor de x%d, y%d : ", i+1, i+1 );
		scanf("%f %f", &Mat[i][0], &Mat[i][1]);
	}
	printf("Introduce el nombre del primer archivo de salida : ");
	scanf("%s", archivo);
	printf("Introduce el nombre del segundo archivo de salida : ");
	scanf("%s", archivo2);
	for(i = 2; i < n + 1; i++){
		for(j = 0; j < n; j++){
			if(j < n-i+1) {
				Mat[j][i] = (Mat[j+1][i-1] - Mat[j][i-1]) / (Mat[j+i-1][0] - Mat[j][0]);
			}
		}
	}
	printf("\n\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n +1; j++){
			printf("\t%f",Mat[i][j]);
		}
		printf("\n");
	}
	salida = fopen(archivo, "w");
	for(i = 0; i < n; i++){
		fprintf(salida,"%f %f\n", Mat[i][0], Mat[i][1]);
	}
	fclose(salida);
	salida2 = fopen(archivo2, "w");
	//printf("El polinomio es : \n\n");
	for(i = 1; i < n + 1; i++){
		if(Mat[0][i] != 0){
			if(i == 1){
				//printf("%f ", Mat[0][i]);
				fprintf(salida2,"replot %f", Mat[0][i]);
			}
			else{
				if(Mat[0][i] > 0)
					//printf("+ %f ", Mat[0][i]);
					fprintf(salida2,"+%f", Mat[0][i]);
				if(Mat[0][i] < 0)
					//printf("- %f ", (Mat[0][i]) * - 1);
					fprintf(salida2,"-%f", (Mat[0][i]) * - 1);
				for(j = 0; j < i - 1; j++){
					if(Mat[j][0] == 0){
						//printf(" * x ");
						fprintf(salida2,"*x");
					}
					else{
						//printf(" * (x ");
						fprintf(salida2,"*(x");
						if(Mat[j][0] > 0){
							//printf(" - %f", Mat[j][0]);
							if(i )
							fprintf(salida2,"-%f)", Mat[j][0]);
						}
						if(Mat[j][0] < 0){
							//printf(" + %f) ", (Mat[j][0]) * - 1 );
							fprintf(salida2,"+%f)", (Mat[j][0]) * - 1 );
						}
					}
				}
			}
		}
	}//printf(")");
	printf("\n\n");
	fclose(salida2);
	return 0;
}
