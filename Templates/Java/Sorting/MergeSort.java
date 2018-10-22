import java.util.Scanner;
//great code
class MergeSort {

    public static void merge(int a[], int l, int m, int n)
    {
        int n1 = m - l + 1;
        int n2 = n - m;

        int left[] = new int[n1];
        int right[] = new int[n2];

        for(int i = 0; i<n1; i++) left[i] = a[l+i];
        for(int j = 0; j<n2; j++) right[j] = a[m+1+j];

        int i = 0, j = 0, k = l;

        while(i < n1 && j < n2) {

            if(left[i] <= right[j]) {
                a[k] = left[i];
                i++;
            }
            else {
                a[k] = right[j];
                j++;
            }
            k++;
        }

        while(i < n1) {
            a[k] = left[i];
            i++;
            k++;
        }

        while(j < n2) {
            a[k] = right[j];
            j++;
            k++;
        }
    }

    public static void mergeSort(int a[], int l, int n) {

        int m = (n+l)/2;
        if(l<n)
        {
            mergeSort(a, l, m);
            mergeSort(a, m+1, n);

            merge(a, l, m, n);
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
        for(int i = 0; i<n; i++) {
            a[i] = sc.nextInt();
        }
        mergeSort(a, 0, n-1);
        printArray(a);
    }

}
