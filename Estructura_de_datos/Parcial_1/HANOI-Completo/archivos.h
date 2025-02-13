#define ML 5
#define P 5

typedef struct 
{
	int posicion;
	char *nombre;
	int tiempo;
}Rancking;

void InsertarDato(Rancking *lista, char *cad, int time, int disco);
void LeeImpreRancking(Rancking *lista,int ndisco, int opc);
void RecorrerDato(Rancking *lista, int ind);
void LeerRancking (Rancking *lista, char *disco);
void LlenandoEstruc(Rancking *lista, char *cad, int *total);
void ImprimirRancking (Rancking *lista, int ndisco, int opc, char *disco, char *nivel);
void GuardarRancking(Rancking *lista, char *disco);
void MandarImpress(Rancking *lista, int nd, int opm);
