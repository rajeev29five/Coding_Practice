//
// Code Contribution(s): Rajeev Ranjan
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
	bool visited[vertices+1] = {false};
	int parent[vertices+1] = {0};		// Not necessary for dfs
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
	//
	// Uncomment the following lines to see parent of a node.
	//
	//for(int i = 1; i<=vertices; i++)
	//{
	//	cout<<i<<":"<<parent[i]<<endl;
	//}
	return 0;
}
