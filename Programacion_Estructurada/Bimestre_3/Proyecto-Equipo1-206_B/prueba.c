/*
Nombre: prueba.c
* Descripcion: Esta es la función principal y tiene la finalidad de llamar a las demás funciones que se definen
* en struct.c y validanc.c.
Autor: Equipo 1

*/
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "validanc.h"
#include "formato.h"
#include "estruct.h"


int main ()
{
	
	Empresa catemp[ML];
	int totalemp=0;
	Alumno catalumn[ML];
	int totalalumn = 0, opcion, usuario, permiso;
	Profesor catprofe[ML];
	int totalprofe = 0;
	Visita visitas[ML];
	int totalvisita = 0;
	char contra[] = "cevesp", contra2[MAX] ;
	initscr();
	keypad(stdscr, TRUE);
	LeerArchivoEmp(catemp, &totalemp);
	LeerArchivoAlumn(catalumn, &totalalumn);
	LeerArchivoProfe(catprofe, &totalprofe);
	do
	{
		clear();
		usuario = Menu();
		if(usuario >=1 && usuario <=2)
		{
			switch (usuario)
				{
					case 1:
							do
							{
									clear();
									mvprintw(5,50,"Escribe la contraseña : ");
									mvprintw(14,25,"Pulse enter para salir");
									LeerContra(contra2, 5, 75);
								
									if(contra2[0] != '\0')
									{
										permiso = strcmp(contra,contra2);
										if (permiso == 0)
										{
											do
											{
												clear();
												Centrar("Abriendo el archivo...",2);
												mvprintw(4,2,"\n\t\tFIN del archivo...");
												opcion = MenuP ();
												if(opcion>=1 && opcion <=6)
												{
													switch (opcion)
													{
														case 1: clear();
																Empresas(catemp, &totalemp, usuario);
															break;
					
														case 2:  clear();
															Alumnos(catalumn, &totalalumn, usuario);
															break;
			
														case 3: clear();
																Profesores (catprofe, &totalprofe, usuario);
															break;
				
														case 4: clear();
																//Visitas(catemp, totalemp, catprofe, totalprofe, visitas, &totalvisita, usuario);
															break;
					
														case 5: Estancias();
															break;
					
														case 6: Servicios();
															break;
													}
											
												}
												if(opcion < 1 || opcion > 7 )
												{
													Error("\tError, opción inválida",22);
												}				
											}while(opcion != 7);
										}	
										else 
											Error("\tLa contraseña es incorrecta",22);
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar("S A L I E N D O . . .",22);
										getch();
									}
								
							}while(permiso != 0 && contra2[0] != '\0');
							break;
					case 2:  
							do
							{
								clear();
								Centrar("Abriendo el archivo...",2);
								mvprintw(4,2,"\n\t\tFIN del archivo...");
								opcion = MenuP ();
								if(opcion>=1 && opcion <=6)
								{
									switch (opcion)
									{
										case 1: clear();
												Empresas(catemp, &totalemp, usuario);
											break;
				
										case 2:  clear();
												Alumnos(catalumn, &totalalumn, usuario);
											break;
		
										case 3: clear();
												Profesores (catprofe, &totalprofe, usuario);
											break;
			
										case 4: clear();
												Visitas(catemp, totalemp, catprofe, totalprofe, visitas, &totalvisita, usuario);
											break;
				
										case 5: Estancias();
												break;
			
										case 6: Servicios();
												break;
									}
										
								}
								if(opcion < 1 || opcion > 7 )
								{
									Error("\tError, opción inválida",22);
								}				
							}while(opcion != 7);
						break;
				}
			
		}
		if(usuario < 1 || usuario > 3 )
		{
			Error("\tError, opción inválida",22);
		}				
	}while(usuario != 3);
	//GuardarEmpText(catemp,totalemp);
	GuardarAlumText(catalumn,totalalumn);
	GuardarProfeText(catprofe,totalprofe);	
	endwin();

	return 0;
} 
