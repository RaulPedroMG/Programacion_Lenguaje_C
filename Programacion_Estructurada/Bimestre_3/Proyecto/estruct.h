/*
Nombre: estruct.h
Descripción: Contiene la definición de constantes y declaciones de estructuras.
		Además se incluyen los prototipos de las funciones 
		* de un arreglo	de estructuras.
Autor: Equipo 1
*/
#define MIN 10
#define CAL 5
#define ML 200
#define MAT 11


typedef struct 
{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct 
{
	char clave[MIN];
	char *nombremp;
	char *giro;
	char *domicilio;
	char *estado;
	int cp;
	char *telefono;
	char *fax;
	char *nomcont;
	char *correo;
	char *visita;
	char *estancia;
	char *servicios;
}Empresa;

typedef struct 
{
	char mat[MAT];
	char *nomalum;
	char *apealum;
}Alumno;

typedef struct 
{
	char clav[CAL];
	char *nomprofe;
	char *apeprofe;
}Profesor; 

typedef struct 
{
	char clavemp[MIN];
	char claveprof[CAL];
	Fecha totalvisita;
	char *cal;
}Visita; 

int Menu ();

void LeerArchivoEmp(Empresa *catemp,int *cont);

void SeparaCad(Empresa *catemp,int *cont,char *cad);

void LeerArchivoAlumn(Alumno *catalumn,int *cont);

void SeparaCadAlumn(Alumno *catalumn,int *cont,char *cad);

void GuardarAlumText(Alumno *catalumn,int cont);

void LeerArchivoProfe(Profesor *catprofe, int *cont);

void SeparaCadProfe(Profesor *catprofe, int *cont, char *cad);

void GuardarProfeText(Profesor *catprofe,int cont);

int MenuP ();

int Menu1 (char *cad);

int Menu2 ();

void Empresas (Empresa *catemp,int *cont, int usuario);

void RegistrarEmp(Empresa *catemp,int *t);

void EliminarEmp(Empresa *catemp,int *t);

int BuscarEmp(Empresa *catemp,int t, char clave[MIN]);

void BorrarEmp(Empresa *catemp,int *total, int i);

void ModificarEmp(Empresa *catemp,int t);

int ImprimirEmpMod (Empresa *catemp, int i);

void CosultarEmp(Empresa *catemp,int t);

void ListaEmp(Empresa *catemp,int cont, int *rr, char clave[MIN]);

void ImprimirEmp2 (Empresa *catemp, int t);

void ImprimirEmp(Empresa *catemp, int i);

void Alumnos (Alumno *catalumn,int *cont, int usuario);

void RegistrarAlumn(Alumno *catalumn,int *t);

void InsertarOrd(Alumno *catalumn,int *t, Alumno *aux);

void Sustituir(Alumno *destino, Alumno *origen);

void EliminarAlumn(Alumno *catalumn,int *t);

int BuscarAlumn(Alumno *catalumn, int t, char matri[MAT]);

void BorrarAlumn(Alumno *catalumn,int *total, int ind);

void ModificarAlumn(Alumno *catalumn,int t);

int ImprimirAlumnMod (Alumno *catalumn, int i);

void CosultarAlumn(Alumno *catalumn,int t);

void ImprimirAlumn2 (Alumno *catalumn, int t);

void ImprimirAlumn (Alumno *catalumn, int i);

void Profesores(Profesor *catprofe, int *cont, int usuario);

void RegistrarProfe(Profesor *catprofe, int *t);

void EliminarProfe(Profesor *catprofe, int *t);

int BuscarProfe( Profesor *catprofe, int t, char clav[CAL]);

void BorrarProfe(Profesor *catprofe, int *total, int ind);

void ModificarProfe(Profesor *catprofe, int t);

void ConsultarProfe(Profesor *catprofe, int t);

int ImprimirProfeMod (Profesor *catprofe, int i);

void ImprimirProfe (Profesor *catprofe, int i);

void ImprimirProfe2 (Profesor *catprofe, int t);

void Visitas (Empresa *catemp,int te, Profesor *catprofe, int tp, Visita *visitas, int *tv, int usuario);

void CosultarVisita ();

void Estancias ();

void Servicios ();

