/*
Nombre: estruct.h
Descripción: Contiene la definición de constantes y las esstructuras a utilizar.
		Ademas la declaración de las funciones a utilizar.
Autor: Equipo 1.
*/
#define MIN 10
#define MAX 100
#define CAL 5
#define ML 200
#define MAT 11
#define A 1

/*Definición de la estructura Alumno, en este momento NO se reserva aún
 * espacio en la memoria.
*/
typedef struct 
{
	char mat[MAT];
	char *nomalum;
	char *apealum;
}Alumno;

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
	char clav[CAL];
	char *nomprofe;
	char *apeprofe;
}Profesor;
/*
typedef struct
{
	char *claveprofe;
	Profesor nombprofe;
	char *clavemp;
	char *calif;
	char *beca;
	Fecha *fechavis;
}Visita;

typedef struct
{
	char *mes;
	char *anio;
}Fecha;
/*
typedef struct
{
	char *inicio;
	char *termino;
	int aniop;
}Periodo;

*/
void SeparaCad(Empresa *catemp,int *cont,char *cad);

void GuardarEmpText(Empresa *catemp,int cont);

void SeparaCadAlumn(Alumno *catalumn,int *cont,char *cad);

void GuardarAlumText(Alumno *catalumn,int cont);

void SeparaCadProfe(Profesor *catprofe, int *cont, char *cad);

void GuardarProfeText(Profesor *catprofe,int cont);

int MenuP ();

int Menu1 (char *cad);

int Menu2 ();

void Empresas (Empresa *catemp,int *cont);

void EliminarEmp(Empresa *catemp,int *t);

int BuscarEmp(Empresa *catemp,int t, char clave[MIN]);

void BorrarEmp(Empresa *catemp,int *total, int ind);

void ModificarEmp(Empresa *catemp,int t);

void CosultarEmp(Empresa *catemp,int t);

void ListaEmp(Empresa *catemp,int cont, int *rr, char clave[MIN]);

void ImprimirEmp2 (Empresa *catemp, int t);

void ImprimirEmp(Empresa *catemp, int i);

void Alumnos (Alumno *catalumn,int *cont);

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

void Profesores (Profesor *catprofe, int *cont);

void RegistrarProfe(Profesor *catprofe, int *t);

void EliminarProfe(Profesor *catprofe, int *t);

int BuscarProfe( Profesor *catprofe, int t, char clav[CAL]);

void BorrarProfe(Profesor *catprofe, int *total, int ind);

void ModificarProfe(Profesor *catprofe, int t);

void ConsultarProfe(Profesor *catprofe, int t);

int ImprimirProfeMod (Profesor *catprofe, int i);

void ImprimirProfe (Profesor *catprofe, int i);

void ImprimirProfe2 (Profesor *catprofe, int t);

//void Visitas (Visita *lisvisita,int *t,Profesor *catprofe, int *to, Empresa *catemp, int *cont);

//void RegistarVisita(Visita *lisvisita,int *t,Profesor *catprofe, int *to, Empresa *catemp, int *cont);

void CosultarVisita ();

void Estancias ();

void Servicios ();


void LeeDatos(Alumno l[ML], int *t);//Alumno *l
/*Se declara la función LeerDatos con dos argumentos por referencia*/

void ImpDatos(Alumno l[ML], int t); // Alumno *l, int t
/*Se declara la función ImpDatos con dos argumentos, uno por referencia y
 * el otro por valor. Los arreglos en C, siempre pasan referencia.*/

void BuscarMayor(Alumno l[ML],int t, int cont[ML], int *j);
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Guardará en el arreglo cont, los índices
 * de los alumnos con mayor calificación, en *j, se almacenará
 * el total de alumnos con la mayor calificación
 * Ejemplo
 * 0 	2004060071	------------	7.8
 * 1	2004060098	------------	8.5
 * 2	2004060099	------------	6.4
 * 3	2005060008	------------	5.4
 * 4	2005060019	------------	8.5
 * 5	2005060111	------------	5.3
 * 6	2006060001	------------	4.5
 * 7	2006060025	------------	8.5
 * 8	2006060085	------------	6.4
 * 9	2006060092	------------	8.5
 * 10	2006060142	------------	3.5
 * 11	2006060214	------------	7.9
 * 12	2006060215	------------	8.5
 * 13	2007060021	------------	6.6
 * 14	2007060042	------------	6.7
 * 15	2007060084	------------	8.5
 * 
 * El vector resultante en cont, quedaría de la siguiente manera
 * 1
 * 4
 * 7
 * 9
 * 12
 * 15
 * el valor de j sería 6
