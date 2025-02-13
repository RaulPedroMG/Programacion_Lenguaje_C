#include <stdio.h>
#include <iostream.h>

int main()
{
    int num, i, j, div, numprim;
    printf("Introduce un número : ");
    scanf("%d", &num);
    for(j = 1; j <= num; j)
    {
          div = 0;
          for(i = 1; i <= j; i++)
          {
                  if(i % j == 0)
                  {
                       div++;
                  }
          } 
          if(div == 2)
          {
                 numprim = j;
          }
    }
    printf("El número primo es : %d ", numprim);  
    getch();
    return 0;
}
