#include <iostream>

using namespace std;

class Heap
{
public:
	int value;
	int label;	
};

void heapify(Heap minHeap[], int size, int index)
{
	Heap temp;
	while(2*index <= size)
	{
		if(2*index+1 > size)
		{
			if(minHeap[index].value > minHeap[2*index].value)
			{
				temp = minHeap[index];
				minHeap[index] = minHeap[2*index];
				minHeap[2*index] = temp;

				break;
			}
		}

		if(minHeap[index].value > minHeap[2*index].value || minHeap[index].value > minHeap[2*index+1].value)
		{
			if(minHeap[2*index].value < minHeap[2*index+1].value)
			{
				temp = minHeap[index];
				minHeap[index] = minHeap[2*index];
				minHeap[2*index] = temp;

				index = 2*index;
			}
			else
			{
				temp = minHeap[index];
				minHeap[index] = minHeap[2*index+1];
				minHeap[2*index+1] = temp;

				index = 2*index+1;
			}
		}
		else
		{
			break;
		}
	}
}

void buildHeap(Heap minHeap[], int size)
{
	for(int i = size/2; i>=1; i--)
		heapify(minHeap, size, i);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	Heap minHeap[n+2];
	for(int i = 1; i<=n; i++)
	{
		cin>>minHeap[i].label>>minHeap[i].value;
	}

	buildHeap(minHeap, n);

	// Display Heap
	for(int i = 1; i<=n; i++)
	{
		cout<<minHeap[i].label<<":"<<minHeap[i].value<<" ";
	}
	return 0;
}
