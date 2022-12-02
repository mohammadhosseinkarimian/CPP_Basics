#include <iostream>
using namespace std;
int main()
{
    long F[5];
    for (int i = 0; i < 5; i = i + 1)
    {
        char A;
        cin >> A;
        long a = A - 64;
        F[i] = a;
    }
    for (int i = 0; i < 5; i = i + 1)
    {
        cout << F[i];
    }
    return 0;
}

