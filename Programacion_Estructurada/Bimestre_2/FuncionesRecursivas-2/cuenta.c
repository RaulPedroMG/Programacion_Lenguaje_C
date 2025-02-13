/*
 * unsis-li
 * nombre:cuenta.c
 * descripcion:Cuenta valores de 1 a 10 de modo recursivo.
 * */
#include <stdio.h>
void contar(int cima);
int main()
{
	contar(10);
	return 0;
}
void contar(int cima)
/*cuenta de forma recursiva del 1 al 10*/
{
	if (cima > 1)
		contar(cima-1);//llamando a la función
	printf ("%d ",cima);
	printf("\n");
}
