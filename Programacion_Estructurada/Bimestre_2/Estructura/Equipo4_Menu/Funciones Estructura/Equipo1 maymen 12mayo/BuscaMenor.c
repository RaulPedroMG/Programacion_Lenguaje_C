void BuscarMenor(Alumno l[ML],int t, int cont[ML], int *j);
{
	int i,c=4;
	float menor;
	menor=l[0].calif[c];
	for(i=1; i < t; i++)
	{
		if(l[i].calif[c] < menor)
		{
			menor = l[i].calif[c];
		}
	}
	for(i=0, *j=0; i < t; i++)
	{
		if(l[i].calif[c] == menor)
		{
			cont[*j] = i;
			(*j)++;
		}
	}
}
