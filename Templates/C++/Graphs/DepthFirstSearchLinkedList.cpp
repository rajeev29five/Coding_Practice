//
// Code Contributor(s): Rajeev Ranjan
//

#include <iostream>

using namespace std;

class Node 
{
	public:
		int data;
		Node * next;
};

Node * insertNode(Node * temp, int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = temp;

	return newNode;
}

void dfs(Node * adjList[], int node, bool v[], int p[])
{

	v[node] = true;
	Node * temp = adjList[node];
	while(temp != NULL)
	{
		if(!v[temp->data])
		{
			if(!p[temp->data])
				p[temp->data] = node;
			dfs(adjList ,temp->data, v, p);
		}
		temp = temp->next;
	}
}

int main()
{
	int vertices;
	cin>>vertices;
	int start, end;
	Node * adjList[vertices+1]={NULL};
	bool visited[vertices+1];
	int parent[vertices+1];			// Not necessary for dfs

	//fill(adjList, adjList+vertices+1, NULL);
	fill(visited, visited+vertices+1, false);
	fill(parent, parent+vertices+1, 0);

	for(int i = 1; i<=vertices; i++)	// Replace <= by < for undirected graph
	{
		cin>>start>>end;
		adjList[start] = insertNode(adjList[start], end);
		//
		// Uncomment the following line for undirected graph
		//
		//adjList[end] = insertNode(adjList[end], start);
	}
	parent[1] = 0;
	for(int i = 1; i<=vertices; i++)
	{
		if(!visited[i])
			dfs(adjList, i, visited, parent);
	}
	
	for(int i = 1; i<=vertices; i++)
	{
		cout<<"Parent of "<<i<<" is "<<parent[i]<<endl;
	}
	return 0;
}

/*

Test Case

----Input-----
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

-----Output-----

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
