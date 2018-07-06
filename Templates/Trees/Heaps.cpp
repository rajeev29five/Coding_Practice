//
// Code Contributor(s): Rajeev Ranjan
//

#include <iostream>

using namespace std;

class Heap
{
public:
	int data;
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
				temp = minHeap[index].value;
				minHeap[index] = minHeap[2*index].value;
				minHeap[2*index].value = temp;

				break;
			}
		}

		if(minHeap[index].value > minHeap[2*index] || minHeap[index].value > minHeap[2*index+1])
		{
			if(minHeap[2*index].value < minHeap[2*index+1])
			{
				temp = minHeap[index].value;
				minHeap[index].value = minHeap[2*index].value;
				minHeap[2*index].value = temp;

				index = 2*index;
			}
			else
			{
				temp = minHeap[index].value;
				minHeap[index].value = minHeap[2*index+1].value;
				minHeap[2*index+1].value = temp;

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
		cin>>minHeap[i].data>>minHeap[i].label;
	}
	buildHeap(minHeap, n);
	return 0;
}
