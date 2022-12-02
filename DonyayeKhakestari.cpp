#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char chap[n], rast[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>chap[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>rast[i];
	}
	int cnt=0;
	for(int i=0;i<n-2;i++)
	{
		if(chap[i]=='_'&&chap[i+1]=='_'&&chap[i+2]=='_')
		{
			cnt++;
			i+2;
		}
	}
	for(int i=0;i<n-2;i++)
	{
		if(rast[i]=='_'&&rast[i+1]=='_'&&rast[i+2]=='_')
		{
			cnt++;
			i+2;
		}
	}
	cout<<cnt;
}

