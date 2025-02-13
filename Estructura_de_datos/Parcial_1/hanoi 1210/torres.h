#define D 5

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
void leerdiscos(int *numdiscos);
void leertorre(int *tor,int i,char *me);

void imprimirprese(void );
void draw_menubar(WINDOW *menubar);
