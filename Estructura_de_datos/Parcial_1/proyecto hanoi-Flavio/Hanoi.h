#include <locale.h>
#include "Pila.h"
#include <time.h>
#define MIN 50
typedef struct
{
	char *arreg;
	int t;
	int lugar;
}Rankin;

void IniciarColor();
void Error(char *cad, int r);
int Menu();
void JugarHanoi(int numdisco, Rankin *reg);
void PintarDisco(Pila P1,Pila P2,Pila P3);
void CargarArchivo(FILE *archivo);
void PintarTorre();
void AsignarColor(int tamaniodisco,int num,int discos);
int DiscosCont(Pila p);
void Movimientos(Pila *origen,Pila *destino);
void Colocar(Pila *origen,Pila *destino);
void Ranking(int numdisco,int movim);
void Tiemp(int tiempo,int ndisc,Rankin *reg);
int Menu2();
void GuardarRanking(Rankin *nomj,int ndisc);
//void GuardaRak(Rankin *aux);
void LeerArchivoRanking(Rankin *nomj,int ndisc);
void SeparaCadRanking(Rankin *nomj,int *cont,char *cad);
void ImprimeRanking(Rankin *nomj,int cont);
void InsertarDato(Rankin *nomj,int tiempo,char *cad, int disco);
void RecorrerDato(Rankin *nomj, int i);
