#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
 
#define msg "                   ============ CRONOMETRO DIGITAL =========="
#define aut "\n                      .**o._.o**. By Tarik Ahmad.**o._.o**."
 
/* Cabecalhos */
void desenha_hrDE(WINDOW *win, int hr);
void desenha_hrDD(WINDOW *win, int hr);
void desenha_minDE(WINDOW *win, int min);
void desenha_minDD(WINDOW *win, int min);
void desenha_segDE(WINDOW *win, int seg);
void desenha_segDD(WINDOW *win, int seg);
 
int main(void)
{
  /* Declarando as variáveis */  
  int hora,min,seg,qh,rh,qm,rm,qs,rs;
  //char sair;
  WINDOW *wstd, *wborder;
  //int i;
  //int u = 0;
     
  /* Inicializando variáveis */
  hora = 0, min = 0, seg = 0;
   
  /* Inicializando modo grafico com curses.h */
  (void)initscr();  
  wstd = newwin(9,58,5,10);
  wborder = newwin(11,62,4,8);
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_RED);
  init_pair(2,COLOR_BLUE,COLOR_YELLOW);
  init_pair(3,COLOR_BLACK,COLOR_WHITE);
  init_pair(4,COLOR_YELLOW,COLOR_BLUE);
  init_pair(5,COLOR_BLACK,COLOR_WHITE);
  init_pair(6,COLOR_RED,COLOR_BLACK);
  init_pair(7,COLOR_YELLOW,COLOR_YELLOW);
  init_pair(8,COLOR_WHITE,COLOR_BLACK);
  wbkgd(wstd,COLOR_PAIR(8) | A_BOLD | A_BLINK);
  wbkgd(wborder,COLOR_PAIR(3) | A_BLINK);
  curs_set(0); /* Desabilitando o cursor do mouse */
  system("CLS");
  puts(msg);
  puts(aut);
  sleep(2);
         
  while (hora < 24)
  {
    while (min < 60)
    {          
      while (seg < 60)
      {    
        wrefresh(wborder);  
        wrefresh(wstd);
         
        /* Calculo para segundos */        
        qs = seg / 10;
        rs = seg % 10;
        desenha_segDE(wstd,qs);
        desenha_segDD(wstd,rs);
         
        /* Calculo para minutos */
        qm = min / 10;
        rm = min % 10;
        desenha_minDE(wstd,qm);
        desenha_minDD(wstd,rm);  
         
         
        /* Calculo para horas */
        qh = hora / 10;
        rh = hora % 10;
        desenha_hrDE(wstd,qh);
        desenha_hrDD(wstd,rh);
         
        sleep(1);
        seg = seg + 1;      
      }              
      seg = 0; /* Resetando segundo */
      min = min + 1; /* Incrementando minuto */
    }    
    min = 0;
    hora = hora + 1; /* Incrementando hora */    
         
    /* Reseta hora para que o loop seja continuo */
    if (hora > 23)
    {
      hora = 0;
    }    
  }
  endwin(); /* Finalizando modo curses */
  return(0);
}
 
/* Sub-rotina que controla o digito da esquerda nas horas */
void desenha_hrDE(WINDOW *win, int hr)
{
  switch(hr)
  {    
    case 0:
      mvwprintw(win,1,3,"###");
      mvwprintw(win,2,2,"#   #");
      mvwprintw(win,3,2,"#   #");
      mvwprintw(win,4,2,"    ");
      mvwprintw(win,5,2,"#   #");
      mvwprintw(win,6,2,"#   #");
      mvwprintw(win,7,3,"###");  
      break;
         
    case 1:
      mvwprintw(win,1,3,"   #");      
      mvwprintw(win,2,2," ");
      mvwprintw(win,3,2," ");
      mvwprintw(win,4,2," ");
      mvwprintw(win,5,2," ");
      mvwprintw(win,6,2," ");
      mvwprintw(win,7,2,"    #");
      break;
 
    case 2:
      mvwprintw(win,1,3,"###  ");
      mvwprintw(win,4,3,"###");
      mvwprintw(win,5,2,"#    ");
      mvwprintw(win,6,2,"#    ");
      mvwprintw(win,7,3,"###  ");
      break;        
  }  
  return;
}
 
