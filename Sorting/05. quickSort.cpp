#include <iostream>

using namespace std;

int partition(int arr[], int left, int right)
{

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {

                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }

      }
      return i;
}

void quickSort(int a[],int p,int r)
{
    int j;
    if(p<r)
    {
        j=partition(a,p,r);
        quickSort(a,p,j-1);
        quickSort(a,j+1,r);
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

    quickSort(arr,0, len-1);
    cout << "Sorted array: ";
    showArray(arr, len);

}
