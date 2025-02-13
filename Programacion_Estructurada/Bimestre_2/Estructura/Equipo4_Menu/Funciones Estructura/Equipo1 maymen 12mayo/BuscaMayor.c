void BuscarMayor(Alumno l[ML],int t, int cont[ML], int *j);
{
	int i,c=4;
	float mayor;
	mayor=l[0].calif[c];
	for(i=1; i < t; i++)
	{
		if(l[i].calif[c] > mayor)
		{
			mayor = l[i].calif[c];
		}
	}
	for(i=0, *j=0; i < t; i++)
	{
		if(l[i].calif[c] == mayor)
		{
			cont[*j] = i;
			(*j)++;
		}
	}
}
