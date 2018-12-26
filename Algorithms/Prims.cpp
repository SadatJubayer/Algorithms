#include<iostream>
#include<queue>
#include<stack>
#include <limits>

using namespace std;

class Graph {
private:
      int **adjMatrix;
      int vertexCount;
	  // below attributes are for Prims
	 
	  int *key; 
	  int *distance; 
	  int *parent;	 
	  int mstCost;
public:
    Graph(int vertexCount);
    ~Graph();	    
	void addEdgeUndirectedWeight(int i, int j, int cost);   
	void removeEdgeUndirected(int i, int j);
    int isEdge(int i, int j);
    void display();
	void initializeState();		

	void showBasicInfo();
	void primsMST(int startNode);
	int isAllKeyTrue();  //0 means not MST, 1 means MST
	int findMinDistanceNode();
		
};
Graph::Graph(int vertexCount) {	
    this->vertexCount = vertexCount;
	
	this->key = new int[vertexCount];
	this->distance = new int[vertexCount];
	this->parent = new int[vertexCount];

	this->mstCost = 0;
	
    adjMatrix = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[i] = new int[vertexCount];
           for (int j = 0; j < vertexCount; j++)
              adjMatrix[i][j] = 0;
    }
}
Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++)
         delete[] adjMatrix[i];
            delete[] adjMatrix;
}
void Graph::initializeState(){
	for(int i=0; i<this->vertexCount; i++){
		this->key[i] = 0; // 0=not in MST, 1=yes in MST
		this->distance[i]= INT_MAX; //initially distance is Max int
		this->parent[i] = -1;  // -1=no parent, else parent info
		                       //   
	}
}
void Graph::addEdgeUndirectedWeight(int i, int j, int cost) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = cost;
		adjMatrix[j][i] = cost;
    }
}
void Graph::removeEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = 0;
		adjMatrix[j][i] = 0;
    }
}
int Graph::isEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
        return adjMatrix[i][j];
    else{
		cout<<"Invalid vertex number.\n";
		return 0;
	}
}
void Graph::display(){
    int  u,v; //vertex
	cout<<"\t   ";
	for(u=0; u<vertexCount; u++){
		cout<<u<<" ";
	}	
    for(u=0; u<vertexCount; u++) {
        cout << "\nadj[" << (char) (u+48) << "] -> ";
        for(v=0; v<vertexCount; ++v) {
            cout << " " << adjMatrix[u][v];
        }
    }
    cout << "\n\n";
}
void Graph::showBasicInfo(){
	for(int i=0; i<vertexCount; i++){
		cout<<"node: "<<i<<" Key: "<<key[i]
			<<" distance: "<<distance[i]<<" parent: "<<parent[i]<<"\n";
	}
}
int Graph::isAllKeyTrue(){
	for(int i=0; i<this->vertexCount; i++){
		if(this->key[i]==0)
			return 0; // not MST yet
	}
	return 1; // MST done
		
}
int Graph::findMinDistanceNode(){
	int minDistant=INT_MAX; 
	int minDistantNode;	

	for(int i=0; i<vertexCount; i++) {
		if(minDistant > this->distance[i] && this->key[i]==0) 
		{ //0 means that node is not in MST  
			minDistantNode = i;		
			minDistant = this->distance[i];
			//cout<<"min: "<<minDistantNode<<"\n";
		}
	}
	//cout<<"Min Distant Node: "<<minDistantNode<<" Cost: "<<minDistant<<"\n";
	return minDistantNode;
}

void Graph::primsMST(int startNode){
	cout<<"\nPrims MST starts . . . \n";
	// initialization is done before call this method	
	this->distance[startNode]=0; //start node's distance is 0		
	int minDistanceNode, i;
	// 0 means MST is not formed yet;	
	while(!this->isAllKeyTrue()){
		//cout<<"-------------------------------\n";
		minDistanceNode = findMinDistanceNode();		
		this->key[minDistanceNode] = 1;
		cout<<"Prims MST Edges: "<<this->parent[minDistanceNode]
			<<"->"<<minDistanceNode<<"\n";

		this->mstCost += this->distance[minDistanceNode];

		for(i=0; i<vertexCount; i++){
			if(this->isEdge(minDistanceNode, i) && this->key[i]==0 
				&& this->distance[i]>this->adjMatrix[minDistanceNode][i]){
				
				
				this->distance[i] = adjMatrix[minDistanceNode][i];
				this->parent[i] = minDistanceNode;
			}
		}
		this->showBasicInfo(); // To visualize more clearly	
		// you can comment this to only show the edges of MST
	}
	cout<<"\nPrims MST cost: "<<this->mstCost<<"\n";

}

void main(){
	Graph g(10);
	g.addEdgeUndirectedWeight(0, 1, 4); g.addEdgeUndirectedWeight(0, 3, 1);	
	g.addEdgeUndirectedWeight(1, 2, 4); g.addEdgeUndirectedWeight(1, 9, 10);
	g.addEdgeUndirectedWeight(2, 4, 2); g.addEdgeUndirectedWeight(2, 5, 1);
	g.addEdgeUndirectedWeight(3, 1, 4); g.addEdgeUndirectedWeight(3, 7, 5);
	g.addEdgeUndirectedWeight(3, 9, 6); 
	g.addEdgeUndirectedWeight(4, 6, 2); 
	g.addEdgeUndirectedWeight(5, 6, 3); g.addEdgeUndirectedWeight(5, 8, 5);
	g.addEdgeUndirectedWeight(6, 8, 3); g.addEdgeUndirectedWeight(6, 9, 4);
	g.addEdgeUndirectedWeight(7, 9, 2); 
	g.addEdgeUndirectedWeight(8, 9, 3);
	g.initializeState();
	g.display();
	int startNode = 0;
	g.showBasicInfo();
	g.primsMST(startNode);
	//g.showBasicInfo();
	
}
 