#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

int d=0;
int main()
{
char a;
initscr();
  echo();
  printw("Cronometro en segundos, pulse P  para parar:");
 
  do{
  //cronometro();
  refresh();
  }while ((a=getch()) != 'P');

  printw("nPulse un tecla para salir.");
  getch();
  endwin();
  return 0;
}
 
int cronometro()
{
  int e=d;
 
  for (d=0; d < e+1 ; d++)
  {
	printw("%dn", d);
	sleep(1);
  refresh();
  }
  return 0;
}
