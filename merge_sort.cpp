// Merge sort

#include<iostream>

using namespace std;

void merge(int arr[], int l, int mid, int h)
{
	int n1=mid-l+1;
	int n2=h-mid;

	int* arr1 = new int[n1];
	int* arr2 = new int[n2];

	int i, j;

	for(i=0; i<n1; i++)
		arr1[i]=arr[l+i];

	for(j=0; j<n2; j++)
		arr2[j]=arr[mid+1+j];

	for(i=0, j=0; i<n1 && j<n2;)
	{
		if(arr1[i]<arr2[j])
		{
			arr[l]=arr1[i];
			i++;
		}
		else
		{
			arr[l]=arr2[j];
			j++;
		}
		l++;
	}

	while(i<n1)
	{
		arr[l]=arr1[i];
		i++;
		l++;
	}

	while(j<n2)
	{
		arr[l]=arr2[j];
		j++;
		l++;
	}
}

void merge_sort(int arr[], int l, int h)
{
	if(l<h)
	{
		int mid = l + (h-l)/2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, h);
		merge(arr, l, mid, h);
	}
}

int main()
{
	int arr[]={12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	merge_sort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}
