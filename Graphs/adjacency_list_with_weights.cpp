#include <bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<string,list<pair<string,int>>> l;
public:
    void addEdge(string x, string y, bool bidirectional, int wt){
        l[x].push_back(make_pair(y,wt));
        
        // if the edge is bidirectional
        if(bidirectional){
            l[y].push_back(make_pair(x,wt));
        }
    }    

    void print(){
        // each entry is a key value pair of a string and a list of pairs
        for(auto itr:l){
            string city = itr.first;
            list<pair<string,int>> nbrs = itr.second;
            cout<<"City "<<city<<" -> ";
            
            for(auto itr2:nbrs){
                cout<<"("<<itr2.first<<","<<itr2.second<<")"<<",";
            }
            cout<<endl;
        }
    }

};

int main() {
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.print();
    return 0;
}
