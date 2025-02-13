#define V 20
#define P 5
#define RET 127
#define ENT 10
typedef struct 
{
	int clave_v;
	char *destino;
	char *cap_vuelo;
	char *aerolinea;
	int asignado;
}Vuelos;
//Fernando
//Archivos
void LeerVuelos(Vuelos *lista);
void LlenandoEstruc(Vuelos *lista, char *cad, int *total);
//Cola
void ingresardatos(void);
void LlenaCola(Cola *pis1, Cola *pis2, Cola *pis3);
void InsertarAlea(Cola *Pista, int j, int *i);
void AgregarVuelo(Cola *aux1, Cola *aux2, Cola *aux3, Vuelos *turno);
//Gloria
void Obtenermenor(Cola *pis1, Cola *pis2, Cola *pis3, int *menor);//Obtiene el elemento menor de la pis1, pis2 y pis3
void Quitarmenor(Cola *aux1, Cola *aux2, Cola *aux3, Cola *pis1, Cola *pis2, Cola *pis3, int menor, int *ind, Vuelos *turno,int *np);
int BuscarVuelo(Vuelos *turno, int clave);
void ImprimirVuelo(Vuelos *lista, int ind,int np,int nua);
void diavion(int i);
void Pantalla(Vuelos *lista, int ind,int np,int nua);
//Raul
void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno);
void init_curses();
void tiempoavion(int i);
void impresio_marcos(void);
int MenuAd();

int Rango(int men , int may,int r,int c);
void LeeEntero(char *cad,int max,int r, int c);
