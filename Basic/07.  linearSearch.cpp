#include <iostream>
#define sz 10

using namespace std;

int linearSearch(int *arr, int data)
{
    for (int i=0; i<sz; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[sz] =  {15,25,13,6,5,7,98,8,55,6};
    int data = 55;

    int n = linearSearch(arr,data);
    if (n == -1)
        cout << "Not Found";
    else
        cout << "Found at index " << n;
}
