#include <i o s t r e a m >
#include ” FreeImage . h”
#define WIDTH 800
#define HEIGHT 600
#define BPP 24 // S i n c e we ’ r e o u t p u t t i n g t h r e e 8 b i t RGB v a l u e s
using namespace s t d ;
int main ( int argc , char ∗ argv [ ] ) {
	FreeImage Initialise ();
	FIBITMAP∗ bitmap = F r e e I m a g e A l l o c a t e (WIDTH, HEIGHT, BPP ) ;
	RGBQUAD c o l o r ;
	i f ( ! bitmap )
		e x i t ( 1 ) ; //WTF? ! We can ’ t even a l l o c a t e images ? Die !
//Draws a g r a d i e n t from b l u e t o g r e e n :
	f o r ( int i =0; i <WIDTH; i ++) {
		f o r ( int j =0; j <HEIGHT; j ++) {
			c o l o r . rgbRed = 0 ;
			c o l o r . rgbGreen = ( double ) i / WIDTH ∗ 2 5 5 . 0 ;
			c o l o r . rgbBlue = ( double ) j / HEIGHT ∗ 2 5 5 . 0 ;
			F r e e I m a g e S e t P i x e l C o l o r ( bitmap , i , j ,& c o l o r ) ;
// N o t i c e how we ’ r e c a l l i n g t h e & o p e r a t o r on ” c o l o r ”
// so t h a t we can p a s s a p o i n t e r t o t h e c o l o r s t r u c t .
		}
	}
	i f ( FreeImage Save ( FIF PNG , bitmap , ” t e s t . png” , 0 ) )
		c o u t << ” Image s u c c e s s f u l l y saved ! ” << e n d l ;
	F r e e I m a g e D e I n i t i a l i s e ( ) ; // Cleanup !
}