*/

void BuscarMenor(Alumno l[ML],int t, int cont[ML], int *j);
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Guardará en el arreglo cont, los índices
 * de los alumnos con menor calificación, en *j, se almacenará
 * el total de alumnos con la menor calificación
 * Ejemplo
 * 0 	2004060071	------------	7.8
 * 1	2004060098	------------	8.5
 * 2	2004060099	------------	6.4
 * 3	2005060008	------------	5.4
 * 4	2005060019	------------	8.5
 * 5	2005060111	------------	5.3
 * 6	2006060001	------------	4.5
 * 7	2006060025	------------	8.5
 * 8	2006060085	------------	6.4
 * 9	2006060092	------------	8.5
 * 10	2006060142	------------	3.5
 * 11	2006060214	------------	7.9
 * 12	2006060215	------------	8.5
 * 13	2007060021	------------	6.6
 * 14	2007060042	------------	6.7
 * 15	2007060084	------------	8.5
 * 
 * El vector resultante en cont, quedaría de la siguiente manera
 * 10
 * el valor de j sería 1
 */
 
 void ImprimirVector(Alumno l[ML], int cont[ML], int j);
/*Este procedimiento recibe la lista de alumnos, el vector cont que contiene
 * los índices con las calificaciones (mayores o menores) y el total (j) de
 * elementos cont
 * */
  
void BuscarAprobados(Alumno l[ML],int t, int cont[ML], int *j);
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Guardará en el arreglo cont, los índices
 * de los alumnos aprobados, en *j, se almacenará el total de alumnos
 * aprobados.
 * Ejemplo
 * 0 	2004060071	------------	7.8
 * 1	2004060098	------------	8.5
 * 2	2004060099	------------	6.4
 * 3	2005060008	------------	5.4
 * 4	2005060019	------------	8.5
 * 5	2005060111	------------	5.3
 * 6	2006060001	------------	4.5
 * 7	2006060025	------------	8.5
 * 8	2006060085	------------	6.4
 * 9	2006060092	------------	8.5
 * 10	2006060142	------------	3.5
 * 11	2006060214	------------	7.9
 * 12	2006060215	------------	8.5
 * 13	2007060021	------------	6.6
 * 14	2007060042	------------	6.7
 * 15	2007060084	------------	8.5
 * 
 * El vector resultante en cont, quedaría de la siguiente manera
 * 0
 * 1
 * 2
 * 4
 * 7
 * 8
 * 9
 * 11
 * 12
 * 13
 * 14
 * 15
 * el valor de j sería 12
*/

void BuscarReprobados(Alumno l[ML],int t, int cont[ML], int *j);
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Guardará en el arreglo cont, los índices
 * de los alumnos reprobados, en *j, se almacenará el total de alumnos
 * reprobados.
 * Ejemplo
 * 0 	2004060071	------------	7.8
 * 1	2004060098	------------	8.5
 * 2	2004060099	------------	6.4
 * 3	2005060008	------------	5.4
 * 4	2005060019	------------	8.5
 * 5	2005060111	------------	5.3
 * 6	2006060001	------------	4.5
 * 7	2006060025	------------	8.5
 * 8	2006060085	------------	6.4
 * 9	2006060092	------------	8.5
 * 10	2006060142	------------	3.5
 * 11	2006060214	------------	7.9
 * 12	2006060215	------------	8.5
 * 13	2007060021	------------	6.6
 * 14	2007060042	------------	6.7
 * 15	2007060084	------------	8.5
 * 
 * El vector resultante en cont, quedaría de la siguiente manera
 * 3
 * 5
 * 6
 * 10
  * el valor de j sería 4
