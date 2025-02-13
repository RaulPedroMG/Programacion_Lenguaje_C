/* Nombre: estruct.c
  Descripción: Contiene la definición de las funciones para la manipulación de la estructura Alumno.
  Autor: 
  Fecha: 
*/

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "estruct.h"
#include "validanc.h"
#include "formato.h"

void SeparaCad(Empresa *catemp,int *cont,char *cad)
{
	int campo,i,j;
	char subc[200];
	for (campo=0,i=0, j=0; i < strlen(cad);i++)
	{
		if (cad[i] != '\t' && cad[i] != '\n')
			subc[j++]= cad[i];
		else
		{
			subc[j] = '\0';
			j = 0;
			campo++;
			switch (campo)
			{
				case 1 : strcpy(catemp[*cont].clave,subc);
						break;
				case 2 : catemp[*cont].nom = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].nom,subc);
						break;
				case 3 : catemp[*cont].giro = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].giro,subc);
						break;
				case 4 : catemp[*cont].dom = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].dom,subc);
						break;
				case 5 : catemp[*cont].edo = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].edo,subc);
						break;
				case 6 : catemp[*cont].cp = atoi(subc);
						break;
				case 7 : catemp[*cont].tel = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].tel,subc);
						break;
				case 8 : catemp[*cont].fax = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].fax,subc);
						break;
				case 9 : catemp[*cont].cont = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].cont,subc);
						break;
				case 10 :catemp[*cont].correo = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].correo,subc);	
			}
		}
		
	}
	(*cont)++;
}


int MenuP ()
{
	int opc;
	WINDOW *w2;
	initscr();
	keypad(stdscr, TRUE);
	Centrar("C E V E S P",6);
	mvprintw(8,2,"\t\t1 : E M P E R S A S ");
	mvprintw(9,2,"\t\t2 : A L U M N O S");
	mvprintw(10,2,"\t\t3 : P R O F E S O R E S");
	mvprintw(11,2,"\t\t4 : V I S I T A S ");
	mvprintw(12,2,"\t\t5 : E S T A N C I A S");
	mvprintw(13,2,"\t\t6 : S E R V I C I O S   S O C I A L E S");
	Derecha("7 : S A L I R",14);
	mvprintw(16,2," \tIntroduzca el número de opción : ");
	echo();
	scanw("%d",&opc);
	delwin(w2);
	return opc;
}

int Menu1 ()
{
	int opc;
	WINDOW *w2;
	initscr();
	keypad(stdscr, TRUE);
	mvprintw(4,2,"\t\t1 : Consulta ");
	mvprintw(5,2,"\t\t2 : Registro");
	mvprintw(6,2,"\t\t3 : Eliminar");
	mvprintw(7,2,"\t\t4 : Modificar ");
	Derecha("5 : REGRESAR",8);
	mvprintw(10,2," \tIntroduzca el número de opción : ");
	echo();
	scanw("%d",&opc);
	delwin(w2);
	return opc;
}

int Menu2 ()
{
	int opc;
	WINDOW *w2;
	initscr();
	keypad(stdscr, TRUE);
	mvprintw(4,2,"\t\t1 : Imprimir ");
	mvprintw(5,2,"\t\t2 : Registro");
	mvprintw(6,2,"\t\t3 : Eliminar");
	mvprintw(7,2,"\t\t4 : Modificar ");
	Derecha("5 : REGRESAR",8);
	mvprintw(10,2," \tIntroduzca el número de opción : ");
	echo();
	scanw("%d",&opc);
	delwin(w2);
	return opc;
}

