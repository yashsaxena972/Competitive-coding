// Single source shortest distance
// ie, shortest distance of a given node (or every node) from source
// This code is a modified version of BFS traversal

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T,list<T>> l;
public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }    

    void shortestDistance(T src){
        map<T,int> dist;
        queue<T> q;

        // Initially, assign all distances to infinity
        for(auto node_pairs:l){
            T node = node_pairs.first;
            dist[node] = INT_MAX;
        }

        // Now override the distance of source as 0
        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            //cout<<node<<" ";

            for(auto nbrs:l[node]){
                if(dist[nbrs] == INT_MAX){
                    // if the distance was previously 0, update it to 1 + distance of parent from source
                    q.push(nbrs);
                    dist[nbrs] = dist[node] + 1;
                }
            }
        }

        // displaying the shortest distances of all nodes from the source
        for(auto node_pairs:l){
            T node = node_pairs.first;
            cout<<"Distance of node "<<node<<" from source is "<<dist[node]<<endl;
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(0,3);

    g.shortestDistance(0);
    return 0;
}
