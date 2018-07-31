//
// Code Contributor(s): Rajeev Ranjan
//
// Time Complexity:
//
// T(n) =  O(1) + O(V) + O(E log E) + O(V log V) 👈 Union by rank
//        make set 👆        👆 sort
//       = O(E log E) + O(V log V)
//        as |E| >= |V| - 1
// T(n) = E log E + E log E
//      = E log E
//

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

/*

Test Case

---Input---
8
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

---Output---
Weight   Source    Destination
   1        6              7
   2        2              8
   2        5              6
   4        0              1
   4        2              5
   6        6              8
   7        2              3
   7        7              8
   8        0              7
   8        1              2
   9        3              4
  10        4              5
  11        1              7
  14        3              5
Total Weight of Spanning Tree : 37

*/
