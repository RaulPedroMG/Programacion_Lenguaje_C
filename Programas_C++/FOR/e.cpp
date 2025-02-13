/*	Escribe un programa que muestre los números
	comprendidos entre 1 y 1000. El programa mostrará
	en pantalla los número en grupo de 20, solicitando
	al usuario si quiere o no continuar visualizando el
	siguiente grupo de números*/
#include <iostream>
using namespace std;

int main(){
	char respuesta;
	int num;
	for (num = 1;respuesta != 'N' && respuesta != 'n' && num <= 1000; ++num){
		cout <<"\n\t" <<num;
		if ((num % 20) == 0 && num != 1000)
		{
			cout <<"\n¿Desea continuar? (oprima N/n para terminar) : ";
			cin >> respuesta;
		}
	}
	cout <<"\n\n";
	return 0;
}