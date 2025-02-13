void ImprimirVector(Alumno l[ML],int cont[ML], int j);
{
	int i,c,p;
	WINDOW *w2;
	w2 = newwin(15,40,3,15);
	clear();
	attron(A_BOLD);
	Centrar("DATOS DE ALUMNOS",2);
	attroff(A_BOLD);
	attron(A_BOLD);
	mvprintw(4,1,"NUM");
	mvprintw(4,7,"MATRICULA");
	mvprintw(4,19,"Parcial 1 ");
	mvprintw(4,31,"Parcial 2 ");
	mvprintw(4,43,"Parcial 3 ");
	mvprintw(4,55,"Ordinario ");
	mvprintw(4,69,"Final ");
	attroff(A_BOLD);
	for (i = 0; i < j; i++)
	{
		p=cont[i];
		mvprintw(5+i,1,"%2d.  %11s",i+1,l[p].mat);
		for (c=0; c<CAL;c++)
		{	
			mvprintw(5+i,21+12*c,"%4.1f",l[p].calif[c]);
		}
	}

getch();
delwin(w2);
}
