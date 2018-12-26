#include <iostream>
using namespace std;

void countingSort(int A[], int k, int n)
{
    int i, j;
    int B[n], C[k+1];

    for (i=0; i<=k; i++)
        C[i] = 0;

    for (j=0; j<n; j++)
        C[A[j]] = C[A[j]] + 1;

    for (i=1; i<k+1; i++)
        C[i] = C[i] + C[i-1];

    for (j=n-1; j>=0; j--)
    {
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    cout <<"The Sorted array is : ";
    for (i=0; i<n; i++)
        cout << B[i] << " ";

}

int main()
{
    int arr [] = {15,25,13,6,5,7,98,8,2,55};
    int len = sizeof(arr)/sizeof(arr[0]);
    int Max = 0;
    for (int i=0; i<len; i++)
    {
        if(arr[i]>Max)
        Max=arr[i];
    }

    countingSort(arr, Max, len);

}
