#include <stdio.h>
#include <stdlib.h>

int main(){
	int num1, num2, op;
	char oper;
	printf("\t\t\tNo dejar espacios entre los terminos");
	do{
    	do{
    	   printf("\n\n\t\t1 : Realizar una operacion");
           printf("\n\t\t2 : Salir");	
           printf("\n\n\tOpcion : "), scanf("%d", &op);
        }while(op < 1 && op > 2);
        if(op == 1)
        {
           printf("\n\n\t\t\tIntroduce tu operacion : ");
       	   scanf("%d%c%d", &num1, &oper, &num2);
           printf("\n\n\t\t\tEl resultado es : ");
           switch (oper){
                  case '+':
                       printf("%d\n\n", num1 + num2);
                  break;
            		 
                  case '-':
                      printf("%d\n\n", num1 - num2);
                  break;
            		
                  case '*':
               	  	  printf("%d\n\n", num1 * num2);
                  break;
            		
                  case '/':
               	  	  printf("%d\n\n", num1 / num2);
                  break;
              }
          	  getch();
        }
     }while(op != 2);
	return 0;
}
