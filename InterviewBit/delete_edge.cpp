// Delete Edge!
/*

Given a undirected tree with N nodes labeled from 1 to N.
Each node has a certain weight assigned to it given by an integer array A of size N.
You need to delete an edge in such a way that Product between sum of weight of nodes in 
one subtree with sum of weight of nodes in other subtree is maximized.
Return this maximum possible product modulo 109 + 7.

*/

#define M 1000000007
void func(vector<int> adj[],int u,int parent,long& ans,long sum,vector<int> &A){
    int x=A[u-1];
    for(auto& ch:adj[u]){
        if(ch!=parent){
            func(adj,ch,u,ans,sum,A);
            x+=A[ch-1];
        }
    }

    A[u-1]=x;
    if(u==1) 
        return;
    
    ans=max(ans,(x*(sum-x))%M)%M;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n=A.size();
    vector<int> adj[n+1];
    for(auto& x:B){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    long sum=0;

    for(auto& x:A) 
        sum+=x;
    
    long ans=0;
    
    func(adj,1,0,ans,sum,A);
    
    return ans;
}
