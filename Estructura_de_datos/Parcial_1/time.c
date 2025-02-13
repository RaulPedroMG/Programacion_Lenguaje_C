#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;
 
int main(int argc, char *argv[])
{
 clock_t inicioprograma;
    int bucle= 3D1;
    int milisegundos, segundos;
    inicioprograma = 3Dclock();
	while(1)
	{
		cout << "Cuando desee saber cuanto tiempo ha = pasado, presione una tecla" << endl;
		system("pause>nul");
		milisegundos=3Dclock()-inicioprograma;
		segundos = 3D = 3Dmilisegundos / 10;
		cout <<  "Han pasado " << segundos << " segundos" << endl;
		system("PAUSE");
		system("cls");
	}
    return 0;
}
