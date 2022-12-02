#include <iostream>
#include <math.h>
#include <iomanip>                                              
using namespace std; 
                                                                                        // i=n . x=rad


long long factorial(long n){    long long a=1; 
        for(int i=1 ; i<=n;i++){ a*= i;		}   return a;}

double Cos (double teta){  

	double x = 0;
	double cos=0 ;x = teta*(3.14)/180 ;for (int i=0;i<=10;i++)	{cos += (pow(-1,i)*pow(x,2*i))/factorial(2*i) ;}
	return cos ;

}
   

int main(){
	double f,d,teta;
	cin>>f>>d>>teta; 
	double w = ((f*d)* Cos(teta));
	cout<<fixed << setprecision(2) <<w;
	return 0;
}
