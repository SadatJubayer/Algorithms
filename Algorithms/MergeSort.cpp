#include<iostream>
using namespace std;

void merge(int *a, int p, int q, int r){
	int *temp;
	int length = r-p+1;
	temp = new int[length];
	cout<<"length is:"<<length<<"\n";

	int i, j, k;
	//i=k=p;
	i=p;
	k=0;

	j = q+1;

	while(i<=q && j<=r){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
		}
	}
	while(i<=q)
		temp[k++]=a[i++];
	while(j<=r)
		temp[k++]=a[j++];

	k=0;
	for(int x=p; x<=r; x++)
	{
		cout<<"temp["<<x<<"]="<<temp[k]<<"\n";
		a[x]=temp[k];
		k++;
	}
	cout<<"\n\n\n";
}
void mergeSort(int *a, int p, int r){
	if(p<r){
		int q = (p+r)/2;
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);
		merge(a, p, q, r);
	}
}

void show(int *a, int end){
	for(int i=0; i<=end; i++)
		cout<<a[i]<<"\t";
	cout<<"\n";
}
int main(){
	int array[]={4, -5, 77, 1, 0, 44, 21, 6, 10, 33,7, 88,222, 23,-6};
	int start=0, end = 14;
	mergeSort(array, start, end);
	show(array, end);
	return 0;
}
