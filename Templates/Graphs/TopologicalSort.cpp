#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};

Node * insert(Node * temp, int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = temp;

	return newNode;
}

int a[10001];							// Maximum size of stack is assumed to be 10001
int c = 0;

void push(int i)
{
	a[c] = i;
	c++;
}

void dfs(Node * adjList[], int i, bool visited[])
{
	visited[i] = true;
	Node * temp = adjList[i];
	while(temp != NULL)
	{
		if(!visited[temp->data])
		{
			dfs(adjList, temp->data, visited);
		}
		temp = temp->next;
	}
	cout<<"pushing "<<i<<endl;
	push(i);
}

int main(int argc, char const *argv[])
{
	int vertices, edges;
	cin>>vertices>>edges;
	
	Node * adjList[vertices+1] = {NULL};
	int start, end;
	bool visited[vertices+1];
	fill(visited, visited+vertices+1, false);

	for(int i = 1; i<=edges; i++)
	{
		cin>>start>>end;
		adjList[start] = insert(adjList[start], end);
	}
	for(int i = 1; i<=vertices; i++)
	{
		if(!visited[i])
		{
			dfs(adjList, i, visited);
		}
	}

	// Display adjList

	// for(int i = 1; i<=vertices; i++)
	// {
	// 	Node * temp = adjList[i];
	// 	cout<<i<<"->";
	// 	while(temp != NULL)
	// 	{
	// 		cout<<temp->data<<"->";
	// 		temp = temp->next;
	// 	}
	// 	cout<<"NULL"<<endl;
	// }

	// Display Topologically Sorted Vertices
	for(int i = c-1; i>=0 ; i--)
	{
		cout<<a[i]<<" "<<endl;
	}
	return 0;
}