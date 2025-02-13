/*
	nombre:fibonacci
	autor:flavio 206-b
*/

#include <stdio.h>

int Fibonacci(int n);

int main ()
{
	int n,fibo;
	printf("Escribe un número para calcular el Fibonacci:");
	scanf("%d",&n);
	printf("La serie es: %d ,",fibo=Fibonacci(n));
	return 0;
}

int Fibonacci(int n)
{
	if(n==1|| n==2)
		return n;
	else
	return Fibonacci(n-1)+Fibonacci(n-2);
}