void Empresas (Empresa *catemp,int cont)
{
	int opcion;
	do
	{
		initscr();
		keypad(stdscr, TRUE);
		noecho();
		clear();
		Centrar("E M P R E S A S",2);
		opcion = Menu1 ();
		if(opcion>=1 && opcion <=6)
		{
			switch (opcion)
			{
				case 1: clear();
						CosultarEmp(catemp, cont);
					break;
				
				case 2:
					break;
		
				case 3:
					break;
		
				case 4:
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tError, opción inválida",17);
		}				
	}while(opcion != 5);
	endwin();
	//return 0;
} 

void CosultarEmp(Empresa *catemp,int cont)
{
	clear();
	Centrar("C O N S U L T A R   E M P R E S A ",2);
	ListaEmp(catemp, cont);
}

void ListaEmp(Empresa *catemp,int cont)
{
	int i, r = 6, c = 4;
	Centrar("\n\t\tEmpresas en el catalogo\n",4);
	mvprintw(r, c,"Numero");
	mvprintw(r, c+10,"Nombre");
	mvprintw(r, c+30,"Clave");
	for (i=0; i < cont; i++)
	{
		mvprintw(r+i+1, c,"%d",i+1);
		mvprintw(r+i+1, c+20,"\t%5s",catemp[i].nom);
		mvprintw(r+i+1, c+40,"\n%5s",catemp[i].clave);
		
	}	
}

void Alumnos ()
{
	int opcion;
	do
	{
		initscr();
		keypad(stdscr, TRUE);
		noecho();
		clear();
		Centrar("A L U M N O S",2);
		opcion = Menu1 ();
		if(opcion>=1 && opcion <=6)
		{
			switch (opcion)
			{
				case 1: clear();
						
					break;
				
				case 2:
					break;
		
				case 3:
					break;
		
				case 4:
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tError, opción inválida",17);
		}				
	}while(opcion != 5);
	endwin();
	//return 0;
} 

void Profesores ()
{
	int opcion;
	do
	{
		initscr();
		keypad(stdscr, TRUE);
		noecho();
		clear();
		Centrar("P R O F E S O R E S",2);
		opcion = Menu1 ();
		if(opcion>=1 && opcion <=6)
		{
			switch (opcion)
			{
				case 1: clear();
						
					break;
				
				case 2:
					break;
		
				case 3:
					break;
		
				case 4:
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tError, opción inválida",17);
		}				
	}while(opcion != 5);
	endwin();
	//return 0;
} 

void Visitas ()
{
	int opcion;
	do
	{
		initscr();
		keypad(stdscr, TRUE);
		noecho();
		clear();
		Centrar("V I S I T A S",2);
		opcion = Menu2 ();
		if(opcion>=1 && opcion <=6)
		{
			switch (opcion)
			{
				case 1: clear();
						
					break;
				
				case 2:
					break;
		
				case 3:
					break;
		
				case 4:
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tFuera de rango, intente nuevamente!",17);
		}				
	}while(opcion != 5);
	endwin();
} 

void Estancias ()
{
	int opcion;
	do
	{
		initscr();
		keypad(stdscr, TRUE);
		noecho();
		clear();
		Centrar("E S T A N C I A S",2);
		opcion = Menu2 ();
		if(opcion>=1 && opcion <=6)
		{
			switch (opcion)
			{
				case 1: clear();
						
					break;
				
				case 2:
					break;
		
				case 3:
					break;
		
				case 4:
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tFuera de rango, intente nuevamente!",17);
		}				
	}while(opcion != 5);
	endwin();
} 

void Servicios ()
{
	int opcion;
	do
	{
		initscr();
		keypad(stdscr, TRUE);
		noecho();
		clear();
		Centrar("S E R V I C I O S   S O C I A L E S ",2);
		opcion = Menu2 ();
		if(opcion>=1 && opcion <=6)
		{
			switch (opcion)
			{
				case 1: clear();
						
					break;
				
				case 2:
					break;
		
				case 3:
					break;
		
				case 4:
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tFuera de rango, intente nuevamente!",17);
		}				
	}while(opcion != 5);
} 

void LeeDatos(Alumno l[ML], int *t)
/*
 * Función que lee y valida datos del teclado proporcionados por el usuario al arreglo l.
 * Conforme se almacenan los datos en el arreglo se actualiza la variable a donde apunta t.
*/
{
	WINDOW *w2;
	int i,salir=0;
	float prom;
	char aux[MAT];
	w2 = newwin(15,40,3,15);
	while (!salir && *t<ML)
	{
		clear();
		mvprintw(18,57,"Total: %d",*t+1);
		attron(A_BOLD);
		Centrar("LECTURA DE DATOS",2);
		mvprintw(5,2,"MATRICULA:");
		LeeMatricula(aux,5,15);
		if (aux[0] == '\0')
			salir = 1;
		else
		{
			strcpy(l[*t].mat,aux);
			for (prom=0,i= 0; i<3;i++)
			{	
				mvprintw(7+i,2,"PARCIAL %d: ",i+1);
				l[*t].calif[i] = LeeFloatR(7+i,20,0.0,10.0);
				prom+=l[*t].calif[i];
			}
			mvprintw(7+i,2,"ORDINARIO: ",i+1);
			l[*t].calif[i] = LeeFloatR(7+i,20,0.0,10.0);
			l[*t].calif[4] = ((prom/3.)+l[*t].calif[3])/2.;
			(*t)++;
		}
	}
	delwin(w2);
}

void ImpDatos(Alumno l[ML],int t)
/*
 * Función que imprime los t elementos del arreglo l a la pantalla. Si el arreglo está vacío imprime
 * que no hay datos leídos.
*/
{
	int i,c;
	WINDOW *w2;
	w2 = newwin(15,40,3,15);
	clear();
	attron(A_BOLD);
	Centrar("DATOS DE ALUMNOS",2);
	//attroff(A_BOLD);
	if (!t)
		mvprintw(5,5,"NO HAY DATOS LEIDOS");
	else
	{
		//attron(A_BOLD);
		mvprintw(4,1,"NUM");
		mvprintw(4,7,"MATRICULA");
		mvprintw(4,19,"Parcial 1 ");
		mvprintw(4,31,"Parcial 2 ");
		mvprintw(4,43,"Parcial 3 ");
		mvprintw(4,55,"Ordinario ");
		mvprintw(4,69,"Final ");
		attroff(A_BOLD);
		for (i = 0; i < t; i++)
		{
			mvprintw(5+i,1,"%2d.  %11s",i+1,l[i].mat);
			for (c=0; c<CAL;c++)
				mvprintw(5+i,21+12*c,"%4.1f",l[i].calif[c]);
		}
	}
	getch();
	delwin(w2);
}




int Buscar (Alumno l[ML], int *t, char mat[MAT])
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Devolverá el índice donde localizó la 
 * matrícula mat, si no encontró la matrícula devolverá -1.*/

{
	int i, y=-1;
	for (i=0; i<*t && y==-1; i++)
	{
		if (strcmp(mat, l[i].mat)==0)
		{
			y=i;
		}
	}
	return y;
}



void Eliminar(Alumno l[ML],int *t, char mat[MAT])
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Eliminará el registro donde localice la 
 * matrícula mat, pedirá confirmación para eliminarla.
 * Enviará un mensaje si la matrícula no se encontró.*/

{
	int i, j, y;
	char conf;
	
		y = Buscar(l, t, mat);
		if (y == -1)
		{
			printw (" NO SE ENCONTRÓ LA MATRICULA BUSCADA");
		}
		else
		{
			mvprintw(2,2,"¿Esta seguro de que desea eliminar la fila %d  [s/n]", y);
			mvscanw (4,30,"%c",&conf);
			if (conf == 's')
			{
				for(i= y; i < *t-1; i++)
				{
					strcpy(l[i].mat,l[i+1].mat);
					for(j=0; j<CAL; j++)
					{
						l[i].calif[j]=l[i+1].calif[j];
					}
				}
				(*t)=(*t) -1;
			}
		}
}


