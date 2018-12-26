#include<iostream>
using namespace std;
int knapsack_01_Naive(int *weight, int *value, int items, int bag, int *itemTaken){
    int result, temp1, temp2;
    if(items == 0 || bag == 0){
        return 0;
    }else if(weight[items] > bag){
        result = knapsack_01_Naive(weight, value, items-1, bag, itemTaken);
    }else{
        temp1 = knapsack_01_Naive(weight, value, items-1, bag, itemTaken);
        temp2 = value[items] + knapsack_01_Naive(weight, value, items-1, (bag-weight[items]), itemTaken);

        if(temp1>temp2){
            result = temp1;
            //itemTaken[items-1]=1; itemTaken[items]=0;
        }else{
            result = temp2;
            //itemTaken[items]=1; itemTaken[items-1]=1;
        }
    }
    return result;
}

int knapsack_01_TopDown(int *weight, int *value, int items, int bag, int *itemTaken, int **grid){
    int result, temp1, temp2;

    if(grid[items][bag] !=-1){
        cout<<"Memoization...\n";
        return grid[items][bag];
    }else{
        cout<<"else: "<<items<<"  "<<bag<<"="<<grid[items][bag]<<"\n";
    }

    if(items == 0 || bag == 0){
        return 0;
    }else if(weight[items] > bag){
        result = knapsack_01_TopDown(weight, value, items-1, bag, itemTaken, grid);
    }else{
        temp1 = knapsack_01_TopDown(weight, value, items-1, bag, itemTaken, grid);
        temp2 = value[items] + knapsack_01_TopDown(weight, value, items-1, (bag-weight[items]), itemTaken, grid);

        if(temp1>temp2){
            result = temp1;
            grid[items][bag] = result;
            cout<<items<<"  "<<bag<<"="<<grid[items][bag]<<"\n";
        }else{
            result = temp2;
            grid[items][bag] = result;
            cout<<items<<"  "<<bag<<"="<<grid[items][bag]<<"\n";
        }
    }
    return result;
}

int knapsack_0_1_bottom_up(int *w, int *v, int items, int bag){
    //int grid[items][bag]; // I didn't find any error but somehow the 2d array gets wrong value may be
    // because of continuous memory allocation fails, though its a small array.
    int **grid;  // Dynamic array solved that problems
    grid = new int*[items];
    for(int k=0; k<=bag; k++){
        grid[k]= new int[bag];
    }

    for(int i=0; i<=items; i++)
        grid[i][0]=0;
    for(int i=0; i<=bag; i++)
        grid[0][i]=0;

    cout<<"\n";
    for(int i=0; i<=items; i++){
        for(int j=0; j<=bag; j++){
            cout<<grid[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    int k, ww;
    for(k=1; k<=items; k++){
        for(ww=0; ww<=bag; ww++){
            if(w[k]<=ww){
                    if((v[k]+grid[k-1][ww-w[k]]) > grid[k-1][ww]){
                        grid[k][ww]= v[k]+grid[k-1][ww-w[k]];
                    }else{
                        grid[k][ww]= grid[k-1][ww];
                    }
            }else{
                grid[k][ww]=grid[k-1][ww];
            }
        }
    }

    cout<<"\n"; cout<<"Bottom up 0-1 Knapsack Solution: \n";
    for(int i=0; i<=items; i++){
        for(int j=0; j<=bag; j++){
            cout<<grid[i][j]<<"\t";
        }
        cout<<"\n";
    }

    while(items !=0 ){
        if(grid[items][bag] != grid[items-1][bag]){
            cout<<"Item: "<<items<<" is taken. \n";
            items--; bag = bag - w[items];
        }else{
            items--;
        }
    }

}

int main(){
    cout<<"0-1 Knapsack Naive version.\n";
    int totalItem = 4; //1, 2, 4
    int selectedItems[]={0,0,0,0,0};

    //int w[]=  {1, 2, 4, 2, 5};
    //int v[] = {5, 3, 5, 3, 2};

    int w[]=  {0, 2, 3, 4, 5};
    int v[] = {0, 3, 4, 5, 6};
    int capacity = 5;
   // int grid[totalItem][capacity];
    int outcome = knapsack_01_Naive(w, v, totalItem, capacity, selectedItems);
    cout<<"Naive, Capacity is = "<<capacity<< " and outcome is = "<<outcome<<"\n";

    knapsack_0_1_bottom_up(w, v, totalItem, capacity);


    int **grid;  // Dynamic array solved that problems
    grid = new int*[totalItem];
    for(int k=0; k<=capacity; k++){
        grid[k]= new int[capacity];
    }

    for(int i=0; i<=totalItem; i++){
        for(int j=0; j<=capacity; j++){
            grid[i][j]= -1;
        }
    }

    for(int i=0; i<=totalItem; i++){
        for(int j=0; j<=capacity; j++){
            cout<<grid[i][j]<<"\t";
        }
        cout<<"\n";
    }


    int result = knapsack_01_TopDown(w, v, totalItem, capacity, selectedItems, grid);
    cout<<"Top Down, Capacity is = "<<capacity<< " and outcome is = "<<result<<"\n";

   return 0;
}