*/

//void InsertarOrd(Alumno l[ML],int *t);
/* Se insertarán los datos de los alumnos en forma ordenada por la matrícula, 
 * la variable t se incrementará conforme se agreguen datos al arreglo.
 * 
 * Ejemplo:
 * 
 * Si el arreglo está vacío, t vale 0. Al insertar la matrícula 2006060001
 * se colocará en la posición t, no hay necesidad de revisar donde le 
 * corresponde insertarse, ya que el arreglo está vacío.
 * Después de insertar la matrícula se leen las calificaciones y se calcula
 * la calificación final.
 * 
 * 0 2006060001	------------	4.5
 * 
 * Si el arreglo ya tiene al menos un elemento, al capturarse la matrícula
 * se debe comparar para verificar si es mayor que la última y colocarla
 * al final. Por ejemplo si se inserta la matrícula 2006060215, comparándola
 * con el último elemento que es 2006060001, vemos que le corresponde la
 * posición final, por lo que solo se inserta en la posición t=1.
 * 
 * 0	2006060001	------------	4.5
 * 1	2006060215	------------	8.5
 * 
 * Si ya tenemos dos elementos en el arreglo (t=2), y se inserta la matrícula
 * 2005060008, que no es mayor que la última, entonces se tendrá que encontrar
 * la posición donde le corresponde insertarse. Se compara con la primera matrícula
 * si es menor la que intentamos insertar, entonces este es el espacio que le 
 * corresponde, y el resto de registros se mueven una posición hacia abajo, 
 * empezando del último elemento. Al recorrer los datos del arreglo quedaría como
 * sigue:
 * 
 * 0	2006060001	------------	4.5
 * 1	2006060001	------------	4.5
 * 2	2006060215	------------	8.5
 * 
 * entonces ya podemos insertar la nueva matrícula: 
 * 
 * 0	2005060008	------------	5.4
 * 1	2006060001	------------	4.5
 * 2	2006060215	------------	8.5
*/ 

int Buscar(Alumno l[ML],int *t, char mat[MAT]);
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Devolverá el índice donde localizó la 
 * matrícula mat, si no encontró la matrícula devolverá -1.
 * Ejemplo
 * 0 	2004060071	------------	7.8
 * 1	2004060098	------------	8.5
 * 2	2004060099	------------	6.4
 * 3	2005060008	------------	5.4
 * 4	2005060019	------------	8.5
 * 5	2005060111	------------	5.3
 * 6	2006060001	------------	4.5
 * 7	2006060025	------------	8.5
 * 8	2006060085	------------	6.4
 * 9	2006060092	------------	8.5
 * 10	2006060142	------------	3.5
 * 11	2006060214	------------	7.9
 * 12	2006060215	------------	8.5
 * 13	2007060021	------------	6.6
 * 14	2007060042	------------	6.7
 * 15	2007060084	------------	8.5
 * 
 * Si la matrícula que se busca es: 2006060142
 * 
 * Nos regresará el valor de 10.
 * 
 * Si se busca la matrícula 2006060200 entonces el valor que regresará es -1
 * 
 */

void Eliminar(Alumno l[ML],int *t, char mat[MAT]);
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Eliminará el registro donde localice la 
 * matrícula mat, pedirá confirmación para eliminarla.
 * Enviará un mensaje si la matrícula no se encontró.
 * Ejemplo
 * 0 	2004060071	------------	7.8
 * 1	2004060098	------------	8.5
 * 2	2004060099	------------	6.4
 * 3	2005060008	------------	5.4
 * 4	2005060019	------------	8.5
 * 5	2005060111	------------	5.3
 * 6	2006060001	------------	4.5
 * 7	2006060025	------------	8.5
 * 8	2006060085	------------	6.4
 * 9	2006060092	------------	8.5
 * 10	2006060142	------------	3.5
 * 11	2006060214	------------	7.9
 * 12	2006060215	------------	8.5
 * 13	2007060021	------------	6.6
 * 14	2007060042	------------	6.7
 * 15	2007060084	------------	8.5
 * 
 * 
 */
 
 
