#include <iostream>
using namespace std;

void bubble(int arr[], int n)
{
    int temp;
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
            if (arr[j+1] < arr[j])
                swap(arr[j+1],arr[j]);
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

    bubble(arr,len);
    cout << "Sorted array: ";
    showArray(arr, len);

}

