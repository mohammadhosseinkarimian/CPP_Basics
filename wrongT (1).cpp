#include <iostream>
#include<string>
using namespace std;
int main()
{
    string n,a;
    getline(cin,n);
    string c="";
    int counter=0 ,k=0;
    int capcount =0;
    for(int i=0;i<n.length();i++){
        if(n[i]=='a'||n[i]=='e' ||n[i]=='o'||n[i]=='i'||n[i]=='u'||n[i]=='y'){
        	c+= n[i];
			if(counter < 5)
			{
				counter = 0;
			} 
			}
        else{
            if((n[i]>='a' && n[i]<='z')  ){
                counter++;
                c+=n[i];
                }
            else if((n[i]>='A' && n[i]<='Z'))
            {
            	c+=n[i];
            	counter++;
            	capcount++;
			}
            else if(n[i]==' '){ 
                if(counter>4 && counter > capcount ){
                	                	
                	
                    cout << c << " " ;
                    k=0;
                    counter=0;
					}
					capcount =0;
                    k=0;
                    counter=0; 
					c = "";
				
					}
					
					}}
        return 0;}
