// Iterative quick sort

#include<iostream>
#include<stack>

using namespace std;

int partition(int arr[], int l, int h)
{
	if(l>h)
		return -1;

	int piv = l;

	int i, j;
	i = piv+1;
	j = i;

	for(; i<=h && j<=h;)
	{
		if(arr[j]<=arr[piv])
		{
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}

	swap(arr[piv], arr[i-1]);

	return i-1;
}

void quicksort_iter(int arr[], int l, int h)
{
	stack< pair<int, int> > st;
	pair<int, int> tmp;

	tmp.first = l;
	tmp.second = h;

	st.push(tmp);

	while(!st.empty())
	{
		tmp = st.top();
		st.pop();
		int ll = tmp.first;
		int hh = tmp.second;

		int p = partition(arr, ll, hh);

		if(p<0)
			continue;

		if(ll<p-1)
		{
			tmp.first = ll;
			tmp.second = p-1;
			st.push(tmp);
		}

		if(p+1<hh)
		{
			tmp.first = p+1;
			tmp.second = hh;
			st.push(tmp);
		}
	}
}

int main()
{
	int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort_iter(arr, 0, n-1);

    for(int i=0; i<n; i++)
    	cout<<arr[i]<<" ";
}
