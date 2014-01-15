// Implement LRU cache

#include<list>
#include<unordered_map>
#include<iostream>

using namespace std;

typedef list<int>::iterator itr;

void insertl(list<int>& lru, unordered_map<int, itr>& m, int n, const int& sz)
{
	int curr_sz = lru.size();

	if(m.find(n) != m.end())
	{
		lru.erase(m[n]);
		lru.push_front(n);
	}
	else
	{
		if(curr_sz<sz)
		{
			lru.push_front(n);
			m[n]=lru.begin();
		}
		else
		{
			lru.push_front(n);
			m[n]=lru.begin();
			lru.pop_back();
		}
	}
}

void printl(const list<int>& lru)
{
	list<int>::const_iterator it=lru.cbegin();
	for(; it!=lru.cend(); it++)
		cout<<(*it)<<" ";
	cout<<endl;
}

int main()
{
	list<int> lru;
	unordered_map<int, itr> m;
	const int sz = 5; // assuming cache size as 5

	int n;

	while(cin>>n)
	{
		insertl(lru, m, n, sz);
		printl(lru);
	}
}
