#include<iostream>

using namespace std;

void perm(int a[], int k, int n)
{
	int i, t;
	if(k==n)
	{
		for(int j=0; j<=n; j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(i=k; i<=n; i++)
		{
			t = a[i]; a[i] = a[k]; a[k] = t;
			perm(a, k+1, n);
			t = a[i]; a[i] = a[k]; a[k] = t;
		}
	}
}

int main()
{
	int a[] = {1, 2, 3, 4};
	perm(a, 0, 3);
	return 0;
}
