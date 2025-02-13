#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#define ENTER 10
#define ESCAPE 27
#define RET 127


//FUNCIONES SIN COMENTARIOS
//*****************************************************************************************************************
void init_curses()
{
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    init_pair(4,COLOR_WHITE,COLOR_BLACK);
    init_pair(5,COLOR_CYAN, COLOR_WHITE);
    curs_set(0);
    noecho();
    keypad(stdscr,TRUE);
}

WINDOW **dibuja_menus(int colum, int fila, int num_ele, char menu[15][18])
{
	int i;
	WINDOW **campo;
	campo=(WINDOW **)malloc((num_ele + 2)*sizeof(WINDOW *));
	campo[0]=newwin(num_ele + 2,19,fila+1,colum+1);
	
	wbkgd(campo[0],COLOR_PAIR(4));
	campo[1]=newwin(num_ele + 2,19,fila,colum);
	wbkgd(campo[1],COLOR_PAIR(3));
	box(campo[1],ACS_VLINE,ACS_HLINE);
	for(i = 2;i <= num_ele+1;i++)
	{
		campo[i]=subwin(campo[1],1,17,fila+i-1,colum+1);
		wprintw(campo[i],"%s",menu[i-2]);
	}
	wbkgd(campo[2],COLOR_PAIR(1));
   	int x;
   	for (x = 0; x <num_ele; x++)
   		wrefresh(campo[x]);
    return campo;
}

void borrar_menu(WINDOW **campos,int n_campos)
{
    int i;
    for (i=0;i<n_campos;i++)
        delwin(campos[i]);
    free(campos);
    touchwin(stdscr);
}

void dibujar_barra(WINDOW *barra, int num_menu, char menu[8][15])
{
	int x;
	for(x = 0; x <num_menu; x++)
	{
		wbkgd(barra,COLOR_PAIR(2));
		wmove(barra,0,(x*20)+x);
		wbkgd(barra,COLOR_PAIR(2));
		wprintw(barra,"%s   ",menu[x]);
		wprintw(barra,"(F%d)",x+2);
	}
}

int scroll_menu(WINDOW **items,int count)
{
    int key;
    int selected=1;
    while (1){
        key=getch();
        if (key==KEY_DOWN || key==KEY_UP) 
        {
        	if(selected != 0)
        	{
            	wbkgd(items[selected+1],COLOR_PAIR(3));
            	wnoutrefresh(items[selected+1]);
			}
            if (key==KEY_DOWN)
            {
                selected=(selected+1) % count;
            }
            else
            {
                selected=(selected+count-1) % count;
            }
            if(selected != 0)
            {
            	wbkgd(items[selected+1],COLOR_PAIR(1));
            	wnoutrefresh(items[selected+1]);
			}
            doupdate();
        }
        else
        {
        	if(key==KEY_LEFT)
        		return -2;
        	if(key==KEY_RIGHT)
        		return -3;
        	if (key==ESCAPE)
            	return -1;
        	else
        		if (key==ENTER)
            		return selected;
         }
            		
	}
    
}

void Opciones(int *menu, int *opc)
{
	int max_men = 9;
	int ele[8] = {10,10,10,10,10,10,10,10};
	char menus[8][10][18]={{"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",}};
	*menu = 0;
	WINDOW **menu_items;
	int alto = 0;
	while (alto == 0)
	{
	    refresh();
		menu_items=dibuja_menus((*menu)*20,1, ele[*menu], menus[*menu]);
	    *opc = scroll_menu(menu_items,ele[*menu]+1);
	    borrar_menu(menu_items,ele[*menu]);
	    if (*opc == -2)
	    	if(*menu == 0)
	    		(*menu) = max_men -1;
	    	else
	    		(*menu)--;
	    else
	    	if(*opc == -3)
	    		if (*menu == max_men - 1)
	    			(*menu) = 0;
	    		else
	    			(*menu)++;
	    	else
	    		alto = 1;

	}
}

void Maximiza()
{
   	int ren,col;
   	do
   	{
		getmaxyx(stdscr, ren, col);
		if (ren < 20 || col < 160)
			printw("\nMaximize la pantalla para que pueda trabajar");
			getch();
	}while (ren < 20 || col < 160);
	clear();
}

//*****************************************************************************************************************

int main()
{
	init_curses();//inicializar el modo n-curses
	Maximiza();
	//Creacion de la barra
	//**************************************************************************
	WINDOW *barra;
	char men[8][15]={"Menú 1","Menú 2","Menú 3","Menu 4", "Menu 5", "Menu 6", "Menu 7", "Menu 8"};
   	bkgd(COLOR_PAIR(1));
 	barra = subwin(stdscr,1,160,0,0);
 	wbkgd(barra,COLOR_PAIR(4));
 	dibujar_barra(barra,10,men);
 	getch();
 	//**************************************************************************
    //Creación he impresion de los menús
    //**************************************************************************
    int n, m;
    Opciones(&n,&m);
    move(2,2);
    printw("Menu: %d,        Opción %d",n,m);
    getch();
    //**************************************************************************
    delwin(barra);//Borrar la barra 
    endwin();//Salir del modo ventanas 
	return 0;
}


