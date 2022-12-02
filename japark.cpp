#include <iostream>
#include <string>

using namespace std;

int main(){
    int n ,cntr , las;
    char chr;
    cin >> n;

    for(int row = 0; row<=1; row++)
	{
        cntr = 0;
        int i =0;
        while(i < n)
		{
            cin >> chr;
            if(chr != '_')
                cntr = 0;
            else
                cntr += 1;
            if(cntr==3)
			{
            	cntr=0;
                las++;
            }
            i++ ;
        }
    }
    cout<<las ;
}
