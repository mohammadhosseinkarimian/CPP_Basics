#include <iostream>
#include <string>

using namespace std;

int isCorrect(string str);


int main(){

    string str = "";
    string nstr = "";
    getline(cin, str);
    for(int i = 0; i<str.size();i++)
	{
        if( str[i] != ' ' && ispunct(str[i]) == false)
        {
        	char a = tolower(str[i]);
			nstr += a;
		}
    }
    int isc = isCorrect(nstr);
    if(isc == 1)
    {
    	cout << "YES";
	}
	else
	{
		cout << "NO" ;
	}
}

int isCorrect(string str){
    if(str.size() < 2)
        return 1;
    else if(str[0] != str[str.size()-1])
        {
			return 0;
		}
    else
    
	{
	    return isCorrect(str.substr(1, str.size()-2));
	}
}
