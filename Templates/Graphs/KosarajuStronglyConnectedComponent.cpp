//
// Code Contributor(s): Rajeev Ranjan
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};

stack<int> s;

Node * insert(Node * temp, int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = temp;

	return newNode;
}

void dfsFirstRun(Node * adjList[], int node, bool visited[])
{
	visited[node] = true;
	Node * temp = adjList[node];
	while(temp != NULL)
	{
		if(!visited[temp->data])
		{
			dfsFirstRun(adjList, temp->data, visited);
		}
		temp = temp->next;
	}
	s.push(node);
}

void dfsSecondRun(Node * reverseAdjList[], int node, bool visited[])
{
	visited[node] = true;
	cout<<node<<" ";

	Node * temp = reverseAdjList[node];
	while(temp != NULL)
	{
		if(!visited[temp->data])
		{
			dfsSecondRun(reverseAdjList, temp->data, visited);
		}
		temp=temp->next;
	}
}

void reverseGraph(Node * reverseAdjList[], Node * adjList[], int vertices)
{
	for(int i = 1; i<=vertices; i++)
	{
		Node * temp = adjList[i];
		while(temp != NULL)
		{
			reverseAdjList[temp->data] = insert(reverseAdjList[temp->data], i);
			temp = temp->next;
		}
	}
}

int main(int argc, char const *argv[])
{
	int vertices, edges;
	cin>>vertices>>edges;
	int start, end;
	bool visited[vertices+1];
	fill(visited, visited+vertices+1, false);

	Node * adjList[vertices+1] = {NULL};

	for(int i = 1; i<=edges; i++)
	{
		cin>>start>>end;
		adjList[start] = insert(adjList[start], end);
	}

	for(int i = 1; i<=vertices; i++)
	{
		if(!visited[i])
		{
			dfsFirstRun(adjList, i, visited);
		}
	}

	Node * reverseAdjList[vertices+1] = {NULL};
	reverseGraph(reverseAdjList, adjList, vertices);
	fill(visited, visited+vertices+1, false);

	cout<<"Display Strongly Connected Components"<<endl;
	while(!s.empty())
	{
		if(!visited[s.top()])
		{
			dfsSecondRun(reverseAdjList, s.top(), visited);
			cout<<endl;
		}
		s.pop();
	}

	return 0;
}

/*

---Input---
11 13   
1 2
2 3
3 1
2 4
4 5
5 6
6 4
7 6
7 8
8 9
9 10
10 7
10 11

---Output---
Display Strongly Connected Components
7 10 9 8 
11 
1 3 2 
4 6 5 

*/
