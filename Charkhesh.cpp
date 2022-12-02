#include <iostream>
using namespace std;

int main()
{
    long n, W = 0;
    long long A[200000];
    cin >> n;
    for (long i = 0; i < n; i = i + 1)
    {
        cin >> A[i];
    }
    for (int j = 0; j < n - 1; j = j + 1)
    {
        for (int i = j + 1; i < n; i = i + 1)
        {
            if (A[i] < A[j]) W = W + 1;
        }
    }
    cout << W % 100000;
    return 0;
}

