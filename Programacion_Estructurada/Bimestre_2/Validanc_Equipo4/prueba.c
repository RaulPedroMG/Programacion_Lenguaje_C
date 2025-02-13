# include <ncurses.h>
#include "validanc.h"
#define MAX 40
#define M 10
int main ()
{
	
	int n1,n2,n3,x=0;
	char nombre[MAX], cad [M];
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	while (x==0) 
	{   
		clear();
		
		mvprintw(2,5,"Introduce el primer numero:");
		n1 = LeeInt (2, 35);
		mvprintw(4,5,"Introduce el segundo numero:");
		n2 = LeeInt (4, 35);
		mvprintw(6,5,"Introduce el tercer numero:\t");
		n3 = LeeInt (6, 35);
		
		mvprintw(8,5,"Introduce una fecha:");
		LeeFecha (cad,8,28);
		
		mvprintw(10,5,"¿Cuál es tu nombre?:");
		LeeNombre(nombre,MAX,10,35);
		if (n1<n2 && n2<n3) 
		{
			mvprintw (12,2,"%s capturaste en forma ascendente los valores: %d, %d, %d",nombre,n1,n2,n3);
				x=1;
		}else 
			mvprintw(12,2,"Vuelva a introducir los datos");
   }	
	getch();
	endwin();
	return 0;
} 
