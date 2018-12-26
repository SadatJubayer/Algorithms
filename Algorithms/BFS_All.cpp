#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Graph {
private:
      bool **adjMatrix;
      int vertexCount;
	  // below attributes are for BFS
	  int *state; 
	  int *parent; 
	  int *level;	 
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
	void showLevelInfo();
	void showParentInfo();
	void showStateInfo();

	void printPath(int source, int destination);
    void BFS(int startNode);
	//-------------------------------------------	
};
Graph::Graph(int vertexCount) {	
    this->vertexCount = vertexCount;
	
	this->state = new int[vertexCount];
	this->parent = new int[vertexCount];
	this->level = new int[vertexCount];
	
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
		this->parent[i]= -1; //-1=no parent, else parent
		this->level[i] = -1;  // -1=no level info
	}
}
void Graph::showLevelInfo(){
	cout<<"Graph Level Info...\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tNode Level: "<<this->level[i]<<"\n";
	}
}
void Graph::showParentInfo(){
	cout<<"Graph Parent Info...\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tNode Parent: "<<this->parent[i]<<"\n";
	}
}
void Graph::showStateInfo(){
	cout<<"Graph State Info...\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tNode State: "<<this->state[i]<<"\n";
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
void Graph::BFS(int startNode){
	cout<<"Start BFS Member Function. . . \n";	
	initializeState();	// initialize state info for nodes, and undiscovered first

	this->state[startNode]=1; //discovered start node
	this->level[startNode] = 0; // start node level is 0
	queue<int> q;
	q.push(startNode); //enqueue
	int node;
	while(q.empty()!= true){
		node = q.front();		
		q.pop();
		cout<<node<<"   ";  //bfs traversed node

		for(int j=0; j<this->vertexCount; j++){			
			if(this->isEdge(node, j) && state[j]==0){								
				this->state[j]=1; //discovered	
				this->level[j] = this->level[node] + 1;
				this->parent[j] = node;
				
				q.push(j);								
			}			
		}// end for
		this->state[node]=2; //processed				
	}//end while
	cout<<"\n";
}
void Graph::printPath(int source, int destination){
	if(source == destination)
		cout<<source<<"\t";
	else if(this->parent[destination] == -1)
		cout<<"No Path Exists\n";
	else{
		printPath(source, this->parent[destination]);
		cout<<destination<<"\t";
	}	
}
void main(){
	Graph g(9);
	g.initializeState();
	g.addEdgeDirected(0,3); g.addEdgeDirected(0,1);
	g.addEdgeDirected(1,2); g.addEdgeDirected(1,4);
	g.addEdgeDirected(3,1); g.addEdgeDirected(3,4);
	g.addEdgeDirected(4,2); g.addEdgeDirected(4,6); g.addEdgeDirected(4,8);
	g.addEdgeDirected(5,3); g.addEdgeDirected(5,7);
	g.addEdgeDirected(6,5); g.addEdgeDirected(6,8);
	g.addEdgeDirected(7,6); 
	g.addEdgeDirected(8,7); 
	g.display();  // this is the graph that is in your lecture slide
	int startNode=0;
	g.BFS(startNode);
	g.showLevelInfo();
	g.showParentInfo();
	int destination = 7;
	g.printPath(startNode, destination);
	cout<<"\n";
}
 