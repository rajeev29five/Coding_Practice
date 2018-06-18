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
	int v;
	cin>>v;
	int start, end;
	Node * adjList[v+1]={NULL};
	bool visited[v+1] = {false};
	int parent[v+1] = {0};		// Not necessary for dfs
	for(int i = 1; i<=v; i++)
	{
		cin>>start>>end;
		adjList[start] = insertNode(adjList[start], end);
		//
		// Uncomment this line for undirected graph
		//
		//adjList[end] = insertNode(adjList[end], start);
	}
	parent[1] = 0;
	for(int i = 1; i<=v; i++)
	{
		if(!visited[i])
			dfs(adjList, i, visited, parent);
	}
	//
	// Uncomment to see parent of a node.
	//
	//for(int i = 1; i<=v; i++)
	//{
	//	cout<<i<<":"<<parent[i]<<endl;
	//}
	return 0;
}