/* Sub-rotina que controla o digito da direita nas horas */
void desenha_hrDD(WINDOW *win, int hr)
{    
       
  switch(hr)
  {            
    case 0:                  
      mvwprintw(win,1,12,"###");
      mvwprintw(win,2,11,"#   #");
      mvwprintw(win,3,11,"#   #   #");
      mvwprintw(win,4,11,"    ");
      mvwprintw(win,5,11,"#   #");
      mvwprintw(win,6,11,"#   #   #");
      mvwprintw(win,7,12,"###");
      break;
     
    case 1:
      mvwprintw(win,1,12,"   #");      
      mvwprintw(win,2,11," ");
      mvwprintw(win,3,11," ");
      mvwprintw(win,4,11," ");
      mvwprintw(win,5,11," ");
      mvwprintw(win,6,11," ");
      mvwprintw(win,7,12,"   #");      
      break;      
           
    case 2:
      mvwprintw(win,1,12,"###  ");
      mvwprintw(win,4,12,"###");
      mvwprintw(win,5,11,"#    ");
      mvwprintw(win,6,11,"#    ");
      mvwprintw(win,7,12,"###  ");
      break;
     
    case 3:        
      mvwprintw(win,4,12,"###");
      mvwprintw(win,5,11,"    #");      
      mvwprintw(win,6,11,"    #");
      break;
    }
  return;          
}
 
/* Subrotina para controle do digito da esquerda nos minutos */
void desenha_minDE(WINDOW *win, int min)
{
  switch(min)
  {
    case 0:
      mvwprintw(win,1,23,"###");
      mvwprintw(win,2,22,"#   #");
      mvwprintw(win,3,22,"#   #");
      mvwprintw(win,4,22,"    ");
      mvwprintw(win,5,22,"#   #");
      mvwprintw(win,6,22,"#   #");
      mvwprintw(win,7,23,"###");  
      break;
 
    case 1:
      mvwprintw(win,1,23,"   #");      
      mvwprintw(win,2,22," ");
      mvwprintw(win,3,22," ");
      mvwprintw(win,4,22," ");
      mvwprintw(win,5,22," ");
      mvwprintw(win,6,22," ");
      mvwprintw(win,7,23,"   #");
      break;    
 
    case 2:
      mvwprintw(win,1,23,"###  ");
      mvwprintw(win,4,23,"###");
      mvwprintw(win,5,22,"#    ");
      mvwprintw(win,6,22,"#    ");
      mvwprintw(win,7,23,"###  ");
      break;
     
    case 3:        
      mvwprintw(win,4,23,"###");
      mvwprintw(win,5,22,"    #");      
      mvwprintw(win,6,22,"    #");
      break;
       
    case 4:
      mvwprintw(win,1,22,"#   #");
      mvwprintw(win,2,22,"#");
      mvwprintw(win,3,22,"#");
      mvwprintw(win,4,23,"###");  
      mvwprintw(win,7,22,"    #");
      break;
     
    case 5:
      mvwprintw(win,1,22," ### ");
      mvwprintw(win,2,25,"  ");
      mvwprintw(win,3,25,"  ");
      mvwprintw(win,5,22," ");
      mvwprintw(win,6,22," ");
      mvwprintw(win,7,22," ### ");
      break;
  
    case 6:
      mvwprintw(win,5,26,"#");
      mvwprintw(win,6,26,"#");
      break;
     
    case 7:        
      mvwprintw(win,2,26,"#");
      mvwprintw(win,3,26,"#");
      mvwprintw(win,4,22,"    ");
      mvwprintw(win,5,22," ");
      mvwprintw(win,6,22," ");
      mvwprintw(win,7,22,"    #");
      break;
     
    case 8:
      mvwprintw(win,4,23,"###");
      mvwprintw(win,5,22,"#");
      mvwprintw(win,6,22,"#");
      mvwprintw(win,7,23,"### ");
      break;
     
    case 9:
      mvwprintw(win,5,22," ");
      mvwprintw(win,6,22," ");
      break;      
  }
  return;
}
 
