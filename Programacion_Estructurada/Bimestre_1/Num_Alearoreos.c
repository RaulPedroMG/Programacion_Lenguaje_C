#include<stdlib.h>
#include<iostream.h>
using namespace std;
 
int main()
{
    int num,c;
    srand(time(NULL));
    for(c=1;c<=10;c++)
    {
        num=1+rand()%(11-1);
        cout<<num<<" ";
    }
    cin.get();
}
