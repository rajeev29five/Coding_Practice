//
// Code Contributor(s) : Rajeev Ranjan
//

import java.util.Scanner;

class QuickSort {

    public static int partition(int a[], int l, int n) {
        int pivot = a[n];
        int i = l - 1;

        for(int j = l; j<=n-1; j++) {
            if(a[j]<=pivot) {
                i = i + 1;
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
        int temp = a[n];
        a[n] = a[i+1];
        a[i+1] = temp;

        return i+1;
    }

    public static void quickSort(int a[], int l, int n) {
        if(l<n)
        {
            int pi = partition(a, l, n);

            quickSort(a, l, pi-1);
            quickSort(a, pi+1, n);
        }
    }

    public static void printArray(int a[]) {
        for(int i : a) {
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i<a.length; i++) {
            a[i] = sc.nextInt();
        }
        quickSort(a, 0, n-1);
        printArray(a);
    }

}
