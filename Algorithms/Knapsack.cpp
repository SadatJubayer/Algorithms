#include<iostream>
using namespace std;
void knapsack(int *w, int *v, float *unit, int capacity){
    float x[]={0,0,0};
    int weight = 0; int i=0;// best item
    while(weight<capacity){
        if(weight+w[i]<=capacity){
            x[i]=1; weight +=w[i];
        }else{
            float a= w[i];
            x[i] = (capacity - weight)/a;
            weight = capacity; break;
        }
        i++;
    }
    for(int j=0; j<3; j++){
        cout<<x[j]<<"\n";
    }
}

int main(){
    int ww[]={10, 20, 30};
    int vv[]={60, 100, 120};
    float u[]={6, 5, 4};
    knapsack(ww, vv, u, 35);
}
