#include <iostream>
using namespace std;

int main(){

    int n, i ,j, k;
    int grades[400];

    // khandane vorudi
    cin >>n;
    for (i=0; i<n; i++){
        cin >> grades[i];
    }
    cin >> k;
    k %= n; // chon masalan charkhesh be andaze n+1 ba charkhesh be andaze 1 barabare

    // raveshe 1 (temp array)
    int newGrades[400];
    for(i=0; i<n; i++)
        newGrades[i] = grades[(i + k) % n]; // baghimande migirim chon i+k akhare array bargarde be avale array

    for(i=0; i<n; i++)
        cout << newGrades[i] << " ";

    return 0;
}
