#include <iostream>
#include <string>

using namespace std;

int main ()
{
	int n , time , mid,final, sum = 0 ;
    cin >> n;
    int col [n];
    
    for (int i = 0; i < n; i++)
    {
    	int a ;
        cin >> a;
        col [i] = a;
        sum += col [i];       
    }
    mid = sum/n;
    for (int i = 0; i < n; i++)
    {
    	int x = mid - col [i];
    	time+= abs(mid-col[i]);

	}
	final = time/2;
    cout << time/2;

}
