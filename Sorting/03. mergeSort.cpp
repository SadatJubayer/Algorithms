#include <iostream>
using namespace std;

void merge (int arr[], int start, int end, int mid)
{
    int i, j , k, brr [end-start+1];
    i = start;
    k = 0;
    j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            brr[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            brr[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        brr[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        brr[k] = arr[j];
        k++;
        j++;
    }
    for (i=start; i <= end; i++)
    {
        arr[i] = brr[i-start];
    }
}

void mergeSort(int arr[], int n, int start, int End)
{
    if (start < End)
    {
        int mid = (start + End) / 2;
        mergeSort(arr, n, start, mid);
        mergeSort(arr, n, mid+1, End);

        merge(arr, start, End, mid);
    }
}

void showArray (int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr [i] << " ";
}

int main()
{
    int arr [] = {15,25,13,6,5,7,98,8,2,55};
    int len = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, len, 0, len-1);
    cout << "Sorted array: ";
    showArray(arr, len);

}
