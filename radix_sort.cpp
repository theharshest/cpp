//Radix Sort

#include<iostream>
#include<queue>

using namespace std;

void radix_sort(int arr[], int n)
{
	queue<int> buck[10];

	for(int i=0; i<n; i++)
	{
		int b=arr[i]%10;
		buck[b].push(arr[i]);
	}

	for(int i=0, j=0; i<n && j<10; j++)
	{
		while(!buck[j].empty())
		{
			arr[i]=buck[j].front();
			buck[j].pop();
			i++;
		}
	}

	for(int i=0; i<n; i++)
	{
		int b=arr[i]/10;
		buck[b].push(arr[i]);
	}

	for(int i=0, j=0; i<n && j<10; j++)
	{
		while(!buck[j].empty())
		{
			arr[i]=buck[j].front();
			buck[j].pop();
			i++;
		}
	}
}

int main()
{
	int arr[]={23, 93, 10, 3, 99, 2, 23, 44, 9};
	int n=sizeof(arr)/sizeof(arr[0]);

	radix_sort(arr, n);

	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}
