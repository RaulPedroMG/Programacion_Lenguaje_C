#include <ncurses.h>
#include <stdlib.h>

void marco(int filaO, int columnaO, int largo, int ancho, char borde, char relleno)
{
	int i,j;

	for(i=filaO; i<filaO+ancho;i++)	
		for(j=columnaO; j<columnaO+largo;j++)	
			{
			if(i==filaO || i==filaO+ancho-1)		
			mvprintw(i,j,"%c",borde);
			else if(j==columnaO || j==columnaO+largo-1)
				mvprintw(i,j,"%c",borde);
			else 
				mvprintw(i,j,"%c",relleno);
			}		
}

int main()
{
	int r = 5, c = 40, i, j;
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_BLUE,COLOR_WHITE);
	init_pair(3,COLOR_RED,COLOR_MAGENTA);
	init_pair(4,COLOR_YELLOW,COLOR_BLUE);
	init_pair(5,COLOR_BLUE,COLOR_YELLOW);
	init_pair(6,COLOR_BLUE,COLOR_BLACK);
	init_pair(7,COLOR_BLACK,COLOR_GREEN);
	init_pair(8,COLOR_WHITE,COLOR_MAGENTA);
	init_pair(9,COLOR_RED,COLOR_CYAN);
	init_pair(10,COLOR_BLACK,COLOR_RED);
	init_pair(11,COLOR_YELLOW,COLOR_BLUE);
	init_pair(12,COLOR_RED,COLOR_YELLOW);
	init_pair(13,COLOR_WHITE,COLOR_BLACK);
	curs_set(0);
	for(i = 1; i <= 25; i++)
	{
		j = i % 7;
		bkgd(COLOR_PAIR(j));
		if(i < 8)
		{ 
			clear();
			attron(COLOR_PAIR(13));
			marco(-30,15,160,130,'#','-');
			attron(COLOR_PAIR(10));
			mvprintw(r,c,"  *********    *********    *            *******    ****          **********    ****          *********     *********    ");
			mvprintw(r+1,c,"  *            *            *               *       *    **       *        *    *    **       *             *            ");
			mvprintw(r+2,c ,"  *            *            *               *       *      **     *        *    *      **     *             *            ");
			mvprintw(r+3,c,"  *********    *            *               *       *        *    *      * *    *        *    *             *            ");
			mvprintw(r+4,c,"  *            *********    *               *       *        *    *   *    *    *        *    *********     *********    ");
			mvprintw(r+5,c,"  *            *            *               *       *        *    * *      *    *        *    *                     *    ");
			mvprintw(r+6,c,"  *            *            *               *       *      **     *        *    *      **     *                     *    ");
			mvprintw(r+7,c,"  *            *            *               *       *    **       *        *    *    **       *                     *    ");
			mvprintw(r+8,c,"  *            *********    *********    *******    ****          *        *    ****          *********     *********    ");

			mvprintw(r+14,c+15,"  *********    *        *          *************    *          *    ***********   ");
			mvprintw(r+15,c+15,"  *            * *      *                *          *          *    *             ");
			mvprintw(r+16,c+15,"  *            *  *     *                *          *          *    *             ");
			mvprintw(r+17,c+15,"  *            *  *     *                *          *          *    *             ");
			mvprintw(r+18,c+15,"  *********    *   *    *                *          *          *    ***********   ");
			mvprintw(r+19,c+15,"  *            *    *   *                *          *          *              *   ");
			mvprintw(r+20,c+15,"  *            *    *   *                *          *          *              *   ");
			mvprintw(r+21,c+15,"  *            *     *  *                *          *          *              *   ");
			mvprintw(r+22,c+15,"  *********    *      * *                *          ************    ***********   ");
		}
		if(i > 7 && i < 16)
		{
			clear();
			attron(COLOR_PAIR(13));
			marco(-30,15,160,130,'#','-');
			attron(COLOR_PAIR(10));
			mvprintw(r,c+4,"  **********    *          *    * ");
			mvprintw(r+5,c,"  *            *          *    *            ");
			mvprintw(r+6,c ,"  *            *         *    *               ");
			mvprintw(r+7,c,"  *            *         *    *                ");
			mvprintw(r+8,c,"  *            *         *    *              ");
			mvprintw(r+9,c,"  *            *         *                            ");
			mvprintw(r+10,c,"  *            *         *                        ");
			mvprintw(r+11,c,"  *            *         *                       ");
			mvprintw(r+12,c,"  **********   ***********         ");

		}
		system("sleep 1");
		refresh();
		erase();
	}
	endwin();
	return 0;
}

