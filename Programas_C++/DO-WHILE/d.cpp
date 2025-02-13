/*	Escribe un programa que detecte si un número
	tecleado es primo o no. Un número es primo si solo
	es divisible por sí mismo y por la unidad*/
#include <iostream>
using namespace std;

int main(){
	int num, numaux, divisible = 0;
	cout <<"\nIntroduce un número : ";
	cin >> num;
	numaux = num;
	do{
		if ((num % numaux) == 0)
		{
			divisible++;
		}
		numaux--;
	}while(numaux >= 1);
	if(divisible == 2){
		cout <<"\nEl número " <<num <<" es primo" << "\n\n";
	}else{
		cout <<"\nEl número " <<num <<" no es primo" << "\n\n";
	}
	return 0;
}