#include<iostream>
using namespace std;

void main(){
	// semi-dynamic
	int c;
	const int size = 5; // you have to use const, else 
	int *p[size];  // compile error, because size
	p[0] = new int[c];// must have to know in compile time
	// but column can be dynamically allocated
	bool test;
	test = true; cout<< test<<"\n";
//-------------------------------------
	int row, col;  
	cout<<"enter row and column value:\n";
	cin>>row>>col;
	// pointer to a pointer to a integer
	int **Graph;  // Fully dynamic	
	//Allocate the array Graph and the Graph[i] arrays:
	Graph = new int*[row]; // row does not have to be constant, 
							//so dynamic
	int i, j;
	for (i = 0; i < row; i++) 
	{ 
		Graph[i] = new int[col]; 
	}
	// initialized to all 0 entries
	for (i = 0; i < row; i++) 
	{ 
		for (j = 0; j < col; j++) 
		{
		 Graph[i][j] = 0;
		}
   }

	for(int u=0; u<row; ++u) {
		cout << "\nadj[" << (char) (u+65) << "] -> ";
        for(int v=0; v<row; ++v) {
            cout << " " << Graph[u][v];
        }
    }



}