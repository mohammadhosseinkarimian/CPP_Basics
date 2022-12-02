#include <iostream>
using namespace std;
int main()
{
    long  n,b,a=1; 
    cin>>n;
    if (n==1)
    {cout<<"1";}
    else{
    for(int i=2 ;i<=n;i++){
        a=a*i;
        while(a%10==0){
            a=a/10;
        }
        a=a%10000; }
        cout<<a%10; }
    return 0;
}
