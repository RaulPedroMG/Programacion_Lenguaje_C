#define MC 500
#define RET 127//263
#define ENT 10
//	TAREA PARA EL PRÓXIMO LUNES 2 DE MAYO DE 2011
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
 void LeeRFC(char *cad, int r, int c);
 /* En la cadena se aceptarán números que representen el RFC de una
  * persona, con las siguientes restricciones:
  * 		GORF-920228
  * 	Los cuatros primeros caracteres serán letras del alfabeto, pero
  * 	el segundo caracter solo puede ser una vocal.
  * 	Los seis últimos caracteres serán dígitos numéricos, los dos
  * 	primeros para el año (00 - 99). Los siguientes dos, para indicar
  * 	el mes de nacimiento (01-12) y los últimos 2 para el día.
  * 	Se debe verificar que el número de días corresponda al mes y al
  * 	año.
  * */
 void LeeCad(char *cad, int max, int r, int c);
 /* En esta cadena pueden capturar todos los caracteres imprimibles 
  * válidos.
  * */
 void LeeCorreo (char *cad, int max, int r, int c);
 /* En esta cadena podrán capturar una cadena que represente una 
  * dirección de correo electrónico:
  * Ejemplos de direcciones de correo válidas:
  * 	quid123_er.ra@gmail.com
  * 	har_r4_32_@hotmail.com
  * 	iuhx_1_2@yahoo.com.mx
  * */
 void LeeContra (char *cad, int r, int c);
 /* La cadena permitirá un máximo de 10 caracteres, deberán verificar
  * que la contraseña tenga al menos un dígito, una letra del alfabeto
  * y al menos un caracter siguiente (. , - / # ).
  * Los caracteres no deben visualizarse en la pantalla, por cada
  * caracter se imprimirán un asteriscto (*).
  * */
 void LeeMatricula(char *cad,int r, int c); //La longitud máxima es 11
 

int LeeInt(int r, int c);
float LeeFloat(int r, int c);
