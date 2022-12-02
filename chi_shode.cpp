#include <iostream>
using namespace std;
int main()
{
    int array[5];
    for (int i = 0; i<5; i=i+1)
    {
        char inp;
        cin>>inp;
        array[i] = inp-64;
    }
    for (int i = 0; i<5; i = i+1)
    {
        cout << array[i];
    }
    return 0;
}