/* Sub-rotina para controle do digito da direita nos minutos */
void desenha_minDD(WINDOW *win, int min)
{
  switch(min)
  {
    case 0:
      mvwprintw(win,1,31,"###");
      mvwprintw(win,2,30,"#   #");
      mvwprintw(win,3,30,"#   #  #");
      mvwprintw(win,4,30,"    ");
      mvwprintw(win,5,30,"#   #");
      mvwprintw(win,6,30,"#   #  #");
      mvwprintw(win,7,31,"###");  
      break;
 
    case 1:
      mvwprintw(win,1,31,"   #");      
      mvwprintw(win,2,30," ");
      mvwprintw(win,3,30," ");
      mvwprintw(win,4,30," ");
      mvwprintw(win,5,30," ");
      mvwprintw(win,6,30," ");
      mvwprintw(win,7,31,"   #");
      break;    
 
    case 2:
      mvwprintw(win,1,31,"###  ");
      mvwprintw(win,4,31,"###");
      mvwprintw(win,5,30,"#    ");
      mvwprintw(win,6,30,"#    ");
      mvwprintw(win,7,31,"###  ");
      break;
     
    case 3:        
      mvwprintw(win,4,31,"###");
      mvwprintw(win,5,30,"    #");      
      mvwprintw(win,6,30,"    #");
      break;
       
    case 4:
      mvwprintw(win,1,30,"#   #");
      mvwprintw(win,2,30,"#");
      mvwprintw(win,3,30,"#");
      mvwprintw(win,4,31,"###");  
      mvwprintw(win,7,30,"    #");
      break;
     
    case 5:
      mvwprintw(win,1,30," ### ");
      mvwprintw(win,2,33,"  ");
      mvwprintw(win,3,33,"  ");
      mvwprintw(win,5,30," ");
      mvwprintw(win,6,30," ");
      mvwprintw(win,7,30," ### ");
      break;
  
    case 6:
      mvwprintw(win,5,30,"#");
      mvwprintw(win,6,30,"#");
      break;
     
    case 7:        
      mvwprintw(win,2,34,"#");
      mvwprintw(win,3,34,"#");
      mvwprintw(win,4,30,"    ");
      mvwprintw(win,5,30," ");
      mvwprintw(win,6,30," ");
      mvwprintw(win,7,30,"    #");
      break;
     
    case 8:
      mvwprintw(win,4,31,"###");
      mvwprintw(win,5,30,"#");
      mvwprintw(win,6,30,"#");
      mvwprintw(win,7,31,"### ");
      break;
     
    case 9:
      mvwprintw(win,5,30," ");
      mvwprintw(win,6,30," ");
      break;      
  }
  return;
}
 
