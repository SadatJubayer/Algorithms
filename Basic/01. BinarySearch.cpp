#include<iostream>
using namespace std;

int binarySearch(int arr[], int length, int to_be_found){

    int p = 0;
    int r = length - 1;
    int q = (r + p) / 2;
    int counter = 0;

    while (p <= r)
    {
        counter++;
        if (arr[q] == to_be_found)
            return q;
        else
        {
            if (arr[q] < to_be_found)
            {
                p = q + 1;
                q = (r + p) / 2;
            }
            else
            {
                r = q - 1;
                q = (r + p) / 2;
            }
        }
    }
    return -1;
}

int main(){
	 int arr [] = {1,4,6,8,11,66,99,231,564,777};
    int len = sizeof(arr)/sizeof(arr[0]);
    int key = 564;
	cout<<"index of key: "<<binarySearch(arr, len, key)<<"\n";
}
