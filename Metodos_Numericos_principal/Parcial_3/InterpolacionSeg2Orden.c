/*El programa solo obtiene los valores de los coeficientes 
de las ecuaciones lo demas sera resulto enviando a maxima los valores encontrados
y se escriben las ecuaciones en un archivo de texto y se envia a gnuplot para hacer las graficas
*/

#include <stdio.h>
#include <math.h>
#define N 100
float X[N]={0};
float Y[N]={0};
float A[N][N+1];

void leerP(int np);
void parabolas(int np);
void deriv(int np);
void imprimirP(int np);

int main()
{
	int np;
	printf("Ingrese el numero de puntos a evaluar \n");
	scanf("%d",&np);
	leerP(np);
	parabolas(np);
	deriv(np);
	imprimirP(np);
	return 0;
}

void leerP(int np)
{
	int i=0;
	for(i=0;i<np;i++){
		printf("\nIngrese el punto X%d: ",i+1);
		scanf("%f",&X[i]);
		printf("\nIngrese el punto Y%d: ",i+1);
		scanf("%f",&Y[i]);
	}
}

void parabolas(int np)
{
	//la ultima ecuacion de la matriz es la primera derivada de la parabola en el punto x0 igualada a 0
	int i=0,fila=0,columna=0;
	int Nparabolas;
	Nparabolas=np-1;
	float a,b,c;
	for(i=0;i<Nparabolas;i++){
		a=1;
		b=X[i];
		c=X[i]*X[i];
		fila=2*i;
		columna=3*i;
		A[fila][columna]=a;
		A[fila][columna+1]=b;
		A[fila][columna+2]=c;
		A[fila][3*Nparabolas]=Y[i];
		a=1;
		b=X[i+1];
		c=X[i+1]*X[i+1];
		fila=2*i+1;
		columna=3*i;
		A[fila][columna]=a;
		A[fila][columna+1]=b;
		A[fila][columna+2]=c;
		A[fila][3*Nparabolas]=Y[i+1];
	}	
}

void deriv(int np)
{
	int i,fila;
	int Nparabolas;
	Nparabolas=np-1;
	fila=2*Nparabolas;
	for(i=0;i<Nparabolas-1;i++){
		A[fila+i][3*i+1]=1;
		A[fila+i][3*i+2]=2*X[i+1];
		A[fila+i][3*i+4]=-1;
		A[fila+i][3*i+5]=2*X[i+1];
	}
	A[fila+i][1]=1;
	A[fila+i][2]=2*X[0];
}
void imprimirP(int np)
{
	int i,j;
	int Nparabolas=np-1;
	for(i=0;i<3*Nparabolas;i++){
		for(j=0;j<=3*Nparabolas;j++){
			printf(" %lg ",A[i][j]);
		}
		printf("\n");
	}
}
