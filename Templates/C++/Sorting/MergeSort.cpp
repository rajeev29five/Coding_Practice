#include <iostream>

using namespace std;

void merge(int a[], int l, int m, int n)
{
    int n1 = m - l + 1;
    int n2 = n - m;
    int left[n1];
    int right[n2];

    for(int i = 0; i<n1; i++) left[i] = a[l+i];
    for(int j = 0; j<n2; j++) right[j] = a[m+1+j];

    int i = 0, j = 0, k = l;

    while(i<n1 && j<n2)
    {
        if(left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int n) {

    int m = (n+l)/2;

    if(l<n)
    {
        mergeSort(a, l, m);
        mergeSort(a, m+1, n);

        merge(a, l, m, n);
    }

}

void printArray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[]) {

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++) cin>>a[i];
    mergeSort(a, 0, n-1);
    printArray(a, n);
    return 0;
}
