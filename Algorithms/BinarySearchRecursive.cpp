#include<iostream>
using namespace std;

// consider the array is sorted ascending order
int binarySearchRec(int *a, int start, int end, int key){
	int mid;
	if(start>end)
	{
		return -1;
	}else{
		mid = (start + end)/2;
		if(a[mid]>key){
			binarySearchRec(a, start, mid, key);
		}else if(a[mid]<key){
			binarySearchRec(a, mid+1, end, key);
		}else {
			return mid;
		}
	}
}

void main(){
	int s=0, e=9,key=564;
	int arr[]={1,4,6,8,11,66,99,231,564,777};
	cout<<"index of key: "<<binarySearchRec(arr, s, e, key)<<"\n";
}