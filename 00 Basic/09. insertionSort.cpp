#include <iostream>
using namespace std;

void insertion(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        int x = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j]>x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr [j + 1] = x;
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

    insertion(arr,len);
    cout << "Sorted array: ";
    showArray(arr, len);

}
