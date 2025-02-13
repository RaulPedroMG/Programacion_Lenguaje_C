/*
UNSIS_LI
Nombre:
Autor:Equipo5
Descripción:Funcion modificar calificación y ordenar calificaciones de los alumnos de mayor a menor.
Fecha:10-may-2011
*/


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
          //ind=Buscar(aux);
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
      int i,j,cont=0,k=0,b,x;
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
