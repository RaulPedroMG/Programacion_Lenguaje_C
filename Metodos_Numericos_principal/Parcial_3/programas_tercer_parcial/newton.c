#include <stdio.h>
#include <stdlib.h>

int main()
{
	float y,x,n=4;
	int j,i;
	float A[5][4]={{-3,2,4,7},{8,-7,14,24}};

	for(i=0; i<5; i++)
	{
	  for(j=0; j<4; j++)
	  {
	    printf(" %f ",A[i][j]);
	  }
	}
	
	y=n-1;
	x=1;
	for(i=0; i<4; i++)
	{	
	   for(j=0; j<y; j++)
	   {
			A[i+2][j]=((A[i+1][j+1]-A[i+1][j])/(A[0][j+x]-A[0][j]));
			y--;
	   }
	   printf("\n");
	}
	
	for(i=0; i<6;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%f ",A[i][j]);
		}	
		printf("\n");		
	}
	
return 0;
}
