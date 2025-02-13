#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float df(float x,float y){
return (y*sin(x));
}

int main(){
    float xa, xb, ya, yb, A, Ax, Ay, eps;
    int Nx,Ny,i,j;
    float Deri,Tanc;
    float x,y;
    FILE *arch;
    char nombre[30];

    printf("\nIntroduzca el limite inferior de X:\n");
    scanf("%f",&xa);
    printf("\nIntroduzca el limite inferior de X:\n");
    scanf("%f",&xb);
    printf("\nIntroduzca el limite inferior de Y:\n");
    scanf("%f",&ya);
    printf("\nIntroduzca el limite superior de Y:\n");
    scanf("%f",&yb);
    printf("\nIntroduzca el número de segmentos de X:\n");
    scanf("%d",&Nx);
    printf("\nIntroduzca el número de segmentos de Y:\n");
    scanf("%d",&Ny);
    printf("\nNombre del archivo:");
    scanf("%s",nombre);

    A = (xb - xa) / Nx;
    eps = (yb - ya) / Ny;
    Tanc = eps / A;
    x = xa;
    arch = fopen(nombre,"w");
    for(i = 0; i <= Nx; i++){
       y = ya;
       for(j = 0; j< Ny ; j++){
          Deri = df(x, y);
          if((Deri * Deri) < (Tanc * Tanc)){
             Ax = A;
             Ay = Deri * A;
          }else{
             Ay = eps;
             Ax = eps / Deri;
          }
          fprintf(arch,"set arrow from %f,%f to %f,%f\n", x, y, x + Ax, y + Ay);
          y += eps;
       }
       x += A;
    }
    fclose(arch);
}
