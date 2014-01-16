// Longest Increasing Subsequence in an array
#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int* lis(int arr[], int n)
{
	int *aux = new int[n];

	for(int i=0; i<n; i++)
		aux[i] = 0;

	aux[0] = 1;

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[i]>arr[j])
				aux[i] = max(aux[i], aux[j] + 1);
		}
	}

	return aux;
}

int main()
{
	int arr[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n=sizeof(arr)/sizeof(arr[0]);
	int *aux = lis(arr, n);
	list<int> res;

	int k = *max_element(aux, aux+n);

	for(int i=n-1; i>=0; i--)
	{
		if(aux[i]==k)
		{
			res.push_front(arr[i]);
			k--;
		}
	}

	list<int>::iterator it = res.begin();

	for(; it!=res.end(); it++)
		cout<<(*it)<<" ";
}
