/*
Nombre: estruct.h
Descripción: Contiene la definición de constantes y el nuevo tipo de dato Alumno.
		Además se incluyen los prototipos de las funciones para Lectura e Impresión de elementos 
		* de un arreglo	de estructuras.
Autor: SKRV
Fecha: 3/jun/2010
*/


#define CAL 5
#define ML 20
#define MAT 11
#define MM 11

/*Definición de la estructura Alumno, en este momento NO se reserva aún
 * espacio en la memoria.
*/
typedef struct 
{
	char mat[MAT];
	float calif[CAL];
}Alumno;

void Leedatos(Alumno l[ML], int *t);//Alumno *l
/*Se declara la función LeerDatos con dos argumentos por referencia*/

void ImpDatos(Alumno l[ML], int t); // Alumno *l, int t
/*Se declara la función ImpDatos con dos argumentos, uno por referencia y
 * el otro por valor. Los arreglos en C, siempre pasan referencia.*/
void LeeMatricula(char *cad, int r, int c);
void InsertarOrd(Alumno l[ML],int *t);
int menu();
int Buscar (Alumno l[ML], int t, char mat[MAT]);
void Eliminar(Alumno l[ML],int *t, char mat[MAT]);
void Imprimir(Alumno l[ML], int j);
void sus(int x, Alumno l[ML]);
void ustituir(Alumno *dest, Alumno origen);
int CapturaDatos(Alumno *l);
void ModifiCalif(Alumno l[ML],int t,char aux[MAT]);
void OrdenCalif(Alumno l[ML],int t,Alumno auxi[ML]);
 void OrdenCalif(Alumno l[ML],int t,Alumno auxi[ML]);
 void CopiarAr(Alumno ldest[ML],int t,Alumno lorig[ML]);
 void Sustituir(Alumno dest,Alumno origen);
void ModifiCalif(Alumno l[ML],int t,char aux[MAT]);
void LeeContra(char *cad,int max,int r, int c);
