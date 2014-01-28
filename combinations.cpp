//Print all combinations of elements of an array
#include<iostream>
#include<set>
#include<vector>
#include<cmath>

using namespace std;

vector< set<int> > comb(int arr[], int n)
{
	int i=0;
	int maxi=(int)pow(2.0, float(n));

	vector< set<int> > res;

	while(i<=maxi)
	{
		int tmp1=i;
		set<int> tmp;
		for(int j=0; j<n; j++)
		{
			if(tmp1 & (1<<j))
				tmp.insert(arr[j]);
		}
		res.push_back(tmp);
		tmp.clear();
		i++;
	}

	return res;
}

int main()
{
	int arr[]={1, 2, 3, 4};
	int n=sizeof(arr)/sizeof(arr[0]);

	vector< set<int> > res = comb(arr, n);
	vector< set<int> >::iterator it = res.begin();

	for(; it != res.end(); it++)
	{
		set<int>::iterator tmpit = it->begin();

		for(; tmpit != it->end(); tmpit++)
			cout<<(*tmpit)<<" ";

		cout<<endl;
	}

	return 0;
}
