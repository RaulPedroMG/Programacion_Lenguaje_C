#define OK 0
#define COLA_VACIA -1
#define SIN_ESPACIO -2
#define MAX 25

typedef struct
{
	int cola[MAX];
	int posterior;
	int anterior;
}COLA; 

void iniciar_cola(COLA *Q);
int encolar(int elemento, COLA *Q);
int desencolar(COLA * Q);
int cola_vacia(COLA *Q);
int tamano_cola(COLA *Q);
