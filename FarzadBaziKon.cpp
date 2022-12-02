#include <iostream>
#include <math.h>

using namespace std;

int determinent(int arr2[50][50],int ind);

int main()
{
	int n;
	
	cin >> n;
	
	int inp[50][50],arr1[50][50],C[50][50];
	
	for(int i=0;i<n;i++)
	{
		
      for(int k=0;k<n;k++)
      {
        cin>>inp[i][k]; 
   	  }
	}
    for(int i = 0;i<n;i++)
    {
      for(int k=0;k<n;k++)
      {
        cin>>arr1[i][k]; 
        C[i][k]=0;
      }
   }
    
	for (int i = 0;i < n;i++)
	{
      for (int j = 0;j < n;j++)
      {
        for (int k = 0;k < n;k++)
        {
    		C[i][j]+= arr1[k][j]*inp[i][k];
    	}
       }
   }
   
    if(determinent(C,n) % 2 == 0)
    {
    	cout << "Farzad";
	}
	else
	{
    cout << "Danial";
		
	}
}


int determinent(int arr2[50][50],int ind)
{
	int i, output = 0;
	int arr1[50][50];

	if(ind > 2)
	{
		for (i = 0;i < ind;i++)
		{
			int t = 0, j = 0;
			for (int g = 1;g < ind;g++)
			{
				for (int k = 0;k < ind;k++)
				{
					if (k != i)
					{
					arr1[t][j] = arr2[g][k];
					j++;
					if (j == ind - 1)
					{
					    j = 0;
						t++;
					}
					}
				}
			}
			int mul = pow(-1, i) * arr2[0][i] ;
			output += determinent(arr1,(ind - 1)) * mul;
		
		}
	}	
	else if (ind == 2)
	{
		output = arr2[1][1]*arr2[0][0] - arr2[1][0]*arr2[0][1] ;
		return output;
	}
	
	return output;
}
