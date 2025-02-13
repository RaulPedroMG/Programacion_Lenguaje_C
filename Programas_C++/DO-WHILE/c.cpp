/*	Escribe un programa que calcule el Factorial
	de un número entero positivo*/
#include <iostream>
using namespace std;

int main(){
	int num, factorial;
	cout <<"\nIntroduce un número para calcular el factorial : ";
	cin >> num;
	factorial = num;
	if(num >= 0){
		if(num == 1 || num == 0){
			cout <<"\nEl factorial es : 1" << "\n\n";
		}else{
			do{
				factorial = factorial * (num - 1);
				num--;
			}while((num - 1) >= 1);
			cout <<"\nEl factorial es : " <<factorial << "\n\n";
		}
	}else{
		cout <<"\nNo se puede calcular el factorial de un número negativo\n\n";
	}
	return 0;
}
