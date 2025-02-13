#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>


//CONTANTES OCUPADAS 
#define ENTER 10
#define ESCAPE 27
#define RET 127


void init_curses()
/* Función que inicializa el modo n_curses
 * En ella se crean algunas combinaciones de colores 
 * con la instrucción init_pair("Numero de combinacion",COLORES)
 * apaga el echo y activa las teclas especiales.
 */
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




WINDOW **dibuja_menus(int colum, int fila, int num_ele, char menu[15][18])//numero de elementos y longitud de la cadena
/* 
 * Funcion la cual crea una lista desplegable de menús recibiendo como argumento
 * * La columna inicial
 * * La fila inicial
 * * El número de elementos "Maximo 15"
 * * Un arreglo de caracteres de dimenciones [15][18] que contenga las opciones deseadas
 * y devolviendo un doble apuntador a ventana
 * ELABORÓ: Adrián Josué Ramírez Díaz
 */
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
/* 
 * Funcion la cual borra una lista desplegable creada, recibe como argumentos:
 * * Un doble apuntador a ventana, el cual será el que se borrará 
 * * El número de ventanas que contiene dicho apuntador
 * ELABORÓ: Adrián Josué Ramírez Díaz
 */
{
    int i;
    for (i=0;i<n_campos;i++)
        delwin(campos[i]);
    free(campos);
    touchwin(stdscr);
}

void dibujar_barra(WINDOW *barra, int num_menu, char menu[8][15])
/*
 * Funcion que dibuja una barra de menús, recibe como argumentos el número de menús
 * ademas de un arreglo que contenga los nombres de cada menú,  combiene que se
 * dibuje en una ventana con las sig. dimenciones largo: 160, ancho 1 para el buen funcionamiento de la barra
 */
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
/* Funcion que da el movimiento al menú dibujado, recibe un deble apuntador a ventana y en número de opciones del menú
 * con las teclas de dirección arriba y abajo se puede mover atraves de los menús.
 * - Si está seleccionada una opción,y se presiona enter devuelve el número de menú selecionado
 * - Si se presiona la tecla ESCAPE devuelve un -1
 * - Si se presiona la tecla IZQUIERDA de las líneas de dirección devuelve -2
 * - Si se presiona la tecla DERECHA de las líneas de dirección devuelve -3
 * Las dos opciones anteriores sirven para crear el cambio de ménus en una barra, pero si sólo se ocupa 
 * un menú será conveniente borrar o poner entre comentarios la parte de código seleccionada más adelante 
 * ELABORÓ: Adrián Josué Ramírez Díaz
 */
    int key;
    int selected=1;
    while (1){
        key=getch();
        if (key==KEY_DOWN || key==KEY_UP) 
        {
        	if(selected != 0)
        	{
            	wbkgd(items[selected+1],COLOR_PAIR(3));//color de texto
            	wnoutrefresh(items[selected+1]);
			}
            if (key==KEY_DOWN)
            {
                selected=(selected+1) % count;//modulo count es para que incremente en 1 y no se pase 
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
        	//PARTE SOLO PARA BARRAS
        	//**********************
        	if(key==KEY_LEFT)
        		return -2;
        	if(key==KEY_RIGHT)
        		return -3;
        	//**********************
        	if (key==ESCAPE)
            	return -1;
        	else
        		if (key==ENTER)
            		return selected;
         }
            		
	}
    
}

void Opciones(int *menu, int *opc)
/* Esta función dibuja los menús de una barra, recibe como argumentos dos apuntadores a int, el primero será el numero de 
 * menú selecionado comenzando desde 0 y el segundo la opcion de dicho menú comenzando desde 1.
 * Para el uso de esta función es necesario adaptarla a las necesidades del programa
 * Las modificaciones necesarias se indican a continuación.
 * ELABORÓ: Adrián Josué Ramírez Díaz 
 */
{
	//******************************************************************************************************************
	//Número máximo de menús que se desea que se impriman
	int max_men = 4;
	//Número de oopciones que se quiere que se impriman por menú
	int ele[8] = {10,10,10,10,10,10,10,10};
	//Arreglo que contiene las opciones que se muestran en cada menú
	//solo tiene que cambiar las opciones que va a ocupar, no es necesario que modifique todas
	char menus[8][10][18]={{"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",},
						   {"Opc 1","Opc 2","Opc 3","Opc 4","Opc 5","Opc 6","Opc 7","Opc 8","Opc 9","Opc 10",}};
	
	//Esta variable es el menú inicial que se imprimirá si desea que se inicie en un menú especifico puede borrar esta
	//inicialización y que la variable menú contenga ya el munú inial que se imprimirá
	*menu = 0;
	//******************************************************************************************************************
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
	    		(*menu) = (*menu)--;
	    else
	    	if(*opc == -3)
	    		if (*menu == max_men - 1)
	    			(*menu) = 0;
	    		else
	    			(*menu) = (*menu)++;
	    	else
	    		alto = 1;

	}
}

void Maximiza()
/*Funcion que imprime un mensaje en la pantalla hasta que el usiario maximize su pantalla
 * ELABORÓ: Adrián Josué Ramírez Díaz 
 */
{
   	int ren,col;
   	do{
		getmaxyx(stdscr, ren, col);
		if (ren < 20 || col < 160)
			printw("\nMaximize la pantalla para que pueda trabajar");
			getch();
	}while (ren < 20 || col < 160);
	clear();
}
