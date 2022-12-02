#include <iostream>
#include <cmath>
using namespace std;
int main(){
	long k,a,b,d,v,x;
	cin >> k >> a >> b;
	
	long nazdika=a%k;
	if (nazdika<0){nazdika+=k;	}
	
	if(nazdika<= (k/2) )       //chap nazdiktare
	{d= a-nazdika; 	}
	
	else if(nazdika> (k/2))      //rast nazdiktare
	{d= (a+k)-nazdika; 	}
//-------------------------------------------------------------
long nazdikb=b%k;
	if (nazdikb<0){nazdikb+=k;	}
	if(nazdikb<= (k/2) )       //chap nazdiktare
	{v=b-nazdikb;	 }
	
	else if(nazdikb> (k/2))      //rast nazdiktare
	{v= (b+k)-nazdikb; 	}
//-------------------------------------------------------------
x =(v-d)/k;
if (x<0){x=-x;}
long minute=((nazdika + nazdikb)+x);

if(b-a<minute){cout <<b-a; return 0;}

else {cout << minute;}
}
