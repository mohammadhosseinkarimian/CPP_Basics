using namespace std;
#include <iostream>
int main()
{
unsigned int n;
cout<<"enter 1 to connect to technical departement"<<"\n";
cout<<"enter 2 to pay the bill "<<"\n";
cout<<"enter 3 to connect to the operator"<<"\n";
cout<<"or enter any other letter to end the process"<<"\n";
while(1)
{
cin >> n;
if (n!=1 && n!=2 && n!=3)
{
	break;
}
switch(n)
{
case 1:
cout << "You are connected to technical departement"<< endl;
cout << "Choose your next servise or enter any other letter to end the process"<< endl;
break;


case 2:
cout << "You are connected to the operator"<< endl;
cout << "Choose your next servise or enter any other letter to end the process"<< endl;
break;

case 3:
cout << "You have paid the bill successfuly"<<endl;
cout << "Choose your next servise or enter any other letter to end the process"<< endl;

break;

default:
cout << "The process is finished."<< endl;
break;
}
}
cout<<"see u later"<<"\n";
}
