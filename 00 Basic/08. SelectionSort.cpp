#include <iostream>
#include <algorithm> // for using built in swap function

using namespace std;

int main()
{
    int arr [10] = {15,25,13,6,5,7,98,8,2,55};
//    selection(arr,10);
    for (int i=0; i<10; i++)
    {
        for (int j=i+1; j<10; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }

    for (int i=0; i<10; i++)
        cout << arr[i] << endl;

}
