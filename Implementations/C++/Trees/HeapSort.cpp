//
// Code Contributor(s): Rajeev Ranjan
//

#include <iostream>
#include <vector>

using namespace std;

void display(int a[], int n){
	for(int i = 1; i<=n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void heapify(int a[], int i, int n)
{
	while(2 * i <= n)
	{
		if(2 * i + 1 > n)
		{
			if(a[i] > a[2*i])
			{
				int temp = a[2*i];
				a[2*i] = a[i];
				a[i] = temp;
			}

			break;
		}

		if(a[i] > a[2*i] || a[i] > a[2*i+1])
		{
			if(a[2*i] > a[2*i+1])
			{
				int temp = a[2*i+1];
				a[2*i+1] = a[i];
				a[i] = temp;

				i = 2*i+1;
			}
			else 
			{
				int temp = a[2*i];
				a[2*i] = a[i];
				a[i] = temp;

				i = 2*i;
			}
		}
		else
			break;

	}
}

int extractMin(int a[], int &n)
{
	int min = a[1];
	a[1] = a[n];
	n--;
	heapify(a, 1, n);

	return min;
}

void add(int a[], int key, int &n)
{
	n++;
	a[n] = key;
	for(int i = n/2; i>=1; i = i/2)
	{
		heapify(a, i, n);
	}
}

void build(int a[], int n)
{
	for(int i = n/2; i>=1; i--)
	{
		heapify(a, i, n);
	}
}

void heapsort(int a[], int n){
	vector<int> sorted;
	while(n){
		sorted.push_back(extractMin(a, n));
	}
	cout<<"Sorted Values ";
	for(auto i: sorted) cout<<i<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i = 1; i<=n; i++) {
		cin>>a[i];
	}
	display(a, n);
	build(a, n);
	display(a, n);
	cout<<"Min->"<<extractMin(a, n)<<endl;
	display(a, n);
	add(a, 1, n);
	display(a, n);
	heapsort(a, n);
	return 0;
}