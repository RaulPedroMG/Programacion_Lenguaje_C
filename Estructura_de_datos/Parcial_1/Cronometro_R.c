#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
//#include ENTER 10
//#define msg "                   ============ CRONOMETRO DIGITAL =========="
//#define aut "\n                      .**o._.o**. By Tarik Ahmad.**o._.o**."
 
/* Cabecalhos */
void desenha_hrDE(int hr);
void desenha_hrDD(int hr);
void desenha_minDE(int min);
void desenha_minDD(int min);
void desenha_segDE(int seg);
void desenha_segDD(int seg);
//void Salir(int *parar);

int main(void)
{
  /* Declarando as variáveis */  
  int hora,min,seg,qh,rh,qm,rm,qs,rs;
  //char salir[] = "si";
  //WINDOW *wstd, *wborder;
  //int i;
  //int u = 0;
     
  /* Inicializando variáveis */
  hora = 0, min = 0, seg = 0;
   
  /* Inicializando modo grafico com curses.h */
  (void)initscr();  
  //wstd = newwin(2,12,3,10);
  //wborder = newwin(7,18,2,8);
  start_color();
  //init_pair(1,COLOR_BLACK,COLOR_RED);
  //init_pair(2,COLOR_BLUE,COLOR_YELLOW);
  init_pair(3,COLOR_BLACK,COLOR_WHITE);
  //init_pair(4,COLOR_YELLOW,COLOR_BLUE);
  //init_pair(5,COLOR_BLACK,COLOR_WHITE);
  //init_pair(6,COLOR_RED,COLOR_BLACK);
  //init_pair(7,COLOR_YELLOW,COLOR_YELLOW);
  //init_pair(8,COLOR_WHITE,COLOR_BLACK);
  //wbkgd(wstd,COLOR_PAIR(8) | A_BOLD | A_BLINK);
  //wbkgd(wborder,COLOR_PAIR(3) | A_BLINK);
  curs_set(0); /* Desabilitando o cursor do mouse */
  system("CLS");
  //puts(msg);
  //puts(aut);
  sleep(1);
         
  while (hora < 5)
  {
    while (min < 60) 
    {
      while (seg < 60)
      {
        //wrefresh(wborder);  
        //wrefresh(wstd);
		refresh();         
        /* Calculo para segundos */        
        qs = seg / 10;
        rs = seg % 10;
        desenha_segDE(qs);
        desenha_segDD(rs);
         
        /* Calculo para minutos */
        qm = min / 10;
        rm = min % 10;
        desenha_minDE(qm);
        desenha_minDD(rm);  
         
         
        /* Calculo para horas */
        qh = hora / 10;
        rh = hora % 10;
        desenha_hrDE(qh);
        desenha_hrDD(rh);  
		sleep(1);
		seg = seg + 1;        		 
		//Salir(&salir);     
      }              
      seg = 0; /* Resetando segundo */
      min = min + 1; /* Incrementando minuto */
    }    
    min = 0;
    hora = hora + 1; /* Incrementando hora */         
    /* Reseta hora para que o loop seja continuo */
    //if (hora > 23)
    //{
    //  hora = 0;
    //}    
  }
  endwin(); /* Finalizando modo curses */
  return (0);
}



void Salir(int *parar)
{
    mvscanw(3,1,"%d",&parar);
    echo();
	refresh();
} 
 
 
/* Sub-rotina que controla o digito da direita nos segundos */
void desenha_segDD(int seg)
{
  switch(seg)
  {
    case 0:
      mvprintw(1,9,"%d",seg);
      break;
 
    case 1:
      mvprintw(1,9,"%d",seg);
      break;    
 
    case 2:
      mvprintw(1,9,"%d",seg);
      break;
     
    case 3:        
      mvprintw(1,9,"%d",seg);
      break;
       
    case 4:
      mvprintw(1,9,"%d",seg);
      break;
     
    case 5:
      mvprintw(1,9,"%d",seg);
      break;
  
    case 6:
      mvprintw(1,9,"%d",seg);
      break;
     
    case 7:        
      mvprintw(1,9,"%d",seg);
      break;
     
    case 8:
      mvprintw(1,9,"%d",seg);
      break;
     
    case 9:
      mvprintw(1,9,"%d",seg);
      break;      
  }
  return;
}

