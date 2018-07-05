#include <iostream>

using namespace std;

class Node
{
public:
	int start;
	int end;
	int weight;
	Node * next;
};

Node * insert(int start, int end, int weight)
{
	Node * newNode = new Node;
	newNode->start = start;
	newNode->end = end;
	newNode->weight = weight;
	newNode->next = NULL;

	return newNode;
}

void bellmanFord(Node * adjList[], int distance[], int parent[], int source, int vertices, int edges)
{
	distance[source] = 0;
	for(int i = 0; i<vertices-1; i++)
	{
		for(int j = 1; j<=edges; j++)
		{
			Node * temp = adjList[j];
			if(distance[temp->end] > distance[temp->start] + temp->weight)
			{
				distance[temp->end] = distance[temp->start] + temp->weight;
				parent[temp->end] = temp->start;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int vertices, edges;
	cin>>vertices>>edges;

	int start, end, weight;
	Node * adjList[edges+1]={NULL};

	for(int i = 1; i<=edges; i++)
	{
		cin>>start>>end>>weight;
		adjList[i] = insert(start, end, weight); 
	}

	int distance[vertices];
	fill(distance, distance+vertices, INT8_MAX);
	int source;
	cin>>source;
	int parent[vertices]={-1};

	bellmanFord(adjList, distance, parent, source, vertices, edges);
	int minDistance = 0;

	// for(int i = 0; i<vertices; i++)
	// {
	// 	cout<<"Parent "<<i<<" "<<parent[i]<<endl;
	// }
	cout<<"Shortest path from "<<source<<" to 4: "<<distance[4]<<endl;
	return 0;
}

/*

Test Case 1

---Input---
5
7
0 1 4
0 2 5
0 3 8
1 2 -3
2 4 4
4 3 1
3 4 2
0

---Output---
Shortest path from 0 to 4: 5

Test Case 2

---Input---
5
8
0 1 -1									
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0

---Output---
Shortest path from 0 to 4: 1


*/