#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, j;
	float **Mat;
	printf("\nIntroduce los números de puntos de la función : ");
	scanf("%d", &n);
	Mat = (float **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		Mat[i] = (float *)malloc(n+1 * sizeof(int));
	for(i = 0; i < n; i++)
		for(j = 0; j < n + 1; j++)
			Mat[i][j] = 0;
	for(i = 0; i < n; i++){
		printf("Introduce el valor de x%d, y%d : ", i+1, i+1 );
		scanf("%f %f", &Mat[i][0], &Mat[i][1]);
	}
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
	printf("\n");
	return 0;
}
