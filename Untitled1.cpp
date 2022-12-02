#include<iostream>
#include<string>
using namespace std;


// part1: function definition
int findMismatch(string s1, string s2) {
    // start by make the alphabets in both strings lower
    for (int i = 0; i < s1.length(); i++)
    s1[i] = tolower(s1[i]);
    for (int i = 0; i < s2.length(); i++)
    s2[i] = tolower(s2[i]);

   int  mismatch = 0;
    if(s1.length()!=s2.length())
    cout<<2;
    else{
    mismatch=0;
    for(int i=0;i<s1.length();i++)
	{
    	if(tolower(s1[i])!=tolower (s2[i]))
    	mismatch+=1;
	}
	if (mismatch==1)
	cout<<1;
	if (mismatch>=2)
	cout<<2;
    return mismatch;
}
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
   findMismatch(str1, str2);

    return 0;}

