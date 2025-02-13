#include <curses.h>
#include <stdlib.h>
#define ENTER 10
#define ESCAPE 27

void init_curses();
void DibujaBarras(WINDOW *menubar);
WINDOW **Dibujamenus(int start_col);
void Borra_menu(WINDOW **items,int count);
int scroll_menu(WINDOW **items,int count,int menu_start_col);

int main()
{
	int key;
	WINDOW *menubar,*messagebar;
	init_curses();
	bkgd(COLOR_PAIR(1));
	menubar=subwin(stdscr,1,80,0,0);
	messagebar=subwin(stdscr,1,79,23,1);
	DibujaBarras(menubar);
	move(2,1);
	printw("Presione F1 o F2 para abrir menú. ");
	printw("ESC para salir");
	refresh();
	do 
	{
		int selected_item;
		WINDOW **menu_items;
		key=getch();
		werase(messagebar);
		wrefresh(messagebar);
		if (key==KEY_F(1)) 
		{
			menu_items = Dibujamenus(0);
			selected_item = scroll_menu(menu_items,3,0);
			Borra_menu(menu_items,3);
			if (selected_item<0)
			{
				wprintw(messagebar,"No seleccionaste ningún menú");
			}
			else
			{
				wprintw(messagebar,"Has seleccionado en menú %d",selected_item+1);
			}
			touchwin(stdscr);
			refresh();
		} 
		else
		{ 
			if (key==KEY_F(2)) 
			{
				menu_items = Dibujamenus(20);
				selected_item=scroll_menu(menu_items,3,20);
				Borra_menu(menu_items,4);
			}
			if (selected_item<0)
			{
				wprintw(messagebar,"No seleccionaste ningún menú");
			}
			else
			{
				wprintw(messagebar, "La opción que escogiste es : %d",selected_item+1);
			}
			touchwin(stdscr);
			refresh();
		}
	} while (key!=ESCAPE);
	delwin(menubar);
	delwin(messagebar);
	endwin();
	return 0;
}

void init_curses()
{
	initscr();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_BLUE,COLOR_WHITE);
	init_pair(3,COLOR_RED,COLOR_WHITE);
	init_pair(4,COLOR_WHITE,COLOR_BLUE);
	init_pair(5,COLOR_BLUE,COLOR_YELLOW);
	init_pair(6,COLOR_BLUE,COLOR_GREEN);
	curs_set(0);
	noecho();
	keypad(stdscr,TRUE);
}

void DibujaBarras(WINDOW *menubar)
{
	wbkgd(menubar,COLOR_PAIR(4));
	waddstr(menubar,"Menu1");
	wattron(menubar,COLOR_PAIR(4));
	waddstr(menubar,"(F1)");
	wattroff(menubar,COLOR_PAIR(4));
	wmove(menubar,0,20);
	waddstr(menubar,"Menu2");
	wattron(menubar,COLOR_PAIR(4));
	waddstr(menubar,"(F2)");
	wattroff(menubar,COLOR_PAIR(4));
}

WINDOW **Dibujamenus(int start_col)
{ 
	//int i;
	WINDOW **items;
	items=(WINDOW **)malloc(4*sizeof(WINDOW *));
	items[0]=newwin(10,19,1,start_col);
	wbkgd(items[0],COLOR_PAIR(2));
	box(items[0],ACS_VLINE,ACS_HLINE);
	items[1]=subwin(items[0],1,17,2,start_col+1);
	wprintw(items[1],"JUGAR");
	items[2]=subwin(items[0],1,17,3,start_col+1);
	wprintw(items[2],"VER RANCKING");
	items[3]=subwin(items[0],1,17,4,start_col+1);
	wprintw(items[3],"SALIR");
	//items[4]=subwin(items[0],1,17,5,start_col+1);
	//items[5]=subwin(items[0],1,17,6,start_col+1);
	//items[6]=subwin(items[0],1,17,7,start_col+1);
	//items[7]=subwin(items[0],1,17,8,start_col+1);
	//items[8]=subwin(items[0],1,17,9,start_col+1);
	//for (i=1;i<9;i++)
	//{
	
	//}
	wbkgd(items[1],COLOR_PAIR(1));
	wrefresh(items[0]);
	return items;
}

void Borra_menu(WINDOW **items,int count)
{
	int i;
	for (i=0;i<count;i++)
	{
		delwin(items[i]);
	}
	free(items);
}

int scroll_menu(WINDOW **items,int count,int menu_start_col)
{
	int key;
	int selected=0;
	while (1) 
	{
		key=getch();
		if (key==KEY_DOWN || key==KEY_UP) 
		{
			wbkgd(items[selected+1],COLOR_PAIR(2));
			wnoutrefresh(items[selected+1]);
			if (key==KEY_DOWN) 
			{
				selected=(selected+1) % count;
			} 
			else 
			{
				selected=(selected+count-1) % count;
			}
			wbkgd(items[selected+1],COLOR_PAIR(1));
			wnoutrefresh(items[selected+1]);
			doupdate();
		} 
		else
		{ 
			if (key==KEY_LEFT || key==KEY_RIGHT) 
			{
				Borra_menu(items,count+1);
				touchwin(stdscr);
				refresh();
				items=Dibujamenus(20-menu_start_col);
				return scroll_menu(items,3,20-menu_start_col);
			} 
			else
			{ 
				if (key==ESCAPE) 
				{
					return -1;
				}
				else
				{
					if (key==ENTER)
					{
						return selected;
					}
				}
			}
		}
	}
}



