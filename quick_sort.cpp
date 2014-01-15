#include<iostream>

using namespace std;

int partition(int arr[], int l, int h)
{
	int piv=arr[l];
	int i, j;
	for(i=l+1, j=l+1; i<=h && j<=h;)
	{
		if(arr[j]>piv)
			j++;
		else
		{
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}
	swap(arr[i-1], arr[l]);
	return i-1;
}

void quicksort(int arr[], int l, int h)
{
	if(l>h)
		return;

	int p=partition(arr, l, h);
	quicksort(arr, l, p-1);
	quicksort(arr, p+1, h);
}

int main()
{
	int arr[]={4, 7, 30, 2, 52, 12, 30, 9, 34, 22, 1, 2};
	int n=sizeof(arr)/sizeof(arr[0]);

	quicksort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}
