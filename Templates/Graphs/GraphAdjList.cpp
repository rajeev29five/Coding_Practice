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

class LinkedList
{
	public:
		Node * insertNode(Node * currentHead, int vertex);
};

Node * LinkedList::insertNode(Node * currentHead, int vertex)
{
	Node * newNode = new Node;

	newNode->data = vertex;
	newNode->next = currentHead;

	return newNode;
}

int main()
{
	LinkedList l;
	int v;
	cin>>v;
	int e1, e2;
	Node * adjList[v+1]={NULL};
	for(int i = 1; i<v; i++)
	{
		cin>>e1>>e2;
		adjList[e1] = l.insertNode(adjList[e1], e2);
		adjList[e2] = l.insertNode(adjList[e2], e1);
	}
	for(int i = 1; i<=v; i++)
	{
		Node * traverse = adjList[i];
		cout<<i<<"->";
		while(traverse->next != NULL)
		{
			cout<<traverse->data<<"->";
			traverse = traverse->next;
		}
		cout<<traverse->data<<"->NULL"<<endl;
	}
	return 0;
}
