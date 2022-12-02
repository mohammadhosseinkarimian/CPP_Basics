#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	string inp;
	int n,cntr =0; 
	cin>>n;
	cin>>str>>inp;
	
	for(int i=0;i<n;++i){
		
		if(inp[i] != str[i])
		{	
			cntr+=1;
		}
	}
	cout<<cntr;
	return 0;
}
