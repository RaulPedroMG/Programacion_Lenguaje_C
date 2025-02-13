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

void Leedatos(Alumno l[ML], int *t)
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

void InsertarOrd(Alumno l[ML],int *t)
{
	int salir=0, ind, band=0,i,j;
	Alumno aux;
	keypad(stdscr, TRUE);
	noecho();
		while(*t<ML && salir==0){
			clear();
			if(*t==0){
				salir=CapturaDatos(&l[*t]);
				if(salir==0){
					(*t)++;
				}
			}else{
				if(*t>0){
					salir=CapturaDatos(&aux);
					if(salir==0){
						if(strcmp(aux.mat,l[(*t)-1].mat)>0){
							ustituir(&l[*t],aux);
							(*t)++;
						}else{
							for(ind=0;ind<*t && band==0;ind++){
								i=strcmp(aux.mat,l[ind].mat);
								if(i==0){
									Error("La matrícula ya existe!",ind+6);
									band=1;
								}else{
									if(i<0){
										for(j=*t;j>ind;j--){
											ustituir(&l[j],l[j-1]);
										}
										ustituir(&l[ind],aux);
										band=1;
										(*t)++;
									}
								}
							}
						}
					}
				}
			}
		}
}
int menu()
{
	int opc;
	//initscr();
	keypad(stdscr, TRUE);
	echo();
	clear();
	attron(A_BOLD);
	mvprintw(5,5,"OPCIONES A REALIZAR");
	mvprintw(6,5,"1.- Ingreso de alumnos");
	mvprintw(7,5,"2.- Imprimir lista");
	mvprintw(8,5,"3.- Buscar alumno");
	mvprintw(9,5,"4.- Eliminar un alumno");
	mvprintw(10,5,"5.- Modificar datos de un alumno");
	mvprintw(11,5,"6.- Ordenar alumnos por calificacion mayor");
	mvprintw(12,5,"7.- salir");
	mvprintw(14,5,"Eliga su opción ");
	mvscanw(16,30,"%d",&opc);
	//endwind();
	return opc;
}


int Buscar (Alumno l[ML], int t, char mat[MAT])
/*Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Devolverá el índice donde localizó la 
 * matrícula mat, si no encontró la matrícula devolverá -1.*/

