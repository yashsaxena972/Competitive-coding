#include <iostream>
#include<list>
using namespace std;

class Graph{
    int V; // denotes the number of nodes in the graph
    list<int> *l; // Pointer to an array of lists
   
public:
    // Constructor
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        // assuming all edges are bidirectional
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<"Vertex "<<i<<"-> ";
            for(int itr:l[i]){
                cout<<itr<<" ";
            }
            cout<<endl;
        }
    }

}; 

int main() {
    
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.print();
    return 0;
}
