#include <iostream>
using namespace std;

int main()
{
    long k, a, b;
	long final = 0;
	long swap , x , y , a_close, b_close;
	double middle;
    cin >> k >> a >> b;
    if(a>b) {
        swap = a;
        a = b;
        b = swap;
    }

    if(a % k < 0)
	{
	  x = a%k + k;
    }
    else
    {
    	x = a%k;
	} 
    if(b % k < 0)
	{
	 y = b % k + k;
	}
	else
	{
		y = b % k;
	}

    middle = k / 2.0;
    if(x<middle)
    {
    a_close = a - x;
    final += x;
	}
    else{
        a_close = a - x + k;
        final += k - x;
    }
  
    if (y <= middle){
       b_close = b - y;

       final += y;
        
    }
    else{
        b_close = b -y + k;
        final += k - y;

    }
	  
    final += (b_close - a_close) / k; 
    cout <<  min(final, b - a);

    return 0;
}

