#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Graph {
private:
      bool **adjMatrix;
      int vertexCount;
	  
	  int time;
	  int *state; 	  	  
	  int *startTime;
	  int *endTime;
	  int *parent;

public:
    Graph(int vertexCount);
    ~Graph();
	int getVertexCount();
    void addEdgeUndirected(int i, int j);
	void addEdgeDirected(int i, int j);
    void removeEdgeDirected(int i, int j);
	void removeEdgeUndirected(int i, int j);

    bool isEdge(int i, int j);
    void display();
	void initializeState();		
	void showStateInfo();
	void showStartAndEndTime();
	void showParentInfo();

	void DFS(); // it will start at from 0 if the vertex is 0, 1, 2...
	void DFS_Visit(int startNode);	
};
Graph::Graph(int vertexCount) {	
    this->vertexCount = vertexCount;
	this->time = 0;

	this->state = new int[vertexCount];		
	this->startTime = new int[vertexCount];
	this->endTime = new int[vertexCount];	
	this->parent = new int[vertexCount];

    adjMatrix = new bool*[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[i] = new bool[vertexCount];
           for (int j = 0; j < vertexCount; j++)
              adjMatrix[i][j] = false;
    }
}
Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++)
         delete[] adjMatrix[i];
            delete[] adjMatrix;
}
void Graph::initializeState(){
	for(int i=0; i<this->vertexCount; i++){
		this->state[i] = 0; // 0=undiscovered, 1=discovered, 2=processed				
	
		this->startTime[i]=-1;
		this->endTime[i]=-1;
		this->parent[i] = -1; // no parent
	}
}
void Graph::showStateInfo(){
	cout<<"Graph State Info...\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tNode State: "<<this->state[i]<<"\n";
	}
}
void Graph::showParentInfo(){
	cout<<"Graph parent Info...\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tNode's Parent: "<<this->parent[i]<<"\n";
	}
}
void Graph::showStartAndEndTime(){
	cout<<"\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tStart Time: "<<this->startTime[i]
			<<"\tEnd Time: "<<this->endTime[i]<<"\n";
	}
}
int Graph::getVertexCount(){
	return this->vertexCount;
}
void Graph::addEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = true;
		adjMatrix[j][i] = true;
    }
}
void Graph::addEdgeDirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = true;		
    }
}
void Graph::removeEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = false;
		adjMatrix[j][i] = false;
    }
}
void Graph::removeEdgeDirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = false;		
    }
}
bool Graph::isEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
        return adjMatrix[i][j];
    else{
		cout<<"Invalid vertex number.\n";
		return false;
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

void Graph::DFS(){
	cout<<"Start DFS...\n";
	int i, totalNode;
	totalNode = this->vertexCount;
	initializeState(); // init state to all 0, means undiscovered		
	
	for(i=0; i<totalNode; i++){
		if(this->state[i]==0){
			this->DFS_Visit(i);
		}
	}
	cout<<"\n";
} 
void Graph::DFS_Visit(int startNode){
	cout<<startNode<<"\t";	
	this->state[startNode] = 1; // discovered state
	this->time = this->time+1;
	
	this->startTime[startNode] = this->time;

	int i;
	for(i=0; i<this->vertexCount; i++){
		if(this->isEdge(startNode, i) && this->state[i]==0){
			this->parent[i] = startNode;
			this->DFS_Visit(i);
		}		
	}	
	this->state[startNode] = 2; //processed
	this->time = this->time+1;
	this->endTime[startNode] = this->time;	
}


void main(){
	Graph g(6); 
	g.initializeState();
	g.addEdgeDirected(0,1); g.addEdgeDirected(0,3);
	g.addEdgeDirected(1,2); 
	g.addEdgeDirected(2,3);
	g.addEdgeDirected(3,1);
	g.addEdgeDirected(4,2); g.addEdgeDirected(4,5);
	g.addEdgeDirected(5,5);
	g.display();
	g.DFS(); // it explores from node 0
	g.showParentInfo();
	g.showStartAndEndTime();
	
}
 