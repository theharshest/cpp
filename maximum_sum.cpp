// Find maximum sum of a subarray in the given array
#include<iostream>
#include<algorithm>

using namespace std;

int max_sum(int arr[], int n)
{
	int* aux = new int[n];

	fill(aux, aux+n, 0);
	aux[0]=arr[0];

	for(int i=1; i<n; i++)
	{
		if(arr[i]+aux[i-1]>0)
			aux[i]=max(aux[i-1] + arr[i], arr[i]);
	}

	return *max_element(aux, aux+n);
}

int main()
{
	int arr[]={7, 2, -34, -2, 98, -21, 43, 9};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<max_sum(arr, n)<<endl;
}
