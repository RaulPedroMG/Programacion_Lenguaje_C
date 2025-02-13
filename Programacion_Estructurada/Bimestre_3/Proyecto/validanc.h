/*
Nombre: validanc.h
* Descripcion: Contiene la definición de constantes y declaciones de estructuras.
		Además se incluyen los prototipos de las funciones de lecturas. 
		* de un arreglo	de estructuras.
Autor: Equipo 1

*/
#define MIN 10
#define MAX 100
#define MC 500
#define RET 127//263//127//
#define ENT 10
#define RFC 12
#define MATRI 11
#define CP 6
#define CAL 5


void LeerContra(char *cad, int r, int c);

void LeerClave(char *cad, int r, int c);

void LeerNomEmp(char *cad, int r, int c);

void GenerarClave(char cad[MAX], char clave[MIN - 1], int lon);

void LeerGiroEmp(char *cad, int r, int c);

void LeerDomEmp(char *cad, int r, int c);

void LeerEstEmp(char *cad, int r, int c);

void LeerCpEmp(char *cad, int r, int c);

void LeerTelEmp(char *cad, int r, int c);

void LeerFaxEmp(char *cad, int r, int c);

void LeerContEmp(char *cad, int r, int c);

void LeerCorreoEmp(char *cad, int r, int c);

void LeerVisitaEmp(char *cad, int opc);

void LeerEstanciaEmp(char *cad, int opc);

void LeerServicioEmp(char *cad, int opc);

void Leercad(char *cad);

void LeerNomAlumn(char *cad, int r, int c );

void LeerApellidoAlumn(char *cad, int r, int c);

void LeerClav(char *cad, int r, int c);

void LeerNomProfe(char *cad, int r, int c);

void LeerApellidoProfe(char *cad, int r, int c);






void LeeNombre(char *cad,int max, int r, int c);	

void LeeEntero(char *cad,int max, int r, int c);
 
 void LeeEnteroP(char *cad,int max, int r, int c);
 /* En la cadena se aceptarán solo números enteros positivos, esto es
  * sin signo.
  * */
 void LeeRealP(char *cad, int max, int r, int c);
 /* En la cadena se aceptarán números reales sin signo. No se aceptará
  * el guión, y el punto decimal sólo se permitirá una vez.
  * */
 void LeeReal(char *cad, int max, int r, int c);
 /* En la cadena se aceptarán números reales con signo. Se aceptará
  * el guión solo en la primera posición y el punto decimal sólo se 
  * permitirá una vez.
  * */
 
 void LeeFecha(char *cad, int r, int c);
 /*En la cadena se aceptarán números para representar una fecha en el
  * siguiente formato: dd/mm/aaaa. Los números que se capturarán son
  * dd, mm y aaaa, las diagonales se insertarán automáticamente.
  * Se tiene que verificar que la fecha sea válida a partir del año 
  * 1900.
  * Por ejemplo:  al capturar 1 y pulsar enter, se debe ver en pantalla
  * 				01/
  * al capturar 13 y pulsar enter, debe enviar un mensaje de error
  * 				01/13
  * 				Error, este mes no existe, intente nuevamente!
  * 				01/3
  * al pulsar 3 y enter aparecerá en la pantalla lo siguiente:
  * 				01/03/
  * si se captura 4 y enter deberá enviar el mensaje:
  * 				01/03/4
  * 		Error, el año debe ser con cuatro cifras, intente nuevamente!
  * 				01/03/2001
  * */
 void LeeMatricula(char *cad,int r, int c); //La longitud máxima es 11
 
