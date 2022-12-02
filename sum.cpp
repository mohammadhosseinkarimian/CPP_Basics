#include <iostream>

using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main()
{
	int arr[10];
	for (int k =0;k<10;k++)
	{
		cin >> arr[k];

	}
	
	int i, j; 
    for (j = 0; j < 9-i; j++) 
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
            
	for (int z = 0; z < 10; z++) 
        cout << arr[z] << " "; 
    cout << endl; 
	return 0;
	
} 

	
	

