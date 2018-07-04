#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <bits/stdc++.h>
#include <map>

using namespace std;

class Node
{
public:
	int data;
	int rank;
	Node * parent;
};

map<int, Node *> m;
int sumWeight;

void makeSet(int v)
{
	do
	{
		Node * newNode = new Node;
		newNode->data = v;
		newNode->rank = 0;
		newNode->parent = newNode;
		m[v] = newNode;
	}while(v--);
}

int findSet(Node * node)
{
	if(node->parent == node)
		return node->data;
	return findSet(node->parent);
}

void unionSet(int x, int y, int weight)
{
	Node * nodeX = m[x];
	Node * nodeY = m[y];

	int parentX = findSet(nodeX);
	int parentY = findSet(nodeY);

	if(parentX == parentY)
		return;

	sumWeight = sumWeight + weight;
	if(m[parentX]->rank >= m[parentY]->rank)
	{
		m[parentY]->parent = m[parentX];
		m[parentX]->rank = m[parentX]->rank + 1;
	}
	else
	{
		m[parentX]->parent = m[parentY];
		m[parentY]->rank = m[parentY]->rank + 1;
	}

}

int main(int argc, char const *argv[])
{
	int vertices, edges;
	cin>>vertices>>edges;

	vector<pair<int, pair<int,int>>> adj;
	int start, end, weight;

	for(int i = 1; i<=edges; i++)
	{
		cin>>start>>end>>weight;
		adj.push_back(make_pair(weight, make_pair(start, end)));
	}
	sort(adj.begin(),adj.end());
	makeSet(vertices);

	for(int i = 0; i<adj.size(); i++)
	{
		unionSet(adj[i].second.first, adj[i].second.second, adj[i].first);
	}

	cout<<"Weight"<<setw(9)<<"Source"<<setw(15)<<"Destination"<<endl;
	for(int i = 0; i<adj.size(); i++)
	{
		cout<<setw(4)<<adj[i].first<<setw(9)<<adj[i].second.first<<setw(15)<<adj[i].second.second<<endl;
	}
	cout<<"Total Weight of Spanning Tree : "<<sumWeight<<endl;

	return 0;
}