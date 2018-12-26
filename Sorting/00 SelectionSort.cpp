#include <iostream>
using namespace std;

void selection(int arr[], int n)
{
    for (int i=0; i<10; i++)
    {
        for (int j=i+1; j<10; j++)
            if (arr[i] > arr[j])
                swap(arr[i],arr[j]);
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

    selection(arr,len);
    cout << "Sorted array: ";
    showArray(arr, len);

}
