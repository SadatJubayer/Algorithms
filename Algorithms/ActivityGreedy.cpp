#include<iostream>
using namespace std;

void activityGreedy(int *s, int *f, int n){
	int *resultSet;
	resultSet = new int[n];
	int count=0;
	int i=0;
	resultSet[count]=1;
	for(int m=1; m<n; m++){
		if(s[m]>=f[i]){
			resultSet[++count]=m+1;
			i=m;
		}
	}
	for(int j=0;j<=count; j++){
		cout<<"activity: "<<resultSet[j]<<"\n";
	}
}
void main(){
	
	int s[11]={1,3,0,5,3,5,6,8,8,2,12};
	int f[11]={4,5,6,7,8,9,10,11,12,13,14};
	int size=11;
	activityGreedy(s,f,size);
}