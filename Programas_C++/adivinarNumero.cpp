// Programa para adivinar un número usando do-while
#include <iostream>
using namespace std;

int main(){
	int numeroAdivinar = 20;
	int numLeer;
	cout <<"\nAdivine un número\n";
	do{
		cout <<"\nIntroduzca un número : ";
		cin >> numLeer;
		if (numLeer < numeroAdivinar )
		{
			cout <<"El número es " << numLeer <<" es pequeño! \n";
		}else{
			if (numLeer != numeroAdivinar){
				cout <<"El número es " << numLeer <<" es grande! \n";
			}
		}
	}while(numLeer != numeroAdivinar);
	cout <<"\nFelicidades! Adivinaste el número " << numeroAdivinar << "\n\n";
	return 0;
}