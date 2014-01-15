#include<iostream>

using namespace std;

void max_heapify(int arr[], int k, int n)
{
	int maxi=k;
	if(2*k<n && arr[2*k]>arr[k])
		maxi=2*k;
	if(2*k+1<n && arr[2*k+1]>arr[maxi])
		maxi=2*k+1;
	if(maxi!=k)
	{
		swap(arr[k], arr[maxi]);
		max_heapify(arr, maxi, n);
	}
}

void build_max_heap(int arr[], int n)
{
	for(int i=n/2; i>=0; i--)
	{
		max_heapify(arr, i, n);
	}
}

void heap_sort(int arr[], int n)
{
	build_max_heap(arr, n);
	for(int i=1; i<n; i++)
	{
		swap(arr[0], arr[n-i]);
		max_heapify(arr, 0, n-i-1);
	}
}

int main()
{
	int arr[]={4, 7, 30, 2, 52, 12, 30, 9, 34, 22, 1, 2};
	int n=sizeof(arr)/sizeof(arr[0]);

	heap_sort(arr, n);

	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}
