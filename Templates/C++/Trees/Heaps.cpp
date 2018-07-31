#include <iostream>

using namespace std;

class Heap {
public:
	int data;
	int label;
};

void heapify(Heap minHeap[], int index, int size) {

	while( 2*index <= size) {

		if ( 2*index+1 > size ) {
			if (minHeap[2*index].data < minHeap[index].data) {
				Heap temp = minHeap[2*index];
				minHeap[2*index] = minHeap[index];
				minHeap[index] = temp;
			}
			break;
		}
		if(minHeap[index].data > minHeap[2*index].data || minHeap[index].data > minHeap[2*index+1].data ) {
			if( minHeap[2*index].data < minHeap[2*index+1].data ) {
				Heap temp = minHeap[2*index];
				minHeap[2*index] = minHeap[index];
				minHeap[index] = temp;

				index = 2*index;
			}
			else {
				Heap temp = minHeap[2*index+1];
				minHeap[2*index+1] = minHeap[index];
				minHeap[index] = temp;
				index = 2*index+1;
			}
		}
		else {
			break;
		}
	}

}

void buildHeap(Heap minHeap[], int size) {
	for(int i = size/2; i>=1; i--) {
		heapify(minHeap, i, size);
	}
}

void displayHeap(Heap minHeap[], int size) {
	for(int i = 1; i<=size; i++) {
		cout<<minHeap[i].data<<":"<<minHeap[i].label<<" ";
	}
	cout<<endl;
}

void addVertex(Heap minHeap[], int &size, Heap newVal) {

	size++;
	int index = size;
	minHeap[size] = newVal;
	while (index > 1) {
		if ( minHeap[index/2].data > minHeap[index].data ) {
			Heap temp = minHeap[index/2];
			minHeap[index/2] = minHeap[index];
			minHeap[index] = temp;

			index = index/2;
		}
		else {
			break;
		}
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin>>n;
	Heap heap[n+2];

	for(int i = 1; i<=n; i++) {
		cin>>heap[i].data;
		cin>>heap[i].label;
	}

	// displayHeap(heap, n);
	buildHeap(heap, n);
	displayHeap(heap, n);

	Heap newVal;
	cin>>newVal.data>>newVal.label;
	addVertex(heap, n, newVal);
	displayHeap(heap, n);

	return 0;
}
