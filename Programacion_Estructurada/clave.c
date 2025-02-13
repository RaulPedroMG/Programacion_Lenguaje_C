#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void obtenerclave(char *cad, char clave[10]);
void separacad(char *cad, int k);
//void clave(int mat[l][m], int k);

int main ()
{
	int i, cont = 0, k;
	char *cad;
	
	for(i = 0; i !='\0'; i = i + 1)
	{
		if(cad[i] == ' ' || cad[i]=='\0')
		{
			cont = cont + 1;
		}
	}
	k = cont;
	separacad(cad, k);
	return 0;
}



void separacad(char *cad, int k)

	
{
	int l = 0,m = 0;
	int mat[l][m], i;
	do
	{
		for(i = 0; i != '\0'; i = i + 1);
		{
			mat[l][m] = cad[i];
			m=m+1;
			if (cad[i] == ' ');
				{
					l = l +1;
					m = 0;
				}
		}
	}while (l != k);
	//clave(mat[l][m], k);
	
}


/*void clave(int mat[l][m], int k)


{
	int cont=0, x=0, m=0, l=0;
	char *clav;
	int i = 0;
	for (m = 0; x == 1; m = m + 1)
	{
		for (l = 0; l != k; l = l + 1)
		{
			clav[i] = mat[l][m];
			cont = cont + 1;
			i = i + 1;
			if (cont == 10)
			{
				x=1;
				clav[i] = '\0';
			}
		}
	}
}*/
