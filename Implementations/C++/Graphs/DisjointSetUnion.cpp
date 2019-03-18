//
// Code Contributor(s) : Rajeev Ranjan
//

#include <iostream>
#include <map>

using namespace std;

class Node
{
	public:
		int data;
		int rank;
		Node * parent;
};

map<int , Node *> m;

void makeSet(int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->rank = 0;
	newNode->parent = newNode;

	m[data] = newNode;
}

Node * findSet(Node * temp)
{
	if(temp->parent == temp)
		return temp;
	return temp->parent = findSet(temp->parent);
}

int findSet(int data)
{
	return findSet(m[data])->data;
}

void unionSet(int x, int y)
{
	Node * nodex = m[x];
	Node * nodey = m[y];

	Node * parentx = findSet(nodex);
	Node * parenty = findSet(nodey);

	if(parentx == parenty)
		return ;

	if(parentx->rank >= parenty->rank)
	{
		parentx->rank = (parentx->rank == parenty->rank)?(parentx->rank+1):parentx->rank;
		parenty->parent = parentx;
	}
	else
	{
		parentx->parent = parenty;
	}
}


int main()
{

	makeSet(1);
	makeSet(2);
	makeSet(3);
	makeSet(4);
	makeSet(5);
	makeSet(6);
	makeSet(7);

	unionSet(1, 2);
	unionSet(2, 3);
	unionSet(4, 5);
	unionSet(6, 7);
	unionSet(5, 6);
	unionSet(3, 7);

	cout<<findSet(6)<<endl;
	cout<<findSet(7)<<endl;
	cout<<findSet(1)<<endl;
	cout<<findSet(3)<<endl;

	return 0;
}
// program ends
