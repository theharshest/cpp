// Find maximum and minimum elements in an array
#include<iostream>
#include<limits>

using namespace std;

void max_min(int arr[], int l, int h, int& maxi, int& mini)
{
	if(l==h)
		return;

	if(h==l+1)
	{
		maxi=max(maxi, max(arr[h], arr[l]));
		mini=min(mini, min(arr[h], arr[l]));
		return;
	}
	else
	{
		int mid=(l+h)/2;
		max_min(arr, l, mid, maxi, mini);
		max_min(arr, mid+1, h, maxi, mini);
	}
}

int main()
{
	int arr[]={20, 5, 7, 25, 30, 1, 9, 12};
	int maxi, mini;
	int n=sizeof(arr)/sizeof(arr[0]);
	maxi = numeric_limits<int>::min();
	mini = numeric_limits<int>::max();
	max_min(arr, 0, n-1, maxi, mini);
	cout<<maxi<<" "<<mini;
}
