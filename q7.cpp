#include<iostream>
#include<math.h>
#include <iomanip>

using namespace std;

int f(int x , int y){
	int n = pow(x , 0.5);
	int m = pow(y , 0.5);
	if(n-m >=1 )
	{
		int r =pow(n , 2);
		cout << r;

		return r;
	}
	if(m-n >=1 )
	{
		int r =pow(m , 2);

		cout << r;
		return r;
	}
	return 0;
}
int main(){
	int x , y ;
	double sum;
	for(int i=1;i<=25;i++)
	{
		int first = pow(2,i);
		int second = pow(2,(i+1));
		double s = f(first , second);
		double ss = 5*f(i,i+1)+1;
		sum+= s/ss;
		
	}
	cout<<setprecision(3) << fixed << sum;
	
	
}

