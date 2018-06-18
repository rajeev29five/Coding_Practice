#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> v, int node, bool visited[], int parent[])
{
	if(!visited[node])
	{
		visited[node] = true;
		for(int i : v[node])
		{
			if(!parent[i])
				parent[i] = node;
			dfs(v, i, visited, parent);
		}
	}
}

int main()
{
	int vertices;
	cin>>vertices;
	vector<vector<int>> v(vertices+1);
	int start, end;
	bool visited[vertices+1] = {false};

	int parent[vertices+1] = {0};

	for(int i = 1; i<=vertices; i++)
	{
		cin>>start>>end;
		v[start].push_back(end);
		//
		// Uncomment the following line for undirected graphs.
		//
		//v[end].push_back(start);
	}
	parent[1] = 0;
	for(int i = 1; i<=vertices; i++)
	{
		if(!visited[i])
			dfs(v, i, visited, parent);
	}

	//
	// Uncomment the following lines to see the parent of a node.
	//
	//for(int i = 1; i<=vertices; i++)
	//	cout<<i<<":"<<parent[i]<<endl;
	
	return 0;
}
