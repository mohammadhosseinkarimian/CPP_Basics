using namespace std;
#include <iostream>

int main()
{

	int a  = 0;
	int b =0;
	int sum = 1;
	cin >> a;
	cin >> b;
	for(int i =0;i<b;i++)
	{
		sum *= a;
	}
	cout<< sum;
	return 0;
	
}


