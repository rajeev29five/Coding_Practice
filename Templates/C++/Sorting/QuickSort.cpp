#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int n)
{
    int pivot = a[n];
    int i = l - 1;

    for(int j = l; j<=n-1; j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap (&a[i+1], &a[n]);

    return i+1;
}

void quickSort(int a[], int l, int n)
{
    if(l<n)
    {
        int pi = partition(a, l, n);

        quickSort(a, l, pi-1);
        quickSort(a, pi+1, n);
    }
}

void printArray(int a[], int length)
{
    for(int i = 0; i<length; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++) cin>>a[i];
    quickSort(a, 0, n-1);
    printArray(a, n);
    return 0;
}
