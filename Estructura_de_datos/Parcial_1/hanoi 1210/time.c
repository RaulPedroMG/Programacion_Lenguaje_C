#include <stdio.h>
#include <time.h>
#include <ncurses.h> 
/*
 * El resultado debe ser algo así como
 * Fri 2008-08-22 15:21:59 WAST
 */
 
int main(void)
{
    time_t now;
    time_t des;
    double DIF;
    char nom[23];
 
    /* Obtener la hora actual */
    now = time(0);
    scanf("%s",nom);
    des = time(0);
	DIF = difftime( des,now);
	printf(" te has tardado %g segundos par escribir tu nombre",DIF);
    return 0;
}
