#define ML 5

typedef struct 
{
	char nombre[20];
	int nudis;
	int tiempo;
}Ranking;

void ImprimirDatos(Ranking lista[ML], int *contj,char *nivel);
void GuardarEmp(Ranking *Lista,int contj,char *nom);
void LeerEmp(Ranking *Lista,int *contj,char *nom);
void ImprimirRes(int i,Ranking lista[ML]);
void ingresardatos(Ranking Lista[ML],int nd, char nom[15], int DIF,int *indice);
int busm(Ranking Lista1[ML], int DIF,int indice);
void MoverR(int ind, Ranking Lista1[ML], int *indice);
void rankind(void);
