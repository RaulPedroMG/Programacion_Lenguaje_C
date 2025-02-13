/*	Escribe una programa que realice la pregunta
	"¿Desea continuar S/N?" y que no deje de hacerla
	hasta que le ususario teclee 'N'*/
#include <iostream>
using namespace std;

int main(){
	char respuesta;
	cout <<"\n";
	do{
		cout <<"\n¿Desea continuar S/N? : ";
		cin >> respuesta;
	}while(respuesta != 'N' && respuesta != 'n');
	cout << "\n\n";
	return 0;
}