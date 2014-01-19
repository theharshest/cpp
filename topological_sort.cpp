// Topological Sort
#include<iostream>
#include<list>
#include<stack>
#include<algorithm>

using namespace std;

class graph{
	int v;
	list<int>* adj;

	public:
	graph(int n);
	stack<int> tmp;
	void add_edge(int n, int m);
	void top_sort_util(int n, bool vis[]);
	void top_sort(bool vis[]);
};

graph::graph(int n)
{
	v = n;
	adj = new list<int>[n];
}

void graph::add_edge(int n, int m)
{
	adj[n].push_back(m);
}

void graph::top_sort_util(int n, bool vis[])
{
	list<int>::iterator it = adj[n].begin();

	vis[n] = true;

	for(; it!=adj[n].end(); it++)
		if(!vis[*it])
			top_sort_util(*it, vis);

	tmp.push(n);
}

void graph::top_sort(bool vis[])
{
	for(int i=0; i<v; i++)
	{
		if(!vis[i])
			top_sort_util(i, vis);
	}
}

int main()
{
	graph *g = new graph(6);

	g->add_edge(5, 2);
	g->add_edge(5, 0);
	g->add_edge(4, 0);
	g->add_edge(4, 1);
	g->add_edge(2, 3);
	g->add_edge(3, 1);
	
	bool vis[6]={};

	cout<<"Topological Sort:"<<endl;
	g->top_sort(vis);

	while(!(g->tmp).empty())
	{
		cout<<g->tmp.top()<<endl;
		g->tmp.pop();
	}
}
