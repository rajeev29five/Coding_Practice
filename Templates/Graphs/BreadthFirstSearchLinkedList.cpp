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

Node * insert(Node * head, int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = head;

	return newNode;
}

void bfs(Node * adjList[], int level[], int parent[], int vertices)
{
	int lev = 0, par = 0;
	level[1] = lev;
	parent[1] = par;
	int flag = 1;
	while(flag)
	{
		flag = 0;
		for (int i = 1; i <= vertices; ++i)
		{
			if(level[i] == lev)
			{
				Node * temp = adjList[i];
				par = i;
				flag = 1;

				while(temp != NULL)
				{
					if(level[temp->data] == -1)
					{
						cout<<"Setting level ["<<temp->data<<"] to"<<lev+1<<endl;
						level[temp->data] = lev+1;
						parent[temp->data] = par;
					}
					temp = temp->next;
				}
			}
		}
		lev++;
	}
}

int main(int argc, char const *argv[])
{
	int vertices;
	cin>>vertices;
	int start, end;
	int edges;
	cin>>edges;

	Node * adjList[vertices+1];
	int level[vertices+1];
	int parent[vertices+1];

	for (int i = 1; i <= vertices ; ++i)
	{
		adjList[i] = NULL;
		level[i] = -1;
		parent[i] = 0;
	}

	for(int i = 1; i<edges; i++)
	{
		cin>>start>>end;
		adjList[start] = insert(adjList[start], end);
		adjList[end] = insert(adjList[end], start);
	}

	/*
	*	Prints Adjacency List.
	*
	*/
	for(int i = 1; i<=vertices; i++)
	{
		Node * temp = adjList[i];
		cout<<i;
		while(temp != NULL)
		{
			cout<<"->"<<temp->data;
			temp = temp->next;
		}
		cout<<"->NULL\n";
	}

	bfs(adjList, level, parent, vertices);

	for (int i = 1; i <= vertices; ++i)
	{
		cout<<"Node "<<i<<" is on level "<<level[i]<<" and its parent is "<<parent[i]<<endl;
	}

	return 0;
}					
