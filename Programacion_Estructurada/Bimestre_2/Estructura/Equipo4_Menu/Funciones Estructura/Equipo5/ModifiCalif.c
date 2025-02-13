/*UNSIS_li
 Nombre:ModifiCali.c
 Descripción: Este procedimiento modifica las calificaciones de un alumno,
 el programa,pide la matricula del alumno a quien se le quieren modificar sus calificaciones,
 luego el usuario tendra que dar el parcial al cual quiere modificar la calificación o sino 
 el ordinario.
 Autor:Equipo5
 Fecha: 06-05-2011
 */
 
 
 void ModifiCalif(Alumnol[ML],int t,char aux[MAT])
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
          ind=Buscar(aux);
          while(salir==0)
          {
                mvprintw(12,2,"Que calificación quieres modificar,escribe el numero del parcial u ordinario P1(1),P2(2),P3(3),oridnario(4)");
                mvscanw(14,2,"%d",&par);
                switch (par)
                {
                      case 1:l[ind].calif[0]=' ';
                             l[ind].calif[0]=LeeFloatR(16,2,0.0,10.0);
                             for (i=0;i<3;i++)
                                 prom=prom+l[ind].calif[i];
                             prom=prom/3;
                             prom=(prom + l[ind].calif[3])/2;
                             l[ind].calif[4]=prom;
                             prom=0;
                             break;
                      case 2:l[ind].calif[1]=' ';
                             l[ind].calif[1]=LeeFloatR(16,2,0.0,10.0);
                             for (i=0;i<3;i++)
                                 prom=prom+l[ind].calif[i];
                             prom=prom/3;
                             prom=(prom + l[ind].calif[3])/2;
                             l[ind].calif[4]=prom;
                             prom=0;
                             break;
                      case 3:l[ind].calif[2]=' ';
                             l[ind].calif[2]=LeeFloatR(16,2,0.0,10.0);
                             for (i=0;i<3;i++)
                                 prom=prom+l[ind].calif[i];
                             prom=prom/3;
                             prom=(prom + l[ind].calif[3])/2;
                             l[ind].calif[4]=prom;
                             prom=0;
                             break;
                      case 4:l[ind].calif[3]=' ';
                             l[ind].calif[3]=LeeFloatR(16,2,0.0,10.0);
                             for (i=0;i<3;i++)
                                 prom=prom+l[ind].calif[i];
                             prom=prom/3;
                             prom=(prom + l[ind].calif[3])/2;
                             l[ind].calif[4]=prom;
                             prom=0;
                             break;
                }
                mvprintw(18,2,"Si deseas modificar otra calificación escribe 0 y sino escribe 1");
                mvscanw(19,2,"%d",&salir);
          }           
      }
      delwin(w2);
 }
                          
                  
 
 