{
	int i, y=-1;
	for (i=0; i<t && y==-1; i++)
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
	
		y = Buscar(l, *t, mat);
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
void Imprimir(Alumno l[ML], int j)
{
	int i;
	clear();
	//attron(A_BOLD);
		mvprintw(4,1,"NUM");
		mvprintw(4,7,"MATRICULA");
		mvprintw(4,19,"Parcial 1 ");
		mvprintw(4,31,"Parcial 2 ");
		mvprintw(4,43,"Parcial 3 ");
		mvprintw(4,55,"Ordinario ");
		mvprintw(4,69,"Final ");
		attroff(A_BOLD);
	mvprintw(5,2,"%s",l[j].mat);
	for(i=0; i<CAL; i++)
	{
		mvprintw(5,21+12*i,"%4.1f",l[j].calif[i]);
	}
}

void ustituir(Alumno *dest, Alumno origen)
{
	int ind;
	strcpy(dest->mat,origen.mat);
	for(ind=0;ind<CAL;ind++){
		dest->calif[ind]=origen.calif[ind];
	}	
}

int CapturaDatos(Alumno *l)
{
	int j, band=0;
	float prom;
	char aux[MAT];
	clear();
	mvprintw(5,5,"Ingrese la matrícula");
	LeeMatricula(aux,5,30);
	if(aux[0]!='\0'){
		strcpy(l->mat,aux);
		for(j=0,prom=0;j<3;j++){
			mvprintw(7+j,2,"PARCIAL %d: ",j+1);
			l->calif[j]=LeeFloatR(7+j,20,0.0,10.0);
			prom=prom + l->calif[j];
		}
		prom=prom/3;
		mvprintw(7+j,2,"Dame ordinario ");
		l->calif[j]=LeeFloatR(7+j,20,0.0,10.0);
		l->calif[4]=(prom+l->calif[j])/2;
	}else{
		band=1;
	} 
	return band;
}
void ModifiCalif(Alumno l[ML],int t,char aux[MAT])
/*Definicion del procedimiento ModifiCalf que recibe el arreglo l,el total de registros y otro arreglo aux*/
 {
      float prom;
      int ind,par,i,salir=0;
      WINDOW *w2;
	  w2 = newwin(15,40,3,15);
	  clear();
	  attron(A_BOLD);
	  Centrar("DATOS DE ALUMNOS",2);
	  if (!t)
		mvprintw(5,5,"NO HAY DATOS LEIDOS");
      else
      {
					mvprintw(2,1,"intruduce una matrícula");
					LeeMatricula(aux,5,15);
          ind=Buscar(l,t,aux);
          while(salir==0)
          {
                mvprintw(12,2,"Que calificación quieres modificar,escribe el numero del parcial u ordinario P1(1),P2(2),P3(3),oridnario(4)");
                mvscanw(14,2,"%d",&par);
                l[ind].calif[par-1]=LeeFloatR(16,2,0.0,10.0);
                for (i=0;i<3;i++)
                  prom=prom+l[ind].calif[i];
                prom=prom/3;
                prom=(prom + l[ind].calif[3])/2;
                l[ind].calif[4]=prom;
                prom=0;           
                mvprintw(18,2,"Si deseas modificar otra calificación escribe 0 y sino escribe 1");
                mvscanw(19,2,"%d",&salir);
          }           
      }
      delwin(w2);
 }
 void OrdenCalif(Alumno l[ML],int t,Alumno auxi[ML])/*falta declarar auxi en la función principal
                                                     *auxi se imprime aparte*/
/*Esta función ordena las calificaciones del los alumnos de mayor a menor*/

 {
      int i,j,cont=0,k=0,x;
      Alumno temp[t];
      WINDOW *w2;
	  w2 = newwin(15,40,3,15);
	  clear();
	  Centrar("DATOS DE ALUMNOS",2);
	  if (!t)
		mvprintw(5,5,"NO HAY DATOS LEIDOS");
   	  else
   	  {
		 CopiarAr(temp,t,l);									
         while (cont<t)
          {
               for(i=0;i<t;i++)
               {
                   for(j=0;j<t;j++)
                   {
                        if (temp[i].calif[4] < temp[j].calif[4])
                        {
                           j=t;
                           x=0;
                        }
                        else {
                             x=1;}
                   }
                   if (x==1)
                   {
					Sustituir(auxi[k],l[i]);									
		             k++;
                     temp[i].calif[4]=0;
                     cont++;
                     i=t;
                    }
                }
           }
         
      }
      delwin(w2);
 }

void CopiarAr(Alumno ldest[ML],int t,Alumno lorig[ML])
/*Este procedimiento copia los t elementos de un arreglo origen a un destino*/
{
	int ind,cal;
	for (ind=0;ind<t;ind++)
	{
		strcpy(ldest[ind].mat,lorig[ind].mat);
		for(cal=0;cal<CAL;cal++)
			ldest[ind].calif[cal]=lorig[ind].calif[cal];
	}
}

void Sustituir(Alumno dest,Alumno origen)
/*Se va a sustituir la estructura dest por el contenido de la estructura origen*/
{
	int ind;
	strcpy(dest.mat,origen.mat);
	for (ind=0;ind<CAL;ind++)
		dest.calif[ind]=origen.calif[ind];
}


/*validacion de una contraseña*/
void LeeContra(char *cad,int max,int r, int c)
 {
    int aux,x;
	int ind, band,a=0,b=0,z=0;
	noecho();
	keypad(stdscr, TRUE);
	ind = band =0;
	while (!band && ind < max -1)
	{
		do
		{
			move(r,c+ind);
			aux = getch();
		}while (aux != RET && aux != ENT && !isalpha(aux) && !isdigit(aux) && aux != '.' 
        && aux != '@' && aux != '_' && aux != '-' && aux != '#' && aux != '/');
		switch(aux)
		{
			case ENT: band = 1;
                      cad[ind] = '\0';
			          break;
			case RET: if (ind > 0)
			          {
			            ind--;
			            move(r,c+ind);
			            printw(" ");
			            move(r,c+ind);
	                  }
			          break;
			default : cad[ind] = aux;
		              move(r,c+ind);
			          printw("*");
			          ind++;
		}
	}
	
	for (ind=0;ind<max;ind++)
	{
		if (isalpha(cad[ind]))
			a++;
		if (isdigit(cad[ind]))
			b++;
		if (cad[ind]=='.' || cad[ind]=='@' || cad[ind]=='-' || cad[ind]=='_' || cad[ind]=='/' || cad[ind]=='#')
			z++;	
	}
	if (z>0 && a>0 && b>0)
	{
		x=1;
		mvprintw(r+1,c,"Contraseña valida");
	}
	else 
	   mvprintw(r+1,c,"Contraseña invalida");
	
}
