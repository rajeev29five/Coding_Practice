//
// Code Contributor(s) : Rajeev Ranjan
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> adjList, int level[], int parent[])
{
	int par;
	level[11] = 0;		// set index equal to source for bfs
	queue<int> q;
	q.push(11);		// push source index
	while(!q.empty())
	{
		int j = q.front();
		q.pop();
		for(int i: adjList[j])
		{
			if(level[i] == -1)
			{
				q.push(i);
				level[i] = level[j]+1;
				parent[i] = j;
			}
		}
	}
}

int main()
{
	int vertices;
	int edges;
	cin>>vertices>>edges;
	vector<vector<int>> adjList(vertices+1);
	int start, end;
	int level[vertices+1];
	int parent[vertices+1];
       	fill(level, level+vertices+1, -1);
	fill(parent, parent+vertices+1, 0);	

	for(int i = 1; i<=edges; i++)
	{
		cin>>start>>end;
		adjList[start].push_back(end);
		adjList[end].push_back(start);		// Comment this line for directed graph.
	}	
	
	bfs(adjList, level, parent);

	for(int i = 1; i<=vertices; i++)
	{
		cout<<"Node "<<i<<" is on level "<<level[i]<<" and its parent is "<<parent[i]<<endl;
	}

	return 0;
}
//program ends

/*

Test Case: 1

-----INPUT-----
9
12
1 2
1 6
1 8
2 3
3 4 
3 8
3 9
4 5
5 7 
5 9
6 7
7 9

-----OUTPUT-----

Node 1 is on level 0 and its parent is 0
Node 2 is on level 1 and its parent is 1
Node 3 is on level 2 and its parent is 2
Node 4 is on level 3 and its parent is 3
Node 5 is on level 3 and its parent is 7
Node 6 is on level 1 and its parent is 1
Node 7 is on level 2 and its parent is 6
Node 8 is on level 1 and its parent is 1
Node 9 is on level 3 and its parent is 3


TEST CASE: 2

-----INPUT------
12
21
1 3
1 4
2 3 
2 4 
2 5 
2 7  
2 8
2 12
3 5 
3 12
5 7 
5 8 
5 12
4 7 
4 9
7 8 7 9
6 8 
6 10 
9 10
10 11

-----OUTPUT----

Node 1 is on level 4 and its parent is 4
Node 2 is on level 4 and its parent is 8
Node 3 is on level 5 and its parent is 2
Node 4 is on level 3 and its parent is 9
Node 5 is on level 4 and its parent is 8
Node 6 is on level 2 and its parent is 10
Node 7 is on level 3 and its parent is 9
Node 8 is on level 3 and its parent is 6
Node 9 is on level 2 and its parent is 10
Node 10 is on level 1 and its parent is 11
Node 11 is on level 0 and its parent is 0
Node 12 is on level 5 and its parent is 2

*/
