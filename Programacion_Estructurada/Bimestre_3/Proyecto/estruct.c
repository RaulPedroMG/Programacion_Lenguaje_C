/* Nombre: estruct.c
  Descripción: Contiene la definición de las funciones para la manipulación de la estructura Empresas, 
  * Alumnos, Profesores, Visitas, Estancias y Servicios Sociales.
  Autor: Equipo 1
*/

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <ctype.h>
#include "estruct.h"
#include "validanc.h"
#include "formato.h"

int Menu ()
{
	int opc = 0;
	Centrar("C E V E S P",6);
	mvprintw(9,2,"\t\t D E S E A : ");
	mvprintw(12,2,"\t\t1 : Entrar como Administrador ?");
	mvprintw(14,2,"\t\t2 : Entrar como usuario ?");
	mvprintw(17,2,"\t\t3 : S A L I R");
	mvprintw(19,2," \tIntroduzca el número de opción : ");
	echo();
	scanw("%d",&opc);
	return opc;
}

void LeerArchivoEmp(Empresa *catemp,int *cont)
{
	FILE *arch;
	char cad[450];
	 if ((arch = fopen("./empresas3.txt", "r"))	 == NULL)
	 {
			fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
	 }
	else
	{
		while (!feof(arch))
		{
			if (fgets(cad,449,arch) != NULL)
			{
				SeparaCad(catemp,cont,cad);
			}
		}
	}
	fclose(arch);
}


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
				case 2 : catemp[*cont].nombremp = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].nombremp,subc);
						break;
				case 3 : catemp[*cont].giro = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].giro,subc);
						break;
				case 4 : catemp[*cont].domicilio = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].domicilio,subc);
						break;
				case 5 : catemp[*cont].estado = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].estado,subc);
						break;
				case 6 : catemp[*cont].cp = atoi(subc);
						break;
				case 7 : catemp[*cont].telefono = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].telefono,subc);
						break;
				case 8 : catemp[*cont].fax = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].fax,subc);
						break;
				case 9 : catemp[*cont].nomcont = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].nomcont,subc);
						break;
				case 10 :catemp[*cont].correo = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].correo,subc);	
						
				case 11 :catemp[*cont].visita = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].visita,subc);	
			
				case 12 :catemp[*cont].estancia = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].estancia,subc);	
		
				case 13 :catemp[*cont].servicios = (char *) malloc(strlen(subc));
						strcpy(catemp[*cont].servicios,subc);	
				
			}
		}
		
	}
	(*cont)++;
}

void LeerArchivoAlumn(Alumno *catalumn,int *cont)
{
	FILE *arch;
	char cad[450];
	initscr();
	keypad(stdscr, TRUE);
	 if ((arch = fopen("./alumnos.txt", "r"))	 == NULL)
	 {
			fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
	 }
	else
	{
		while (!feof(arch))
		{
			if (fgets(cad,449,arch) != NULL)
			{
				SeparaCadAlumn(catalumn,cont,cad);
				
			}
		}
	}
	fclose(arch);
}

void SeparaCadAlumn(Alumno *catalumn,int *cont,char *cad)
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
				case 1 : strcpy(catalumn[*cont].mat,subc);
						break;
				case 2 : catalumn[*cont].nomalum = (char *) malloc(strlen(subc));
						strcpy(catalumn[*cont].nomalum,subc);
						break;
				case 3 : catalumn[*cont].apealum = (char *) malloc(strlen(subc));
						strcpy(catalumn[*cont].apealum,subc);
						break;				
			}
		}
		
	}
	(*cont)++;

}

void GuardarAlumText(Alumno *catalumn,int cont)
{
	int i;
	FILE *arch;
	printf("\nAbriendo el archivo...\n");
	if ((arch = fopen("./alumnos.txt", "w"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return;
	}

	printf("\nGuardando Alumnos del catalogo\n");
	for (i=0; i < cont; i++)
		fprintf(arch,"%s\t%s\t%s\n",catalumn[i].mat,catalumn[i].nomalum,catalumn[i].apealum);
	fclose(arch);
}

void LeerArchivoProfe(Profesor *catprofe, int *cont)
{
	FILE *arch;
	char cad[450];
	initscr();
	keypad(stdscr, TRUE);
	 if ((arch = fopen("./profesores.txt", "r"))	 == NULL)
	 {
			fprintf(stderr,"\t\tNo se puede abrir el archivo de salida.\n");
	 }
	else
	{
		while (!feof(arch))
		{
			if (fgets(cad,449,arch) != NULL)
			{
				SeparaCadProfe(catprofe, cont, cad);
				
			}
		}
	}
	fclose(arch);
}

void SeparaCadProfe(Profesor *catprofe, int *cont, char *cad)
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
				case 1 : strcpy(catprofe[*cont].clav,subc);
						break;
				case 2 : catprofe[*cont].nomprofe = (char *) malloc(strlen(subc));
						strcpy(catprofe[*cont].nomprofe, subc);
						break;
				case 3 : catprofe[*cont].apeprofe = (char *) malloc(strlen(subc));
						strcpy(catprofe[*cont].apeprofe,subc);
						break;				
			}
		}
		
	}
	(*cont)++;
}

void GuardarProfeText(Profesor *catprofe,int cont)
{
	int i;
	FILE *arch;
	printf("\nAbriendo el archivo...\n");
	if ((arch = fopen("./profesores.txt", "w"))	 == NULL)
	{
		fprintf(stderr, "No se puede abrir el archivo de salida.\n");
		return;
	}

	printf("\nGuardando Profesores del catalogo\n");
	for (i=0; i < cont; i++)
		fprintf(arch,"%s\t%s\t%s\n",catprofe[i].clav,catprofe[i].nomprofe,catprofe[i].apeprofe);
	fclose(arch);
}


int MenuP ()
{
	int opc = 0;
	Centrar("C E V E S P",6);
	mvprintw(9,2,"\t\t1 : E M P R E S A S ");
	mvprintw(10,2,"\t\t2 : A L U M N O S");
	mvprintw(11,2,"\t\t3 : P R O F E S O R E S");
	mvprintw(12,2,"\t\t4 : V I S I T A S ");
	mvprintw(13,2,"\t\t5 : E S T A N C I A   P R O F E S I O N A L");
	mvprintw(14,2,"\t\t6 : S E R V I C I O   S O C I A L");
	mvprintw(15,2,"\t\t7 : S A L I R");
	mvprintw(18,2," \tIntroduzca el número de opción : ");
	echo();
	scanw("%d",&opc);;
	return opc;
}

int Menu1 (char *cad)
{
	int opc;
	Centrar(cad,2);
	opc = 0;
	mvprintw(4,2,"\t\t1 : Registrar ");
	mvprintw(5,2,"\t\t2 : Eliminar ");
	mvprintw(6,2,"\t\t3 : Modificar ");
	mvprintw(7,2,"\t\t4 : Consultar ");
	mvprintw(8,2,"\t\t5 : REGRESAR");
	mvprintw(10,2," \tIntroduzca el número de opción : ");
	echo();
	scanw("%d",&opc);
	return opc;
}

