#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cola.h"
#include "fpavion.h"

int main()
{
	initscr();
	ingresardatos();
	endwin();
	return 0;
}