/* Sub-rotina para controle do digito da esquerda nos segundos */
void desenha_segDE(WINDOW *win, int seg)
{
  switch(seg)
  {
    case 0:
      mvwprintw(win,1,43,"###");
      mvwprintw(win,2,42,"#   #");
      mvwprintw(win,3,42,"#   #");
      mvwprintw(win,4,42,"    ");
      mvwprintw(win,5,42,"#   #");
      mvwprintw(win,6,42,"#   #");
      mvwprintw(win,7,43,"###");  
      break;
 
    case 1:
      mvwprintw(win,1,43,"   #");      
      mvwprintw(win,2,42," ");
      mvwprintw(win,3,42," ");
      mvwprintw(win,4,42," ");
      mvwprintw(win,5,42," ");
      mvwprintw(win,6,42," ");
      mvwprintw(win,7,43,"   #");
      break;    
 
    case 2:
      mvwprintw(win,1,43,"###  ");
      mvwprintw(win,4,43,"###");
      mvwprintw(win,5,42,"#    ");
      mvwprintw(win,6,42,"#    ");
      mvwprintw(win,7,43,"###  ");
      break;
     
    case 3:        
      mvwprintw(win,4,43,"###");
      mvwprintw(win,5,42,"    #");      
      mvwprintw(win,6,42,"    #");
      break;
       
    case 4:
      mvwprintw(win,1,42,"#   #");
      mvwprintw(win,2,42,"#");
      mvwprintw(win,3,42,"#");
      mvwprintw(win,4,43,"###");  
      mvwprintw(win,7,42,"    #");
      break;
     
    case 5:
      mvwprintw(win,1,42," ### ");
      mvwprintw(win,2,45,"  ");
      mvwprintw(win,3,45,"  ");
      mvwprintw(win,5,42," ");
      mvwprintw(win,6,42," ");
      mvwprintw(win,7,42," ### ");
      break;
  
    case 6:
      mvwprintw(win,5,42,"#");
      mvwprintw(win,6,42,"#");
      break;
     
    case 7:        
      mvwprintw(win,2,46,"#");
      mvwprintw(win,3,46,"#");
      mvwprintw(win,4,42,"    ");
      mvwprintw(win,5,42," ");
      mvwprintw(win,6,42," ");
      mvwprintw(win,7,42,"    #");
      break;
     
    case 8:
      mvwprintw(win,4,43,"###");
      mvwprintw(win,5,42,"#");
      mvwprintw(win,6,42,"#");
      mvwprintw(win,7,43,"### ");
      break;
     
    case 9:
      mvwprintw(win,5,42," ");
      mvwprintw(win,6,42," ");
      break;      
  }
  return;
}
 
/* Sub-rotina que controla o digito da direita nos segundos */
void desenha_segDD(WINDOW *win, int seg)
{
  switch(seg)
  {
    case 0:
      mvwprintw(win,1,51,"###");
      mvwprintw(win,2,50,"#   #");
      mvwprintw(win,3,50,"#   #");
      mvwprintw(win,4,50,"    ");
      mvwprintw(win,5,50,"#   #");
      mvwprintw(win,6,50,"#   #");
      mvwprintw(win,7,51,"###");  
      break;
 
    case 1:
      mvwprintw(win,1,51,"   #");      
      mvwprintw(win,2,50," ");
      mvwprintw(win,3,50," ");
      mvwprintw(win,4,50," ");
      mvwprintw(win,5,50," ");
      mvwprintw(win,6,50," ");
      mvwprintw(win,7,51,"   #");
      break;    
 
    case 2:
      mvwprintw(win,1,51,"###  ");
      mvwprintw(win,4,51,"###");
      mvwprintw(win,5,50,"#    ");
      mvwprintw(win,6,50,"#    ");
      mvwprintw(win,7,51,"###  ");
      break;
     
    case 3:        
      mvwprintw(win,4,51,"###");
      mvwprintw(win,5,50,"    #");      
      mvwprintw(win,6,50,"    #");
      break;
       
    case 4:
      mvwprintw(win,1,50,"#   #");
      mvwprintw(win,2,50,"#");
      mvwprintw(win,3,50,"#");
      mvwprintw(win,4,51,"###");  
      mvwprintw(win,7,50,"    #");
      break;
     
    case 5:
      mvwprintw(win,1,50," ### ");
      mvwprintw(win,2,53,"  ");
      mvwprintw(win,3,53,"  ");
      mvwprintw(win,5,50," ");
      mvwprintw(win,6,50," ");
      mvwprintw(win,7,50," ### ");
      break;
  
    case 6:
      mvwprintw(win,5,50,"#");
      mvwprintw(win,6,50,"#");
      break;
     
    case 7:        
      mvwprintw(win,2,54,"#");
      mvwprintw(win,3,54,"#");
      mvwprintw(win,4,50,"    ");
      mvwprintw(win,5,50," ");
      mvwprintw(win,6,50," ");
      mvwprintw(win,7,50,"    #");
      break;
     
    case 8:
      mvwprintw(win,4,51,"###");
      mvwprintw(win,5,50,"#");
      mvwprintw(win,6,50,"#");
      mvwprintw(win,7,51,"### ");
      break;
     
    case 9:
      mvwprintw(win,5,50," ");
      mvwprintw(win,6,50," ");
      break;      
  }
  return;
}
