
using namespace std;
#include <iostream>
#include <stdlib.h>

int main( )
{

unsigned seed;
while(1)
{
cout <<"Enter seed value : " ;
cin >> seed ;
srand(seed) ;
for(int j=1 ; j<=10 ; ++j)
cout << rand( ) << "\n";
}

return 0 ;
}


