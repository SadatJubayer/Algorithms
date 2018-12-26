#include<iostream>
#include<queue>
#include<stack>
#include <limits>

using namespace std;

class Graph {
private:
      int **adjMatrix;  int **kruskalMatrix;
      int vertexCount;
	  // below attributes are for Prims

	  //int *key;
	  //int *distance;
	  //int *parent;

	  int mstCost;
	  int *setParent;

public:
    Graph(int vertexCount);
    ~Graph();
	void addEdgeUndirectedWeight(int i, int j, int cost);
	void removeEdgeUndirected(int i, int j);
    int isEdge(int i, int j);
    void display();
	void initializeState();


	void kruskalMST();

	//void showBasicInfo();
	//int isAllKeyTrue();  //0 means not MST, 1 means MST
	//int findMinEdgeNode();

	int find(int i);
	int uni(int i,int j);
	//---------------------------

};
Graph::Graph(int vertexCount) {
    this->vertexCount = vertexCount;

	//this->key = new int[vertexCount];
	//this->distance = new int[vertexCount];
	//this->parent = new int[vertexCount];

	this->setParent = new int[vertexCount];
	this->mstCost = 0;

	kruskalMatrix = new int*[vertexCount];

    adjMatrix = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[i] = new int[vertexCount];
		kruskalMatrix[i] = new int[vertexCount];
		for (int j = 0; j < vertexCount; j++){
			adjMatrix[i][j] = 0;
			kruskalMatrix[i][j] = 0;
		}
    }
}
Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++)
         delete[] adjMatrix[i];
            delete[] adjMatrix;
}
void Graph::initializeState(){
	for(int i=0; i<this->vertexCount; i++){
		//this->key[i] = 0; // 0=not in MST, 1=yes in MST
		//this->distance[i]= INT_MAX; //initially distance is Max int
		//this->parent[i] = -1;  // -1=no parent, else parent info

		this->setParent[i]=0;// set all the array values to 0, so it will not fall
							// in an infinite loop
	}
}
void Graph::addEdgeUndirectedWeight(int i, int j, int cost) {
    if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
		adjMatrix[i][j] = cost;
		adjMatrix[j][i] = cost;

		kruskalMatrix[i][j] = cost;
		kruskalMatrix[j][i] = cost;
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
/*void Graph::showBasicInfo(){
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
int Graph::findMinEdgeNode(){
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
*/

int Graph::find(int i){
	while(setParent[i]){  // find the parent
		i = setParent[i];
	}
	return i;
}
int Graph::uni(int i,int j){
	if(i != j){  // belogs to different set
		setParent[j] = i; return 1;
	}
	return 0; // same set
}

void Graph::kruskalMST(){
	cout<<"\nKruskal MST starts . . . \n";
	int totalEdge=0;
	int i,j; int minEdgeWeight; int ii, jj; // min edge nodes
	while(totalEdge<vertexCount-1){
		//cout<<"Find minimum edge\n";
		minEdgeWeight = INT_MAX;
		for(i=0; i<vertexCount; i++) {
			for(j =0; j<vertexCount; j++) {
				if(minEdgeWeight > kruskalMatrix[i][j] && kruskalMatrix[i][j] !=0){
					minEdgeWeight = kruskalMatrix[i][j]; // select the minimum
					ii = i; jj = j; // track the i and j location
				}
			}
		}
		//cout<<"i and j is: "<<ii<<"   "<<jj<<"\n";
		kruskalMatrix[ii][jj] = 0; // so that, that minimum edge will not come again.
		kruskalMatrix[jj][ii] = 0;
		int p1, p2;
		p1 = find(ii);
		p2 = find(jj);
		if(uni(p1, p2)){
			cout<<"Kruskal Edge: "<<ii<<" and "<<jj<<"\n";
			mstCost += adjMatrix[ii][jj];
			totalEdge = totalEdge+1;
		}else{
			cout<<"NOT Kruskal Edge: "<<ii<<" and "<<jj<<", loop\n";
		}

	}
	cout<<"\nKruskal MST cost: "<<this->mstCost<<"\n";

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
	//g.showBasicInfo();
	g.kruskalMST();
	//g.showBasicInfo();

}
