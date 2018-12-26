#include<iostream>
using namespace std;

int binarySearch(int a[], int start, int end, int key)
{
	int mid;
	if(start>end)
	{
		return -1;
	}
	else
    {
		mid = (start + end)/2;
		if(a[mid]>key){
			binarySearch(a, start, mid, key);
		}
		else if(a[mid]<key){
			binarySearch(a, mid+1, end, key);
		}
		else {
			return mid;
		}
	}
}

int main()
{
    int arr [] = {1,4,6,8,11,66,99,231,564,777};
    int len = sizeof(arr)/sizeof(arr[0]);
    int key = 564;
	cout<<"index of key: "<<binarySearch(arr, 0, len, key)<<"\n";
}

