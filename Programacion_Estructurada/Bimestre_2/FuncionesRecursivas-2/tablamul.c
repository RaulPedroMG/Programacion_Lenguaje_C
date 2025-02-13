/*unsis-li
 * nombre:tablamul.c
 * descripción:le pide al usuario que introdusca un 
 * 				número para calcular la tabla de
 * 				multiplicar de ese número.
 * */
#include <stdio.h>
void multipli(int numer, int lim);

int main()
{
	int numer, lim = 1;
	printf("Introdusca el número que quiere que calcule la tabla:");
	scanf("%d",&numer);
	multipli(numer, lim);
	printf("\n");
	return 0;
}

void multipli(int numer, int lim)
/*calcula de forma recursiva la tabla del número 
que introduce el usuario(numer) y el limite va hacer 10*/
{
	int mul;
	mul = numer * lim;
	if (lim == 10)
	{
		printf("\n");
		printf("%d * %d = %d",numer,lim,mul);
	}
	else
	{
		printf("\n");
		printf("%d * %d = %d",numer,lim,mul);
		multipli(numer, lim +1);//llamando a la funcion
	}
}
