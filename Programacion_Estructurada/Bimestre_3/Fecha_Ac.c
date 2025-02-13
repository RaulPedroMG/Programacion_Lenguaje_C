#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 40
#define M 11

void LeeFecha(char *cad, int r, int c);

int main ()
{
	char cad [M];
	initscr();
	keypad(stdscr, TRUE);
	noecho();   
	clear();
	mvprintw(8,5,"Introduce una fecha:");
	LeeFecha (cad,8,28);
		
	getch();
	endwin();
	return 0;
} 


void LeeFecha(char *cad, int r, int c)
 {
	int d, m, a, fec = 0, band=0;
	int aux;
	char num1[3], num2[3], num3[5];
	int ind=0;
	
	do
	{
		ind=0;
		while (ind < M  && band == 0)
		{
				do
				{
					move(r,c+ind);
					aux = getch();
				}while (aux != 7 && aux != 10 && !isdigit(aux));
				if (ind >= 0 && ind <=2)
				{	
					if (ind == 0)
					{	
						num1[0] = cad[ind];
					}
					if (ind == 1)
					{	
						num1[1] = cad[ind];
					}
					if (ind == 2)
					{
						num1[2] = '\0';
					}
				}
					
				if (ind >= 3 && ind <=5)
				{
					if (ind == 3)
					{
						num2[0]=cad[ind];
					}
					if (ind == 4)
					{
						num2[1]=cad[ind];
					}
					if (ind == 5)
					{
						num2[2] = '\0';
					}
					
				}
								
				if (ind >= 6 && ind <=9)
				{
					if (ind == 6)
					{
						num3[0]=cad[ind];
					}
					if (ind == 7)
					{
						num3[1]=cad[ind];
					}
					if (ind == 8)
					{
						num3[2]=cad[ind];
					}
					if (ind == 9)
					{
						num3[3]=cad[ind];
					}
				}
				switch(aux)
				{
					case 7: 
						if (ind > 0)
						{
							ind--;
							move(r,c+ind);
							printw(" ");
						}
						break;
					case 10:
							if(ind > 1)
							{
								d = atoi(num1);
								if (d > 0 && d < 10)
								{
									//mvprintw(r,c,"   ");
									mvprintw(r,c,"0%d/",d);
								}
							}
							if(ind > 4)
							{
								m = atoi(num2);
								if (m > 0 && m < 10)
								{
									//mvprintw(r,c+3,"   ");
									mvprintw(r,c+3,"0%d/",m);
								}
							}
							break;
				}
				cad[ind] = aux;
				move(r,c+ind);
				printw("%c",aux);
				ind++;
							
				if (ind == 2 || ind == 5)
				{
					cad[ind] = '/';
					move(r,c+ind);
					printw("/");
					ind++;
				}
			}
		
		if (ind == M)
			cad[ind] = '\0';
		num3[4] = '\0';
		a = atoi(num3);
		
		
		if(a >= 1900)
		{
			if(m >= 1 && m <= 12)
			{
				if(m == 2)
				{
					if(a % 400 == 0 && a % 4 == 0)
					{
						if(d >= 1 && d <= 29)
						{
							fec=1;
						}
					}	
					else	
					{
						if(d >= 1 && d <= 28)
						{
							fec=1;
						}
					}
				}
				else
				{
					if(m ==4  || m == 6 || m == 9 || m == 11)
					{
						if(d >= 1 && d <= 30)
						{
							fec=1;
						}
					}
					else
					{	
						if(m ==1  || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
						{
							if(d >= 1 && d <= 31)
							{
								fec=1;
							}
						}	
					}		
				}
			}
		}	
		if (fec == 1)
		{
			mvprintw (r+4,2,"                                           ");
		} 
		if (fec == 0)
		{
			mvprintw (r+4,2,"La fecha es invalida, vuelva a introducirla");
			mvprintw (8,28,"           ");
			move(r,c);
		}
	
	}while (fec != 0);
	
}
