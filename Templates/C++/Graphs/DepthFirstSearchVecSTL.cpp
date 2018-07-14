//
// Code Contributor(s): Rajeev Ranjan
//

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

/*

Test Case 
   
----Input----

10
1 2   
1 3
2 4
3 2
4 3
4 5
5 6
7 8
8 9
9 10

----Output----

Parent of 1 is 0
Parent of 2 is 3
Parent of 3 is 1
Parent of 4 is 2
Parent of 5 is 4
Parent of 6 is 5
Parent of 7 is 0
Parent of 8 is 7
Parent of 9 is 8
Parent of 10 is 9

*/
