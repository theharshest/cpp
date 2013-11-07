#include<iostream>

using namespace std;

int main()
{
	int arr[10] = {45, 2, 5, 12, 6, 7, 8, 11, 99, 1};

	for(int i=1; i<10; i++)
	{
		int key = arr[i];
		int j = i-1;
		while((j>=0) && (arr[j]>key))
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}

	for(int i=0; i<10; i++)
		cout<<arr[i]<< " ";
}
