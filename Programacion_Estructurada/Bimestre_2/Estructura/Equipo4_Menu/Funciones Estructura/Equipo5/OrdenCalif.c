/*UNSIS_li
 Nombre:OrdenCalif.c
 Descripción: Este procedimiento ordena el arreglo l en otro auxiliar  empezando por el de mayor calificación 
 al de menor calificación.
 Autor:Equipo5
 Fecha: 06-05-2011
 */
 
 void OrdenCalif (Alumno l[ML], int t, Alumno auxi[ML]) /*falta declarar auxi en la función principal
                                                     *auxi se imprime aparte*/
 {
      int i,j,cont=0,k=0,b,x;
      Alumno temp[t];
      WINDOW *w2;
	  w2 = newwin(15,40,3,15);
	  clear();
	  attron(A_BOLD);
	  Centrar("DATOS DE ALUMNOS",2);
	  if (!t)
		mvprintw(5,5,"NO HAY DATOS LEIDOS");
   	  else
   	  {
		  attroff(A_BOLD);
		  for(i=0;i<t;i++)
          {  
		    strcpy(temp[i].mat,l[i].mat);
		    for(j=0;j<CAL;j++)
				temp[i].calif[j]=l[i].calif[j];
		  }
          while (cont<t)
          {
               for(i=0;i<t;i++)
               {
                   for(j=0;j<t;j++)
                   {
                        if (temp[i].calif[4]< temp[j].calif[4])
                        {
                           j=t;
                           x=0;
                        }
                        else {
                             x=1;}
                   }
                   if (x==1)
                   {
                     for(k=0;i<t;i++)
              	     {  
						strcpy(auxi[k].mat,temp[i].mat);
						for(b=0;b<CAL;b++)
							auxi[k].calif[b]=temp[k].calif[b];
		             } 
                     temp[i].calif[4]=0;
                     cont++;
                     i=t;
                    }
                }
           }
         
      }
      delwin(w2);
 }

                        
