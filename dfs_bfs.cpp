// Depth First Search and Breadth First Search
#include<iostream>
#include<list>
#include<queue>
#include<algorithm>

using namespace std;

class graph{
	int v;
	list<int>* adj;

	public:
	graph(int n);
	void add_edge(int n, int m);
	void dfs(int n, bool vis[]);
	void bfs(int n, bool vis[]);
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

void graph::dfs(int n, bool vis[])
{
	cout<<n<<endl;
	vis[n]=true;

	list<int>::iterator it = adj[n].begin();

	for(; it!=adj[n].end(); it++)
		if(!vis[*it])
			dfs(*it, vis);
}

void graph::bfs(int n, bool vis[])
{
	queue<int> q;

	q.push(n);

	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();

		cout<<tmp<<endl;
		vis[tmp]=true;

		list<int>::iterator it = adj[tmp].begin();

		for(; it!=adj[tmp].end(); it++)
			if(!vis[*it])
				q.push(*it);
	}
}

int main()
{
	graph *g = new graph(5);

	g->add_edge(0, 3);
	g->add_edge(3, 1);
	g->add_edge(3, 4);
	g->add_edge(4, 1);
	g->add_edge(1, 2);
	
	bool vis[5]={};

	cout<<"DFS:"<<endl;
	g->dfs(0, vis);

	fill(vis, vis+5, 0);

	cout<<"BFS:"<<endl;
	g->bfs(0, vis);
}
