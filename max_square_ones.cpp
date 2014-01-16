// Find maximum size square sub-matrix having all entries as 1s
#include<iostream>

using namespace std;

int max_square_ones(int arr[][5])
{
	int aux[][5]={
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	};

	int maxi=0;

	for(int i=0; i<6; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(i==0 || j==0)
				aux[i][j] = arr[i][j];
			else if(arr[i][j])
				aux[i][j] = min(aux[i-1][j-1], min(aux[i-1][j], aux[i][j-1])) + 1;
			else
				aux[i][j] = 0;
			maxi = max(maxi, aux[i][j]);
		}
	}

	return maxi;
}

int main()
{
	int arr[][5]={
	{0, 1, 1, 0, 1},
	{1, 1, 0, 1, 0},
	{0, 1, 1, 1, 0},
	{1, 1, 1, 1, 0},
	{1, 1, 1, 1, 1},
	{0, 0, 0, 0, 0},
	};

	cout<<max_square_ones(arr)<<endl;
}