/* Sub-rotina para controle do digito da esquerda nos segundos */
void desenha_segDE(int seg)
{
  switch(seg)
  {
    case 0:
      mvprintw(1,7,":%d",seg);  
      break;
 
    case 1:
      mvprintw(1,7,":%d",seg);
      break;    
 
    case 2:
      mvprintw(1,7,":%d",seg);
      break;
     
    case 3:        
      mvprintw(1,7,":%d",seg);
      break;
       
    case 4:
      mvprintw(1,7,":%d",seg);
      break;
     
    case 5:
      mvprintw(1,7,":%d",seg);
      break;
  
    case 6:
      mvprintw(1,7,":%d",seg);
      break;
     
    case 7:        
      mvprintw(1,7,":%d",seg);
      break;
     
    case 8:
      mvprintw(1,7,":%d",seg);
      break;
     
    case 9:
      mvprintw(1,7,":%d",seg);
      break;      
  }
  return;
}

/* Sub-rotina para controle do digito da direita nos minutos */
void desenha_minDD(int min)
{
  switch(min)
  {
    case 0:
      mvprintw(1,6,"%d",min);  
      break;
 
    case 1:
      mvprintw(1,6,"%d",min);
      break;    
 
    case 2:
      mvprintw(1,6,"%d",min);
      break;
     
    case 3:        
      mvprintw(1,6,"%d",min);
      break;
       
    case 4:
      mvprintw(1,6,"%d",min);
      break;
     
    case 5:
      mvprintw(1,6,"%d",min);
      break;
  
    case 6:
      mvprintw(1,6,"%d",min);
      break;
     
    case 7:        
      mvprintw(1,6,"%d",min);
      break;
     
    case 8:
      mvprintw(1,6,"%d",min);
      break;
     
    case 9:
      mvprintw(1,6,"%d",min);
      break;      
  }
  return;
}

/* Subrotina para controle do digito da esquerda nos minutos */
void desenha_minDE(int min)
{
  switch(min)
  {
    case 0: 
      mvprintw(1,4,":%d",min);
      break;
 
    case 1:
      mvprintw(1,4,":%d",min);
      break;    
 
    case 2:
      mvprintw(1,4,":%d",min);
      break;
     
    case 3:        
      mvprintw(1,4,":%d",min);
      break;
       
    case 4:
      mvprintw(1,4,":%d",min);
      break;
     
    case 5:
      mvprintw(1,4,":%d",min);
      break;
  
    case 6:
      mvprintw(1,4,":%d",min);
      break;
     
    case 7:        
      mvprintw(1,4,":%d",min);
      break;
     
    case 8:
      mvprintw(1,4,":%d",min);
      break;
     
    case 9:
      mvprintw(1,4,":%d",min);
      break;      
  }
  return;
}

/* Sub-rotina que controla o digito da esquerda nas horas */
void desenha_hrDE(int hr)
{
  switch(hr)
  {    
    case 0:
      mvprintw(1,3,"%d",hr);  
      break;
         
    case 1:
      mvprintw(1,3,"%d",hr);
      break;
 
    case 2:
      mvprintw(1,3,"%d",hr);
      break;
      
    case 3:
      mvprintw(1,3,"%d",hr);
      break;
    
    case 4:
      mvprintw(1,3,"%d",hr);
      break;
    
    case 5:
      mvprintw(1,3,"%d",hr);
      break;
    
    case 6:
      mvprintw(1,3,"%d",hr);
      break;
      
    case 7:
      mvprintw(1,3,"%d",hr);
      break;
      
    case 8:
      mvprintw(1,3,"%d",hr);
      break;
      
    case 9:
      mvprintw(1,3,"%d",hr);
      break;        
  }  
  return;
}
 
/* Sub-rotina que controla o digito da direita nas horas */
void desenha_hrDD(int hr)
{    
       
  switch(hr)
  {            
    case 0:                  
      mvprintw(1,2,"%d",hr);
      break;
     
    case 1:
      mvprintw(1,2,"%d",hr);      
      break;      
           
    case 2:
      mvprintw(1,2,"%d",hr);
      break;
     
    case 3:        
      mvprintw(1,2,"%d",hr);
      break;
    }
  return;          
}
