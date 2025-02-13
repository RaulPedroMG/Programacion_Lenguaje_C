# include <stdio.h>
# include <time.h>

int main ()
{
  time_t inicio, final;
  caracteres szInput [256];
   doble DIF;

  tiempo (y principio);
  printf ( "Por favor, ingrese su nombre:" );
  gets (szInput);
  tiempo (y final);
  DIF = difftime (final, inicio);
  printf ( "Hola% s. \ n" , szInput);
  printf ( "Le tomó% 0,2 segundos Si al escribir su nombre \ n", DIF);
 
  retorno 0;
}
