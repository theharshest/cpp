//Towers of Hanoi

#include<iostream>
#include<stack>

using namespace std;

void toh(int n, stack<int>& start, stack<int>& dest, stack<int>& buffer)
{
	if(n<=0)
		return;

	toh(n-1, start, buffer, dest);
	dest.push(start.top());
	start.pop();
	toh(n-1, buffer, dest, start);
}

int main()
{
	stack<int> start, dest, buffer;
	int n=3;

	for(int i=3; i>=1; i--)
		start.push(i);

	toh(n, start, dest, buffer);
}
