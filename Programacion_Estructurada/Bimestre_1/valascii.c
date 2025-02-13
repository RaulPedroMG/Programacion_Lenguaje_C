#include <ncurses.h>
int main()
{
	char car;
	int x=0;
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	clear();
	while(x==0)
	 {
		mvprintw(2,5,"introduce caracter:");
		car=getch();
		mvprintw(4,5,"Ascii %d:",car);
		if(car==10)
			x=1;
       	 }
	getch();
	endwin();
	return 0;
}
	
