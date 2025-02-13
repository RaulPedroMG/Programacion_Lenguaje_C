/*	Escribe una programa que genere la tabla de multiplicar
	de un número introducido por el teclado*/
#include <iostream>
using namespace std;

int main(){
	int numLeer, i=1;
	cout <<"\nIntroduzca de número de la tabla de multiplicar : ";
	cin >> numLeer;
	do{
		cout <<"\t" << numLeer <<" x " << i <<" = " << numLeer*i <<"\n";
		i++;
	}while(i <= 10);
	cout << "\n\n";
	return 0;
}