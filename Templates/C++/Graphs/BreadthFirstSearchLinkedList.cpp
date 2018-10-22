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
