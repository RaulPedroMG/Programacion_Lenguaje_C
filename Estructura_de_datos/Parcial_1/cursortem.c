#include <ncurses.h>
int main()
{
	initscr();
	printw("Hello World !!!\n");
	refresh();
	def_prog_mode();
	endwin();
	system("/bin/sh");
	reset_prog_mode();
	refresh();
	printw("Another String\n");
	refresh();
	endwin();

	/*Start curses mode

	Print Hello World

	Print it on to the real screen 
	Save the tty modes

	End curses mode temporarily

	Do whatever you like in cooked mode 
	Return to the previous tty mode
	stored by def_prog_mode()

Do refresh() to restore the

Screen contents

Back to curses use the full

capabilities of curses

End curses mode
*/
	return 0;
}
