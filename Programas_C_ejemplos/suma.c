#include <stdio.h>

int suma(int x, int y){
    return x + y;
}

int main ()
{
    int x, y;
    printf("\nIntroduce el primer n�mero : \n");
    scanf("%d",&x);
    printf("\nIntroduce el segundo n�mero : \n");
    scanf("%d",&y);
//    s = x + y;
    printf("\nLa sumas es : %d\n", suma (x , y));
    getch();
    return 0;
}
