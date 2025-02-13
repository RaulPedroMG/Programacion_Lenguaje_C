
typedef struct{
int arreglo[MAX];
int tope;
}Pila;

void PilaVacia (Pila *a);
int EsVacia (Pila *a);
int Cima (Pila a);
void Push (int x, Pila *a);
int Pop (Pila *a); 
void imtorres(int numdis);
void llenarpila(Pila *p1);

void Centrar(char *cad, int r);

void Derecha(char *cad, int r);


