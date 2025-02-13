/*
 * InterpolacionSeg1erOrden.c
 * 
 * Copyright 2012 Antonio <antonio@antonio-HP-Pavilion-dv4-Notebook-PC>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int main(){
	float **xy,m,a,res;
	int i,n;
	FILE *out,*ecua;
	printf("Interpolacion Segmentada de Pirmer Orden\n");
	printf("Da el numero de puntos a evaluar para encontrar la funcion que pase por los puntos");
	scanf("%d",&n);
	xy = (float **)malloc(n*sizeof(float*));
	for(i=0;i<n;i++)
		xy[i] = (float*)malloc(2*sizeof(float));
	out=fopen("puntos.dat","w");
	for(i=0;i<n;i++)
	{
		printf("introduce el valor de x(%d)",i);
		scanf("%f",&xy[i][0]);
		printf("introduce el valor de y(%d)",i);
		scanf("%f",&xy[i][1]);
		fprintf(out,"%lf %lf\n",xy[i][0],xy[i][1]);
	}
	fclose(out);
	ecua=fopen("ecuaciones.gnp","w");
	fprintf(ecua,"plot \"puntos.dat\"\n");
	fprintf(ecua,"set parametric\n");
	fprintf(ecua,"set trange[0:1]\n");
	for(i=0;i<n-1;i++){
		res=xy[i+1][0]-xy[i][0];
		m=(xy[i+1][1]-xy[i][1])/(xy[i+1][0]-xy[i][0]);
		a=xy[i][1]-m*xy[i][0];
		fprintf(ecua,"replot %f + %f * t , %f + %f * (%f + %f * t) w l \n",xy[i][0],res,a,m,xy[i][0],res);
	}
	fclose(ecua);
	return 0;
}


