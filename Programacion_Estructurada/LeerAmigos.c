void LeeArchivos(Amigos *lista, int *nua)
{
	FILE *arch;
	echo(); 
  arch = fopen("amigos.dat", "rb");
  if(arch == NULL){
    fprintf(stderr, "No se puede abrir el archivo de salida");
    return;
  }
	mvprintw(3,9,"Registros cargados"); 
	while(!feof(arch) && *nua < N){
		if (fread(&lista[*nua],sizeof(lista[*nua]),1,arch) > 0 )
			(*nua)++;
	}
	fclose(arch);
  getch();
  return;
}
