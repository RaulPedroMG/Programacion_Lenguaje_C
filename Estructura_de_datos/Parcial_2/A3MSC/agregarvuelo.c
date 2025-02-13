/* Se usa para llenar las pistas y saber cuales son los aviosnes que saldrán
*/
void AgregarVuelo(Cola *aux1, Cola *aux2, Cola *aux3,  Vuelo *turno)
{
	int num, a1=1, a2=1, a3=1;
	do{
		srand((unsigned) time(NULL)); 
		num=rand() % 20+1;
		if(!colallena(aux1) && *turno[num].asignado!=1){
			insertar(*aux1,num);
			*turno[num].asignado=1;
		}else{
			a1=0;	
		}
		if(!colallena(aux2) && a1!=0 && *turno[num].asignado!=1){
			insertar(*aux2,num);
			*turno[num].asignado=1;
		}else{
			a3=0;	
		}
		if(!colallena(aux3)  && a2!=0 && *turno[num].asignado!=1){
			insertar(*aux3,num);
			*turno[num].asignado=1;
		}
		else{
			a3=0;	
		}
	}while(a3!=0)
}
