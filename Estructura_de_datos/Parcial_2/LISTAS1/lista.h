
/*	Funciones y procedimientos creados por el equipo 1:::
 * NOTA:
 * 		struct nodo siempre debe de estar escrito de este modo,
 * no se puede usar typedef para minimizar la variable nodo 
 * (EXPLICADO POR EL PROFE VICTOS QUE NO SE PUEDE (si quieren
 * pueden buscar información para hacerlo (opcional)))*/

struct nodo{
	int info;
	struct nodo *sig;
};

struct nodo *crea_nodo();
void crearLista(struct nodo **lista);
int EsVacia(struct nodo *lista);
void InserPrim(int x, struct nodo **lista);
void InsertaFin(int x,struct nodo **lista);
void Eliminar(struct nodo **lista);
void InsertaMedio(int x, struct nodo **lista, struct nodo *n);
struct nodo *localiza(struct nodo *lista,int val);
void Anula(struct nodo **lista);

