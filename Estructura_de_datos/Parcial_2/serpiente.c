#include <ncurses.h>
#include <stdlib.h>

void borde(int x, int y, int filo, int colo);

int main()
{
	int a = 5, b = 5, i = 1, j = 5, ch;
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_BLUE,COLOR_WHITE);
	init_pair(3,COLOR_RED,COLOR_MAGENTA);
	init_pair(4,COLOR_YELLOW,COLOR_BLUE);
	init_pair(5,COLOR_BLUE,COLOR_YELLOW);
	init_pair(6,COLOR_BLUE,COLOR_YELLOW);
	init_pair(7,COLOR_BLACK,COLOR_GREEN);
	init_pair(8,COLOR_WHITE,COLOR_MAGENTA);
	init_pair(9,COLOR_RED,COLOR_CYAN);
	init_pair(10,COLOR_BLACK,COLOR_RED);
	init_pair(11,COLOR_MAGENTA,COLOR_BLUE);
	init_pair(12,COLOR_RED,COLOR_YELLOW);
	init_pair(13,COLOR_WHITE,COLOR_BLACK);
	curs_set(0);
	borde(i, j, a, b);
	/*for(i = 0; i <= 13; i++)
	{
		
		bkgd(COLOR_PAIR(i));
		mvprintw(3,4,"  *************    *               *************  ");
		mvprintw(4,4,"  *                *               *           *   ");
		mvprintw(5,4,"  *                *               *           *   ");
		mvprintw(6,4,"  *                *               *           *      ");
		mvprintw(7,4,"  *                *               *           *      ");
		mvprintw(8,4,"  *   *********    *               *           *     ");
		mvprintw(9,4,"  *           *    *               *           *      ");
		mvprintw(10,4,"  *           *    *               *           *      ");
		mvprintw(11,4,"  *           *    *               *           *          ");
		mvprintw(12,4,"  *************    ************    *************                    ");
		system("sleep 1");
		refresh();
		erase();
	}*/
	bkgd(COLOR_PAIR(4));
	while((ch = getch()) != KEY_F(2))
	{
		switch(ch)
		{
			system("sleep 1");
			case KEY_LEFT:
				borde(i, j, a, --b);
			break;
			
			case KEY_RIGHT:
				borde(i, j, a, ++b);
			break;
	
			case KEY_UP:
				borde(i, j, ++a, b);
			break;

			case KEY_DOWN:
				borde(i, j, --a, b);
			break;
		}
	}

	getch();
	endwin();
	return 0;
}

void borde (int x, int y, int filo, int colo)
{
	int i =0;
	for(i = x; i < y; i++)
	{
		mvprintw(filo+i, colo, "#");
	}
}
