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

/*Definición de la estructura Alumno, en este momento NO se reserva aún
 * espacio en la memoria.
*/
typedef struct 
{
	char mat[MAT];
	float calif[CAL];
}Alumno;

typedef struct 
{
	char clave[10];
	char *nom;
	char *giro;
	char *dom;
	char *edo;
	int cp;
	char *tel;
	char *fax;
	char *cont;
	char *correo;
	char visita;
	char est;
	char ss;
}Empresa;


void SeparaCad(Empresa *catemp,int *cont,char *cad);

int MenuP ();

int Menu1 ();

int Menu2 ();

void Empresas (Empresa *catemp,int cont);

void CosultarEmp(Empresa *catemp,int cont);

void ListaEmp(Empresa *catemp,int cont);

void Alumnos ();

void Profesores ();

void Visitas ();

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

void InsertarOrd(Alumno l[ML],int *t);
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
 
 
