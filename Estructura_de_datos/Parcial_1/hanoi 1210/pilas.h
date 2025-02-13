
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

void Error(char *cad, int r);
void LeeEntero(char *cad,int max,int r, int c);
int LeeInt(int r, int c);

/*Declaración de funciones y procedimientos*/
void Hanoi(char a,char b, char c,int n);
void build_torres(void);/*En esta función se crea una matriz de Nfilas x 3columnas la cual simula el juego de las torres de hanoi.*/
void mover_disco(int x_origen, int x_destino, int* topeOrigen, int* topeDestino);
/*Este bloque de módulos genara una torre indice de donde se puede seleccionar un nivel y imprimirlo.*/
void definir_planos(void);
void draw_planos(void);
void draw_torres(void);

void jugarha(int numdiscos,char nom[15]);
/*Esta funciones imprimen las torres*/
void show_hanoi(int origen, int destino);
void pintar_torre(void);
void imprimir_nivel(int nivel, int fila, int columna);
void iniciar_esquinas(void);
void paleta_colores(void);
void mensaje(int estado);
void leerdiscos(int *numdiscos);
void LeeNombre(char *cad,int max,int r, int c);
void leertorre(int *tor,int i,char *me);
