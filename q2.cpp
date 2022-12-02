#include<iostream>
using namespace std;



int main(){
  string input;
  cin >> input;
  
  int start, end;
  cin >> start >> end;
  
  for(int i = 0; i < input.length(); i++){
    if(i >= start && i <= end){
      cout<<input[i];
    }
  }  
}
