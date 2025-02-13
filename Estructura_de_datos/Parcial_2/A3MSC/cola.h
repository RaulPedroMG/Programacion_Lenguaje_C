#define MAX 50

typedef struct {   
	int listaCola[MAX]; 
	int frente; 
	int final; 
}Cola;


void crearcola(Cola *cola);
int colallena (Cola cola);
void insertar(Cola *cola,int entrada);
int quitar(Cola *cola);
int colavacia (Cola *col);
int frente(Cola cola);