int Menu2 ()
{
	int opc = 0;
	mvprintw(4,2,"CONSULTA POR:");
	mvprintw(6,2,"\t\t1 : Clave de Empresa");
	mvprintw(7,2,"\t\t2 : Año de visita");
	mvprintw(8,2,"\t\t3 : Nombre del profesor");
	mvprintw(9,2,"\t\t4 : Calificación");
	//mvprintw(6,2,"\t\t3 : ");
	//mvprintw(7,2,"\t\t4 : Modificar ");
	mvprintw(10,2,"t\t5 : REGRESAR");
	mvprintw(12,2," \tIntroduzca el número de opción : ");
	echo();
	scanw("%d",&opc);
	return opc;
}

//###########################################################################################################################
void Empresas (Empresa *catemp,int *cont, int usuario)
{
	int opcion;
	do
	{
		clear();
		opcion = Menu1 ("E M P R E S A S");
		if(opcion>=1 && opcion <=4)
		{
			switch (opcion)
			{
				case 1: if(usuario != 2)
							RegistrarEmp(catemp, cont);
						else
							Error("\tPermiso Denegado !",12);
					break;
				
				case 2: if(usuario != 2)
							EliminarEmp(catemp, cont);
						else
							Error("\tPermiso Denegado!",12);
					
					break;
		
				case 3:	if(usuario != 2)
							ModificarEmp(catemp, *cont);
						else
							Error("\tPermiso Denegado!",12);
						
					break;
		
				case 4: 
						CosultarEmp(catemp, *cont);
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tError, opción inválida!",12);
		}				
	}while(opcion != 5);
} 

//**********************************************************************
void RegistrarEmp(Empresa *catemp,int *t)
{
	char cad[MAX], clave[MIN - 1];
	int opc, lon;
	do
	{
		clear();
		Centrar("I N S E R T A R    E M P R E S A ",2);
		mvprintw(4, 100, " Rellene los datos ");
		mvprintw(7, 2, " Nombre : ");
		mvprintw(24,100," Pulse enter para cancelar la captura");
		LeerNomEmp(cad, 7, 14);
		if (cad[0] != '\0')
		{
			lon =  strlen(cad);
			catemp[*t].nombremp = (char *) malloc(strlen(cad));
			strcpy(catemp[*t].nombremp, cad);
			GenerarClave(cad, clave, lon);
			strcpy(catemp[*t].clave, clave);
			mvprintw(9, 2, " Giro : ");
			mvprintw(24,100," Pulse enter para cancelar la captura");
			LeerGiroEmp(cad, 9, 13);
			if(cad[0] != '\0')
			{
				catemp[*t].giro = (char *) malloc(strlen(cad));
				strcpy(catemp[*t].giro, cad);
				mvprintw(11, 2, " Domicilio : ");
				mvprintw(24,100," Pulse enter para cancelar la captura");
				LeerDomEmp(cad, 11, 15);
				if(cad[0] != '\0')
				{
					catemp[*t].domicilio = (char *) malloc(strlen(cad));
					strcpy(catemp[*t].domicilio, cad);
					mvprintw(13, 2, " Estado : ");
					mvprintw(24,100," Pulse enter para cancelar la captura");
					LeerEstEmp(cad, 13, 14);
					if(cad[0] != '\0')
					{
						catemp[*t].estado = (char *) malloc(strlen(cad));
						strcpy(catemp[*t].estado, cad);
						mvprintw(15, 2, " CP : ");
						mvprintw(24,100," Pulse enter para cancelar la captura");
						LeerCpEmp(cad, 15, 9);
						if (cad[0] != '\0')
						{
							catemp[*t].cp = atoi(cad);
							mvprintw(6, 100, " Telefono : ");
							mvprintw(24,100," Pulse enter para cancelar la captura");
							LeerTelEmp(cad, 6, 114);
							if(cad[0] != '\0')
							{
								catemp[*t].telefono = (char *) malloc(strlen(cad));
								strcpy(catemp[*t].telefono, cad);
								mvprintw(8, 100, " Fax : ");
								mvprintw(24,100," Pulse enter para cancelar la captura");
								LeerFaxEmp(cad, 8, 108);
								if(cad[0] != '\0')
								{
									catemp[*t].fax = (char *) malloc(strlen(cad));
									strcpy(catemp[*t].fax, cad);
									mvprintw(10, 100, " Nombre del contacto : ");
									mvprintw(24,100," Pulse enter para cancelar la captura");
									LeerContEmp(cad, 10, 124);
									if (cad[0] != '\0')
									{
										catemp[*t].nomcont = (char *) malloc(strlen(cad));
										strcpy(catemp[*t].nomcont, cad);
										mvprintw(12, 100, " Correo : ");
										mvprintw(24,100," Pulse enter para cancelar la captura");
										LeerCorreoEmp(cad, 12, 111);
										if(cad[0] != 0)
										{
											catemp[*t].correo = (char *) malloc(strlen(cad));
											strcpy(catemp[*t].correo, cad);
											do
											{
												clear(); 
												opc = 0; 
												Centrar(" I N S E R T A R   E M P R E S A ",2);
												Centrar(" ¿La empresa recibe visitas? ",4);
												mvprintw(8,90," 1 : Si" );
												mvprintw(8,120," 2 : No" );
												mvprintw(9,150," 3 : Cancelar");
												mvprintw(10,70," Introduzca el número de opción : ");
												echo();
												scanw("%d",&opc);
												LeerVisitaEmp(cad,opc);
												if (opc >= 1 && opc <= 2)
												{
													catemp[*t].visita = (char *) malloc(strlen(cad));
													strcpy(catemp[*t].visita, cad);
													do
													{
														clear();
														opc = 0; 
														Centrar(" I N S E R T A R   E M P R E S A ",2);
														Centrar(" ¿La empresa permite estancias? ",4);
														mvprintw(8,90," 1 : Si" );
														mvprintw(8,120," 2 : No" );
														mvprintw(9,150," 3 : Cancelar" );
														mvprintw(10,70," Introduzca el número de opción : ");
														echo();
														scanw("%d",&opc);
														LeerEstanciaEmp(cad,opc);
														if (opc >= 1 && opc <= 2)
														{
															catemp[*t].estancia = (char *) malloc(strlen(cad));
															strcpy(catemp[*t].estancia, cad);
															do
															{
																clear(); 
																opc = 0;
																Centrar(" I N S E R T A R   E M P R E S A ",2);
																Centrar(" ¿La empresa permite servicios sociales? ",4);
																mvprintw(8,90," 1 : Si" );
																mvprintw(8,120," 2 : No" );
																mvprintw(9,150," 3 : Cancelar" );
																mvprintw(10,70," Introduzca el número de opción : ");
																echo();
																scanw("%d",&opc);
																LeerServicioEmp(cad,opc);
																if (opc >= 1 && opc <= 2)
																{
																	catemp[*t].servicios = (char *) malloc(strlen(cad));
																	strcpy(catemp[*t].servicios, cad);
																	mvprintw(24,100," Pulse enter para salir");
																	Centrar(" G U A R D A N D O . . .",20);
																	getch();
																	(*t)++;
																}
																else
																{
																	if(opc == 3)
																	{
																		mvprintw(24,100," Pulse enter para salir");
																		Centrar(" C A N C E L A N D O . . .",20);
																		getch();
																	}
																	else
																	{
																		Error(" La opción es incorrecta! Verifícala",20);
																	}
																}
															}while(opc < 1 || opc >3);
														}
														else
														{
															if(opc == 3)
															{
																mvprintw(24,100," Pulse enter para salir");
																Centrar(" C A N C E L A N D O . . .",20);
																getch();
															}
															else
															{
																Error(" La opción es incorrecta! Verifícala",20);
															}
														}
													}while(opc < 1 || opc >3);
												}
												else
												{
													if(opc == 3)
													{
														mvprintw(24,100," Pulse enter para salir");
														Centrar(" C A N C E L A N D O . . .",20);
														getch();
													}
													else
													{
														Error(" La opción es incorrecta! Verifícala",20);
													}
												}
											}while(opc < 1 || opc >3);
										}
											
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}	 
								}
								else
								{
									mvprintw(24,100," Pulse enter para salir");
									Centrar(" C A N C E L A N D O . . .",18);
									getch();
								}	 
							}
							else
							{
								mvprintw(24,100," Pulse enter para salir");
								Centrar(" C A N C E L A N D O . . .",18);
								getch();
							}
						}
						else
						{
							mvprintw(24,100," Pulse enter para salir");
							Centrar(" C A N C E L A N D O . . .",18);
							getch();
						}
						
					}
					else
					{
						mvprintw(24,100," Pulse enter para salir");
						Centrar(" C A N C E L A N D O . . .",18);
						getch();
					}	 
				}
				else
				{
					mvprintw(24,100," Pulse enter para salir");
					Centrar(" C A N C E L A N D O . . .",18);
					getch();
				}	
			}
			else
			{
				mvprintw(24,100," Pulse enter para salir");
				Centrar(" C A N C E L A N D O . . .",18);
				getch();
			}
		}
		else
		{
			mvprintw(24,100," Pulse enter para salir");
			Centrar(" C A N C E L A N D O . . .",18);
			getch();
		}
	}while(cad[0] !='\0' && *t < ML);
}
	

//**********************************************************************
void EliminarEmp(Empresa *catemp,int *t)
{
	char clave[MIN];
	int r = 2, c = 10, ind;
	do
	{
		clear();
		Centrar("E L I M I N A R    E M P R E S A ",2);
		mvprintw(r + 2, c, "Introduzca la clave de la empresa : ");
		LeerClave(clave, r + 2, 46);
		if (clave[0] != '\0')
		{
			ind = BuscarEmp(catemp, *t, clave);
			if (ind != -1)
			{
				clear();
				BorrarEmp(catemp, t, ind);
			}
			else 
			{
				Error("No se encontró la clave! Verifícala ",8);
			}
		}
	}while (clave[0] != '\0');
}

int BuscarEmp(Empresa *catemp, int t, char clave[MIN])
{
	int ind, sal = - 1;
	for (ind = 0; ind < t && sal == - 1; ind++)
	{
		if (strcmp(clave, catemp[ind].clave) == 0)
			sal = ind;
	}
	return sal;
}

void BorrarEmp(Empresa *catemp,int *total, int ind)
{
	int conf, i;
	do
	{
		clear();
		Centrar("¿Esta seguro que desea eliminar la empresa ", 2);
		Centrar(catemp[ind].nombremp, 4);
		printw( "?");
		mvprintw(8,90," 1 : Si" );
		mvprintw(8,120," 2 : No" );
		mvprintw(10,70," \tIntroduzca el número de opción : ");
		echo();
		scanw("%d",&conf);
	
		if (conf >= 1 && conf <= 2)
		{	
			if (conf == 1)
			{
				for(i= ind; i < *total - 1; i++)
				{
					catemp[i]=catemp[i+1];
				}
				Centrar(" E L I M I N A N D O . . . ",20);
				*total=*total -1;
				getch();
			}
			if(conf == 2)
			{
				Centrar(" C A N C E L A N D O . . . ",20);
				getch();
			}
		}
		else
		{
			Error("\tError, opción inválida!",20);
		}
	}while (conf < 1 || conf > 2);
}

//**********************************************************************
void ModificarEmp(Empresa *catemp,int t)
{
	char cad[MAX];
	char clave[MIN];
	int r = 2, c = 10, ind, opcion, opc;
	do
	{
		clear();
		Centrar("M O D I F I C A R    E M P R E S A ",2);
//   	ListaEmp(catemp, t, &r, clave);
		mvprintw(r + 2, c, "Introduzca la clave de la empresa : ");
		LeerClave(clave, r + 2, 46);
		if (clave[0] != '\0')
		{
			ind = BuscarEmp(catemp, t, clave);
			if (ind != -1)
			{
				clear();
				do
				{
					opcion = ImprimirEmpMod (catemp, ind);					
					if (opcion >= 1 && opcion <= 14)
					{
						switch (opcion)
						{
							case 1 : clear(); 
									Centrar(" MODIFICAR NOMBRE DE LA EMPRESA ",2);
									mvprintw(10,4," Escriba el nuevo nombre de la empresa : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerNomEmp(cad, 10, 45);
									if (cad[0] != '\0')
									{
										catemp[ind].nombremp = (char *) malloc(strlen(cad));
										strcpy(catemp[ind].nombremp, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 2 : clear(); 
									Centrar(" MODIFICAR GIRO DE LA EMPRESA ",2);
									mvprintw(10,4," Escriba el nuevo giro de la empresa : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerGiroEmp(cad, 10, 45);
									if (cad[0] != '\0')
									{
										catemp[ind].giro = (char *) malloc(strlen(cad));
										strcpy(catemp[ind].giro, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 3 : clear(); 
									Centrar(" MODIFICAR DOMICILIO DE LA EMPRESA ",2);
									mvprintw(10,4," Escribe el nuevo domicilio de la empresa : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerDomEmp(cad, 10, 48);
									if (cad[0] != '\0')
									{
										catemp[ind].domicilio = (char *) malloc(strlen(cad));
										strcpy(catemp[ind].domicilio, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 4 : clear(); 
									Centrar(" MODIFICAR ESTADO DE LA EMPRESA ",2);
									mvprintw(10,4," Escriba el nuevo estado de la empresa : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerEstEmp(cad, 10, 45);
									if (cad[0] != '\0')
									{
										catemp[ind].estado = (char *) malloc(strlen(cad));
										strcpy(catemp[ind].estado, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 5 : clear(); 
									Centrar(" MODIFICAR CODIGO POSTAL DE LA EMPRESA ",2);
									mvprintw(10,4," Escriba el nuevo código postal de la empresa : ");
									mvprintw(14,25," Pulse enter  para cancelar");
									LeerCpEmp(cad, 10, 52);
									if (cad[0] != '\0')
									{
										catemp[ind].cp = atoi(cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 6 : clear(); 
									Centrar(" MODIFICAR TELEFONO DE LA EMPRESA ",2);
									mvprintw(10,4," Escriba el nuevo telefono de la empresa : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerTelEmp(cad, 10, 47);
									if (cad[0] != '\0')
									{
										catemp[ind].telefono = (char *) malloc(strlen(cad));
										strcpy(catemp[ind].telefono, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
									
							case 7 : clear(); 
									Centrar(" MODIFICAR FAX DE LA EMPRESA ",2);
									mvprintw(10,4," Escriba el nuevo fax de la empresa : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerFaxEmp(cad, 10, 42);
									if (cad[0] != '\0')
									{
										catemp[ind].fax = (char *) malloc(strlen(cad));
										strcpy(catemp[ind].fax, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
								
							case 8 : clear(); 
									Centrar(" MODIFICAR CONTACTO DE LA EMPRESA ",2);
									mvprintw(10,4," Escriba el nuevo contacto de la empresa : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerContEmp(cad, 10 ,47);
									if (cad[0] != '\0')
									{
										catemp[ind].nomcont = (char *) malloc(strlen(cad));
										strcpy(catemp[ind].nomcont, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
								
							case 9 : clear(); 
									Centrar(" MODIFICAR CORREO DE LA EMPRESA ",2);
									mvprintw(10,4," Escriba el nuevo correo de la empresa : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerCorreoEmp(cad, 10, 45);
									if (cad[0] != '\0')
									{
										catemp[ind].correo = (char *) malloc(strlen(cad));
										strcpy(catemp[ind].correo, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 10 : do
										{
											clear(); 
											Centrar(" MODIFICAR VISITA DE LA EMPRESA ",2);
											Centrar(" ¿La empresa recibe visitas? ",4);
											mvprintw(8,90," 1 : Si" );
											mvprintw(8,120," 2 : No" );
											mvprintw(9,150," 3 : Cancelar" );
											mvprintw(10,70," Introduzca el número de opción : ");
											scanw("%d",&opc);
											LeerVisitaEmp(cad,opc);
											if (opc >= 1 && opc <= 2)
											{
												catemp[ind].visita = (char *) malloc(strlen(cad));
												strcpy(catemp[ind].visita, cad);
												mvprintw(24,100," Pulse enter para salir");
												Centrar(" M O D I F I C A N D O . . .",20);
												getch();
											}
											else
											{
												if(opc == 3)
												{
													mvprintw(24,100," Pulse enter para salir");
													Centrar(" C A N C E L A N D O . . .",20);
													getch();
												}
												else
												{
													Error(" La opción es incorrecta! Verifícala",20);
												}
											}
										}while(opc < 1 || opc >3);
								break;
							
							case 11 : do
										{
											clear();
											Centrar(" MODIFICAR ESTANCIA DE LA EMPRESA ",2);
											Centrar(" ¿La empresa permite estancias ? ",4);
											mvprintw(8,90," 1 : Si" );
											mvprintw(8,120," 2 : No" );
											mvprintw(9,150," 3 : Cancelar" );
											mvprintw(10,70," Introduzca el número de opción : ");
											scanw("%d",&opc);
											LeerEstanciaEmp(cad,opc);
											if (opc >= 1 && opc <= 2)
											{
												catemp[ind].estancia = (char *) malloc(strlen(cad));
												strcpy(catemp[ind].estancia, cad);
												mvprintw(24,100," Pulse enter para salir");
												Centrar(" M O D I F I C A N D O . . .",20);
												getch();
											}
											else
											{
												if(opc == 3)
												{
													mvprintw(24,100," Pulse enter para salir");
													Centrar(" C A N C E L A N D O . . .",20);
													getch();
												}
												else
												{
													Error(" La opción es incorrecta! Verifícala",20);
												}
											}
										}while(opc < 1 || opc >3);
								break;
								
							case 12 : do
										{
											clear();
											Centrar(" MODIFICAR SERVICIO SOCIAL DE LA EMPRESA ",2);
											Centrar(" ¿La empresa permite servicios sociales ? ",4);
											mvprintw(8,90," 1 : Si" );
											mvprintw(8,120," 2 : No" );
											mvprintw(9,150," 3 : Cancelar" );
											mvprintw(10,70," Introduzca el número de opción : ");
											scanw("%d",&opc);
											LeerServicioEmp(cad,opc);
											if (opc >= 1 && opc <= 2)
											{
												catemp[ind].servicios = (char *) malloc(strlen(cad));
												strcpy(catemp[ind].servicios, cad);
												mvprintw(24,100," Pulse enter para salir");
												Centrar(" M O D I F I C A N D O . . .",20);
												getch();
											}
											else
											{
												if(opc == 3)
												{
													mvprintw(24,100," Pulse enter para salir");
													Centrar(" C A N C E L A N D O . . .",20);
													getch();
												}
												else
												{
													Error(" La opción es incorrecta! Verifícala",20);
												}
											}
										}while(opc < 1 || opc >3);
								break;
								
						}
					}
					else
					{
						Error("La opción es inválida",35);
					}
				}while(opcion != 13);			
			}
			else
			{
				Error("No se encontró la clave! Verifícala ",14);
			}	
		}
			
	}while (clave[0] != '\0');
}

int ImprimirEmpMod (Empresa *catemp, int i)
{
	int opc;
	clear();
	opc = 0;
	Centrar(catemp[i].nombremp,2);
	mvprintw(4,180," Clave: %s",catemp[i].clave);
	mvprintw(4,2,"Registro: %d",i+1);
	mvprintw(8,2,"1 : Nombre: %s",catemp[i].nombremp);
	mvprintw(9,2,"2 : Giro: %s",catemp[i].giro);
	mvprintw(10,2,"3 : Domicilio: %s",catemp[i].domicilio);
	mvprintw(11,2,"4 : Estado: %s",catemp[i].estado);
	mvprintw(12,2,"5 : CP: %d",catemp[i].cp);
	mvprintw(13,2,"6 : Telefono: %s",catemp[i].telefono);
	mvprintw(14,2,"7 : Fax: %s",catemp[i].fax);
	mvprintw(15,2,"8 : Contacto: %s",catemp[i].nomcont);
	mvprintw(16,2,"9 : Correo: %s",catemp[i].correo);
	mvprintw(17,2,"10 : Visitas: %s",catemp[i].visita);
	mvprintw(18,2,"11 : Estancias: %s",catemp[i].estancia);
	mvprintw(19,2,"12 : Servicios Sociales: %s",catemp[i].servicios);
	mvprintw(20,2,"13 : Regresar");
	mvprintw(26,6,"Introduzca el número de la opción a modificar : ");
	echo();
	scanw("%d",&opc);
	return opc;
}

//**********************************************************************
void CosultarEmp(Empresa *catemp,int t)
{	
	char clave[MIN];
	int r = 2, c = 10, ind, opc;
	do
	{
		clear();
		opc = 0;
		Centrar("C O N S U L T A R   E M P R E S A ",2);
		mvprintw(4,2,"CONSULTA POR:");
		mvprintw(6,2,"1 : Clave");
		mvprintw(7,2,"2 : Una x una");
		mvprintw(8,2,"3 : Salir");
		mvprintw(10,2,"Introduzca el número de su opción : ");
		echo();
		scanw("%d",&opc);
		if (opc == 1)
		{ 
			do
			{
				clear();
				Centrar("C O N S U L T A R   E M P R E S A ",2);
				mvprintw(r + 2, c, "Introduzca la clave de la empresa : ");
				LeerClave(clave, r + 2, 46);
				if (clave[0] != '\0')
				{
					ind = BuscarEmp(catemp, t, clave);
					if (ind != -1)
					{
						clear();
						ImprimirEmp(catemp, ind);
					}
					else 
					{
						Error("No se encontró la clave! Verifícala ",14);
					}
				}
			}while (clave[0] != '\0');
		}
		if (opc == 2)
		{
			ImprimirEmp2(catemp, t);
		}
		if (opc < 1 || opc > 3)
		{
			Error("La opción es inválida",14);
		}
	}while (opc != 3);
}

/*
void ListaEmp(Empresa *catemp,int *cont, int *rr, char clave[MIN])
{
	int i, r = 6, c = 4;
	clear();
	Centrar("\t\tEmpresas en el catalogo\n",4);
	mvprintw(r, c,"Num ");
	mvprintw(r, c+10,"C L A V E");
	mvprintw(r, c+50,"NOMBRE");
	r = 7;
	for (i=0; i < *cont; i++)
	{
		mvprintw(r+i+1, c,"%2d",i+1);
		mvprintw(r+i+1, c+10,"%10s",catemp[i].clave);
		mvprintw(r+i+1, c+30,"%20s",catemp[i].nombremp);		
	}
	(*rr) = r + i + 2;
	LeerClave(clave, i + r + 2, 10);	
}
*/


void ImprimirEmp2 (Empresa *catemp, int t)
{
	int ind = 0;
	char cad[2];
	do 
	{
		clear();
		mvprintw(1,1," Total de registros : %d\n",t);
		Centrar(catemp[ind].nombremp,2);
		mvprintw(4,2,"Registro: %d",ind+1);
		mvprintw(4,150,"Clave: %s",catemp[ind].clave);
		mvprintw(6,2,"Giro: %s",catemp[ind].giro);
		mvprintw(7,2,"Domicilio: %s",catemp[ind].domicilio);
		mvprintw(8,2,"Estado: %s",catemp[ind].estado);
		mvprintw(9,2,"CP: %d",catemp[ind].cp);
		mvprintw(10,2,"Telefono: %s",catemp[ind].telefono);
		mvprintw(11,2,"Fax: %s",catemp[ind].fax);
		mvprintw(12,2,"Contacto: %s",catemp[ind].nomcont);
		mvprintw(13,2,"Correo: %s",catemp[ind].correo);
		mvprintw(14,2,"Visitas: %s",catemp[ind].visita);
		mvprintw(15,2,"Estancias: %s",catemp[ind].estancia);
		mvprintw(16,2,"Servicios Sociales: %s",catemp[ind].servicios);
		if(ind < t -1)
		{
			mvprintw(22,60,"Presione enter para continuar");
			mvprintw(22,110,"Presione una letra para salir");
			Leercad(cad);
		}
		else
		{
			mvprintw(22,50,"Presione enter para salir");
			getch();
		}
		ind++;
	}while(ind < t && cad[0] == '\0');
}
	
void ImprimirEmp (Empresa *catemp, int i)
{
	Centrar(catemp[i].nombremp,2);
	mvprintw(4,2,"Registro: %d",i+1);
	mvprintw(4,150,"Clave: %s",catemp[i].clave);
	mvprintw(6,2,"Giro: %s",catemp[i].giro);
	mvprintw(7,2,"Domicilio: %s",catemp[i].domicilio);
	mvprintw(8,2,"Estado: %s",catemp[i].estado);
	mvprintw(9,2,"CP: %d",catemp[i].cp);
	mvprintw(10,2,"Telefono: %s",catemp[i].telefono);
	mvprintw(11,2,"Fax: %s",catemp[i].fax);
	mvprintw(12,2,"Contacto: %s",catemp[i].nomcont);
	mvprintw(13,2,"Correo: %s",catemp[i].correo);
	mvprintw(14,2,"Visitas: %s",catemp[i].visita);
	mvprintw(15,2,"Estancias: %s",catemp[i].estancia);
	mvprintw(16,2,"Servicios Sociales: %s",catemp[i].servicios);
	mvprintw(20,6,"Presione enter para salir");
	getch();
}
//#########################################################################################################################
void Alumnos (Alumno *catalumn,int *cont, int usuario)
{
	int opcion;
	do
	{
		clear();
		opcion = Menu1 ("A L U M N O S");
		if(opcion>=1 && opcion <=4)
		{
			switch (opcion)
			{
				case 1: if(usuario != 2)
							RegistrarAlumn(catalumn, cont);
						else
							Error("\tPermiso Denegado !",12);
					break;
				
				case 2: if(usuario != 2)
							EliminarAlumn(catalumn, cont);
						else
							Error("\tPermiso Denegado !",12);
						
					break;
		
				case 3: if(usuario != 2)
							ModificarAlumn(catalumn, *cont);
						else
							Error("\tPermiso Denegado !",12);
					break;
		
				case 4:CosultarAlumn(catalumn, *cont);
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tFuera de rango, intente nuevamente!",12);
		}				
	}while(opcion != 5);
} 


void RegistrarAlumn(Alumno *catalumn,int *t)
{
	char cad[MAX],matri[MAT];
	int ind,i=0;
	do
	{
		clear();
		Centrar("I N S E R T A R   A L U M N O ",2);
		mvprintw(4, 100, " Rellene los datos ");
		mvprintw(7, 2, " Matricula : ");
		LeeMatricula(matri, 7, 14);
		if (matri[0] != '\0')
		{
			ind = BuscarAlumn(catalumn, *t, matri);
			if (ind == -1)
			{
				strcpy(catalumn[*t].mat, matri);
				mvprintw(8, 2, " Nombre : ");
				LeerNomAlumn(cad,8,11);
				if(cad[0] != '\0')
				{
					catalumn[*t].nomalum = (char *) malloc(strlen(cad));
					strcpy(catalumn[*t].nomalum, cad);
					mvprintw(9, 2, " Apellidos : ");
					LeerApellidoAlumn(cad,9,14);
					if(cad[0] != '\0')
					{
						catalumn[*t].apealum = (char *) malloc(strlen(cad));
						strcpy(catalumn[*t].apealum, cad);
						(*t)++;
						getch();
					}
					else
					{
						mvprintw(24,100," Pulse enter para salir");
						Centrar(" C A N C E L A N D O . . .",18);
						getch();
					}	
				}
				else
				{
				mvprintw(24,100," Pulse enter para salir");
				Centrar(" C A N C E L A N D O . . .",18);
				getch();
				}
			}
			else 
			{
				Error("la matricula ya existe!",18);
			}
		}
		else
		{
		mvprintw(24,100," Pulse enter para salir");
		Centrar(" C A N C E L A N D O . . .",18);
		getch();
		}				
	}while(matri[0]!='\0' && cad[0] !='\0' && *t < ML);
}

void EliminarAlumn(Alumno *catalumn,int *t)
{
	char matri[MAT];
	int r = 2, c = 10, ind;
	do
	{
		clear();
		Centrar("E L I M I N A R    A L U M N O ",2);
		mvprintw(r + 2, c, "Introduzca la matricula del alumno : ");
		LeeMatricula(matri, r + 2, 46);
		if (matri[0] != '\0')
		{
			ind = BuscarAlumn(catalumn, *t, matri);
			if (ind != -1)
			{
				clear();
				BorrarAlumn(catalumn, t, ind);
			}
			else 
			{
				Error("No se encontró la matricula! Verifícala ",8);
			}
		}
	}while (matri[0] != '\0');
}

int BuscarAlumn(Alumno *catalumn, int t, char matri[MAT])
{
	int ind, sal = - 1;
	for (ind = 0; ind < t && sal == - 1; ind++)
	{
		if (strcmp(matri, catalumn[ind].mat) == 0)
			sal = ind;
	}
	return sal;
}

void BorrarAlumn(Alumno *catalumn,int *total, int ind)
{
	int conf, i;
	do
	{
		clear();
		Centrar("¿Esta seguro que desea eliminar el alumno ", 2);
		Centrar(catalumn[ind].nomalum, 4);
		printw( "?");
		mvprintw(8,90," 1 : Si" );
		mvprintw(8,120," 2 : No" );
		mvprintw(10,70," \tIntroduzca el número de opción : ");
		echo();
		scanw("%d",&conf);
		if (conf >= 1 && conf <= 2)
		{	
			if (conf == 1)
			{
				for(i= ind; i < *total - 1; i++)
				{
					catalumn[i]=catalumn[i+1];
				}
				Centrar(" E L I M I N A N D O . . . ",20);
				*total=*total -1;
				getch();
			}
			if(conf == 2)
			{
				Centrar(" C A N C E L A N D O . . . ",20);
				getch();
			}
		}
		else
		{
			Error("\tError, opción inválida!",20);
		}
	}while (conf < 1 || conf > 2);
}

void ModificarAlumn(Alumno *catalumn,int t)
{
	char cad[MAX];
	char matri[MAT];
	int r = 2, c = 10, ind, opcion;
	do
	{
		clear();
		Centrar("M O D I F I C A R    A L U M N O ",2);
		mvprintw(r + 2, c, "Introduzca la matricula del alumno : ");
		LeeMatricula(matri, r + 2, 46);
		if (matri[0] != '\0')
		{
			ind = BuscarAlumn(catalumn, t, matri);
			if (ind != -1)
			{
				clear();
				do
				{
					opcion = ImprimirAlumnMod (catalumn, ind);					
					if (opcion >= 1 && opcion <= 3)
					{
						switch (opcion)
						{
							case 1 : clear(); 
									Centrar(" MODIFICAR MATRICULA DEL ALUMNO ",2);
									mvprintw(10,4," Escriba la nueva matricula del alumno : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeeMatricula(matri, r + 2, 46);
									if (matri[0] != '\0')
									{
										strcpy(catalumn[ind].mat, matri);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 2 : clear(); 
									Centrar(" MODIFICAR NOMBRE DEL ALUMNO ",2);
									mvprintw(10,4," Escriba el nuevo nombre del alumno : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerNomAlumn(cad,10,45);
									if (cad[0] != '\0')
									{
										catalumn[ind].nomalum = (char *) malloc(strlen(cad));
										strcpy(catalumn[ind].nomalum, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 3 : clear(); 
									Centrar(" MODIFICAR LOS APELLIDOS DEL ALUMNO ",2);
									mvprintw(10,4," Escriba los nuevos apellidos del alumno : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerApellidoAlumn(cad,10,46);
									if (cad[0] != '\0')
									{
										catalumn[ind].apealum = (char *) malloc(strlen(cad));
										strcpy(catalumn[ind].apealum, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
						}
					}
					else
					{
						Error("La opción es inválida",35);
					}
				}while(opcion != 4);			
			}
			else
			{
				Error("No se encontró la matricula! Verifícala ",14);
			}	
		}	
	}while (matri[0] != '\0');
}

int ImprimirAlumnMod (Alumno *catalumn, int i)
{
	int opc;
	clear();
	Centrar(catalumn[i].nomalum,2);
	mvprintw(4,2,"Registro: %d",i+1);
	mvprintw(7,2,"1: Matricula: %s",catalumn[i].mat);
	mvprintw(8,2,"2 : Nombre: %s",catalumn[i].nomalum);
	mvprintw(9,2,"3 : Apellido: %s",catalumn[i].apealum);
	mvprintw(11,2,"4 : Regresar");
	mvprintw(26,6,"Introduzca el número de la opción a modificar : ");
	echo();
	scanw("%d",&opc);
	return opc;
}

void CosultarAlumn(Alumno *catalumn,int t)
{	
	char matri[MAT];
	int r = 2, c = 10, ind, opc;
	do
	{
		clear();
		opc=0;
		Centrar("C O N S U L T A R   A L U M N O ",2);
		mvprintw(4,2,"CONSULTA POR:");
		mvprintw(6,2,"1 : Matricula");
		mvprintw(7,2,"2 : Uno x uno");
		mvprintw(9,2,"3 : Salir");
		mvprintw(11,2,"Introduzca el número de su opción : ");
		echo();
		scanw("%d",&opc);
		if (opc == 1)
		{ 
			do
			{
				clear();
				Centrar("C O N S U L T A R   A L U M N O ",2);
				mvprintw(r + 2, c, "Introduzca la matricula del alumno : ");
				LeeMatricula(matri, r + 2, 46);
				if (matri[0] != '\0')
				{
					ind = BuscarAlumn(catalumn, t, matri);
					if (ind != -1)
					{
						clear();
						ImprimirAlumn(catalumn, ind);
					}
					else 
					{
						Error("No se encontró la matricula! Verifícala ",14);
					}
				}
			}while (matri[0] != '\0');
		}
		if (opc == 2)
		{
			ImprimirAlumn2(catalumn, t);
		}
		if (opc < 1 || opc > 3)
		{
			Error("La opción es inválida",14);
		}
	}while (opc != 3);
}
	
void ImprimirAlumn (Alumno *catalumn, int i)
{
	Centrar(catalumn[i].nomalum,2);
	mvprintw(4,2,"Registro: %d",i+1);
	mvprintw(5,2,"Matricula: %s",catalumn[i].mat);
	mvprintw(6,2,"Apellidos: %s",catalumn[i].apealum);
	mvprintw(11,6,"Presione enter para salir");
	getch();
}

void ImprimirAlumn2 (Alumno *catalumn, int t)
{
	int ind;
	for (ind = 0; ind < t; ind++)
	{
		clear();
		Centrar(catalumn[ind].nomalum,2);
		mvprintw(4,2,"Registro: %d",ind+1);
		mvprintw(5,2,"Matricula: %s",catalumn[ind].mat);
		mvprintw(6,2,"Apellidos: %s",catalumn[ind].apealum);
		if(ind < t -1)
			mvprintw(20,6,"Presione enter para continuar");
		else
			mvprintw(20,6,"Presione enter para salir");
		getch();
	}
}

//###########################################################################################
void Profesores(Profesor *catprofe, int *cont, int usuario)
{
	int opcion;
	do
	{
		clear();
		opcion = Menu1 ("P R O F E S O R E S");
		if(opcion>=1 && opcion <=5)
		{
			switch (opcion)
			{
				case 1:	clear();
						if(usuario != 2)
							RegistrarProfe(catprofe, cont);
						else
							Error("\tPermiso Denegado !",12);
					break;
				
				case 2:	clear();
						if(usuario != 2)
							EliminarProfe(catprofe, cont);
						else
							Error("\tPermiso Denegado !",12);
					break;
		
				case 3:	clear();
						if(usuario != 2)
							ModificarProfe(catprofe, *cont);
						else
							Error("\tPermiso Denegado !",12);
					break;
		
				case 4:	clear();
						ConsultarProfe(catprofe, *cont);
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

void RegistrarProfe(Profesor *catprofe, int *cont)
{
	char cad[MAX];
	int ind, opcion, opc, cp; 
	do
	{
		clear();
		Centrar("R E G I S T R A R     P R O F E S O R ",2);
		Centrar(" Introduzca los datos ", 4);
		mvprintw(7, 5, " Nombre : ");
		LeerNomProfe(cad,7,15);
		mvprintw(24,100," Pulse enter para salir");
		if (cad[0] != '\0')
		{
			catprofe[*cont].nomprofe = (char *) malloc(strlen(cad));
			strcpy(catprofe[*cont].nomprofe, cad);			
			mvprintw(8, 5, " Apellidos : ");
			LeerApellidoProfe(cad,8,17);
			if(cad[0] != '\0')
			{
				catprofe[*cont].apeprofe = (char *) malloc(strlen(cad));
				strcpy(catprofe[*cont].apeprofe, cad);
				mvprintw(9, 5, " Clave : ");
				LeerClav(cad, 9, 13);
				if(cad[0] != '\0')
				{
					strcpy(catprofe[*cont].clav, cad);
					(*cont)++;
				}
				else
				{
					mvprintw(24,100," Pulse enter para salir");
					Centrar(" C A N C E L A N D O . . .",18);
					getch();
				}
			}
			else									
			{
				mvprintw(24,100," Pulse enter para salir");
				Centrar(" C A N C E L A N D O . . .",18);
				getch();
			}
		}			
		else
		{
			mvprintw(24,100," Pulse enter para salir");
			Centrar(" C A N C E L A N D O . . .",18);
			getch();
		}
	}while(cad[0] !='\0' && *cont < ML);
}


void EliminarProfe(Profesor *catprofe ,int *t)
{
	char clav[CAL];
	int r = 2, c = 10, ind;
	do
	{
		clear();
		Centrar("E L I M I N A R    P R O F E S O R ",2);
		mvprintw(r + 2, c, "Introduzca la clave del profesor: ");
		LeerClav(clav, r + 2, 46);
		if (clav[0] != '\0')
		{
			ind = BuscarProfe(catprofe, *t, clav);
			if (ind != -1)
			{
				clear();
				BorrarProfe(catprofe, t, ind);
			}
			else 
			{
				Error("No se encontró la clave! Verifícala ",8);
			}
		}
	}while (clav[0] != '\0');
}

int BuscarProfe( Profesor *catprofe, int t, char clav[CAL])
{
	int ind, sal = - 1;
	for (ind = 0; ind < t && sal == - 1; ind++)
	{
		if (strcmp(clav, catprofe[ind].clav) == 0)
			sal = ind;
	}
	return sal;
}

void BorrarProfe(Profesor *catprofe, int *total, int ind)
{
	int conf, i;
	do
	{
		clear();
		Centrar("¿Esta seguro que desea eliminar al profesor", 2);
		Centrar(catprofe[ind].nomprofe, 4);
		printw( "?");
		mvprintw(8,90," 1 : Si" );
		mvprintw(8,120," 2 : No" );
		mvprintw(10,70," \tIntroduzca el número de opción : ");
		echo();
		scanw("%d",&conf);
	
		if (conf >= 1 && conf <= 2)
		{	
			if (conf == 1)
			{
				for(i= ind; i < *total - 1; i++)
				{
					catprofe[i]=catprofe[i+1];
				}
				Centrar(" E L I M I N A N D O . . . ",20);
				*total=*total -1;
				getch();
			}
			if(conf == 2)
			{
				Centrar(" C A N C E L A N D O . . . ",20);
				getch();
			}
		}
		else
		{
			Error("\tError, opción inválida!",20);
		}
	}while (conf < 1 || conf > 2);
}

void ModificarProfe(Profesor *catprofe,int t)
{
	char cad[MAX];
	char clav[CAL];
	int r = 2, c = 10, ind, opcion, opc, cp;
	do
	{
		clear();
		Centrar("M O D I F I C A R    P R O F E S O R ",2);
		mvprintw(r + 2, c, "Introduzca la clave del profesor : ");
		LeerClav(clav, r + 2, 46);
		if (clav[0] != '\0')
		{
			ind = BuscarProfe(catprofe, t, clav);
			if (ind != -1)
			{
				clear();
				do
				{
					opcion = ImprimirProfeMod (catprofe, ind);					
					if (opcion >= 1 && opcion <= 14)
					{
						switch (opcion)
						{
							case 1 : clear(); 
									Centrar(" MODIFICAR CLAVE DEL PROFESOR ",2);
									mvprintw(10,5," Escriba la nueva clave del profesor: ");
									mvprintw(5,24," Pulse enter para cancelar");
									LeerClave(clav, r + 10, 46);
									if (clav[0] != '\0')
									{
										strcpy(catprofe[ind].clav, clav);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 2 : clear(); 
									Centrar(" MODIFICAR NOMBRE DEL PROFESOR ",2);
									mvprintw(10,4," Escriba el nuevo nombre del profesor : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerNomProfe(cad,10,43);
									if (cad[0] != '\0')
									{
										catprofe[ind].nomprofe = (char *) malloc(strlen(cad));
										strcpy(catprofe[ind].nomprofe, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
							
							case 3 : clear(); 
									Centrar(" MODIFICAR LOS APELLIDOS DEL PROFESOR ",2);
									mvprintw(10,4," Escriba los nuevos apellidos del profesor : ");
									mvprintw(14,25," Pulse enter para cancelar");
									LeerApellidoProfe(cad,10,48);
									if (cad[0] != '\0')
									{
										catprofe[ind].apeprofe = (char *) malloc(strlen(cad));
										strcpy(catprofe[ind].apeprofe, cad);
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" M O D I F I C A N D O . . .",18);
										getch();
									}
									else
									{
										mvprintw(24,100," Pulse enter para salir");
										Centrar(" C A N C E L A N D O . . .",18);
										getch();
									}
								break;
						}
					}
					else
					{
						Error("La opción es inválida",35);
					}
				}while(opcion != 4);			
			}
			else
			{
				Error("No se encontró la clave! Verifícala ",14);
			}	
		}
			
	}while (clav[0] != '\0');
}

int ImprimirProfeMod (Profesor *catprofe, int i)
{
	int opc;
	clear();
	Centrar(catprofe[i].nomprofe,2);
	mvprintw(4,2,"Registro: %d",i+1);
	mvprintw(7,2,"1: Clave: %s",catprofe[i].clav);
	mvprintw(8,2,"2 : Nombre: %s",catprofe[i].nomprofe);
	mvprintw(9,2,"3 : Apellidos: %s",catprofe[i].apeprofe);
	mvprintw(11,2,"4 : Regresar");
	mvprintw(26,6,"Introduzca el número de la opción a modificar : ");
	echo();
	scanw("%d",&opc);
	return opc;
}


void ConsultarProfe(Profesor *catprofe, int t)
{	
	char clav[CAL];
	int r = 2, c = 10, ind, opc;
	do
	{
		clear();
		opc=0;
		Centrar("C O N S U L T A R   P R O F E S O R ",2);
		mvprintw(4,2,"CONSULTA POR:");
		mvprintw(6,2,"1 : Clave");
		mvprintw(7,2,"2 : Uno a uno");
		mvprintw(9,2,"3 : Salir");
		mvprintw(11,2,"Introduzca el número de su opción : ");
		echo();
		scanw("%d",&opc);
		if (opc == 1)
		{ 
			do
			{
				clear();
				Centrar("C O N S U L T A R   P R O F E S O R ",2);
				mvprintw(r + 2, c, "Introduzca la clave del profesor : ");
				LeerClav(clav, r + 2, 46);
				if (clav[0] != '\0')
				{
					ind = BuscarProfe(catprofe, t, clav);
					if (ind != -1)
					{
						clear();
						ImprimirProfe(catprofe, ind);
					}
					else 
					{
						Error("No se encontró la clave! Verifícala ",14);
					}
				}
			}while (clav[0] != '\0');
		}
		if (opc == 2)
		{
			ImprimirProfe2(catprofe, t);
		}
		if (opc < 1 || opc > 3)
		{
			Error("La opción es inválida",14);
		}
	}while (opc != 3);
}

void ImprimirProfe2 (Profesor *catprofe, int t)
{
	int ind;
	for (ind = 0; ind < t; ind++)
	{
		clear();
		Centrar(catprofe[ind].nomprofe,2);
		mvprintw(4,2,"Registro: %d",ind+1);
		mvprintw(5,2,"Clave: %s",catprofe[ind].clav);
		mvprintw(6,2,"Apellidos: %s",catprofe[ind].apeprofe);
		if(ind < t -1)
			mvprintw(20,6,"Presione enter para continuar");
		else
			mvprintw(20,6,"Presione enter para salir");
		getch();
	}
}
	
void ImprimirProfe (Profesor *catprofe, int i)
{
	Centrar(catprofe[i].nomprofe,2);
	mvprintw(4,2,"Registro: %d",i+1);
	mvprintw(5,2,"Clave: %s",catprofe[i].clav);
	mvprintw(6,2,"Apellidos: %s",catprofe[i].apeprofe);
	mvprintw(11,6,"Presione enter para salir");
	getch();
}

void Visitas (Empresa *catemp,int te, Profesor *catprofe, int tp, Visita *visitas, int *tv, int usuario)
{
	int opcion;
	do
	{
		initscr();
		keypad(stdscr, TRUE);
		noecho();
		clear();
		//Centrar(,2);
		opcion = Menu1 ("V I S I T A S");
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
		
				case 4: clear();
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

void CosultarVisita ()
{
	int opcion;
	do
	{
		opcion = Menu2();
		if(opcion>=1 && opcion <=2)
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
		if(opcion < 1 || opcion > 3 )
		{
			Error("\tFuera de rango, intente nuevamente!",17);
		}				
	}while(opcion != 3);
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
		//Centrar("E S T A N C I A S",2);
		opcion = Menu1 ("E S T A N C I A S");
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
		//Centrar("S E R V I C I O S   S O C I A L E S ",2);
		opcion = Menu1 ("S E R V I C I O S   S O C I A L E S ");
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



/*void Visitas ()//Visita *lisvisita,int *t,Profesor *catprofe, int *to, Empresa *catemp, int *cont)
{
	int opcion;
	do
	{
		clear();
		opcion = Menu1 ("V I S I T A S");
		if(opcion>=1 && opcion <=6)
		{
			switch (opcion)
			{
				case 1: //RegistrarVisita(lisvisita,t,catprofe,to,catemp,cont);
					break;
				
				case 2://EliminarVisita();
					break;
		
				case 3://ModificarVisita();
					break;
		
				case 4: clear();
						CosultarVisita();
					break;
			}
			
		}
		if(opcion < 1 || opcion > 5 )
		{
			Error("\tFuera de rango, intente nuevamente!",17);
		}				
	}while(opcion != 5);
}*/ 

//void LeeDatos(Alumno l[ML], int *t)
/*
 * Función que lee y valida datos del teclado proporcionados por el usuario al arreglo l.
 * Conforme se almacenan los datos en el arreglo se actualiza la variable a donde apunta t.
*/
/*
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

 * Función que imprime los t elementos del arreglo l a la pantalla. Si el arreglo está vacío imprime
 * que no hay datos leídos.
*/
/*{
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
Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Devolverá el índice donde localizó la 
 * matrícula mat, si no encontró la matrícula devolverá -1.*/

/*{
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
Este procedimiento recibe la lista de alumnos y el total (t) de
 * elementos del arreglo. Eliminará el registro donde localice la 
 * matrícula mat, pedirá confirmación para eliminarla.
 * Enviará un mensaje si la matrícula no se encontró.*/

/*{
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
*/

