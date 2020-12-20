// Max edge queries!
/*

Given a tree with N nodes numbered from 1 to N.

Each edge is bi-directional and has a certain weight assigned to it.

You are given Q queries, in each query you are given two integers u and v and you are required to find the maximum weighted edge in a simple path from u to v.

You have to return the weight of the edge for each queries.

*/

void dfs(vector<int> *adj, vector<vector<int>> &dp, vector<vector<int>> &mx, map<vector<int>,int> &m, vector<int> &level, int index, int parent, int h){
    level[index]=h;
    dp[index][0]=parent;
    for(auto i: adj[index]){
        if(i!=parent){
            dfs(adj,dp,mx,m,level,i,index,h+1);
            mx[i][0]=m[{index,i}];
        }
    }
}
int lca(vector<vector<int>> &dp, vector<vector<int>> &mx, vector<int> &level, map<vector<int>,int> &m, int u, int v){
    int d=level[u]-level[v];
    if(d<0){
        int temp=u;
        u=v;
        v=temp;
        d=abs(d);
    }
    int an=INT_MIN;
    while(d>0){
        int i=log2(d);
        an=max(an,mx[u][i]);
        u=dp[u][i];
        d-=(1<<i);
    }
    if(u==v) return an;
    int n=ceil(log2(level.size()-1));
    for(int i=n;i>=0;i--){
        if(dp[u][i]!=dp[v][i] && dp[u][i]!=-1){
            an=max(an,max(mx[u][i],mx[v][i]));
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return max(an,max(mx[u][0],mx[v][0]));
}

vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n=A.size();
    n+=1;
    vector<int> adj[n+1];
    map<vector<int>,int> m;
    for(int i=0;i<n-1;i++){
        int u,v;
        u=A[i][0];
        v=A[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        m[{u,v}]=A[i][2];
        m[{v,u}]=A[i][2];
    }
    vector<int> level(n+1,0);
    int lg=ceil(log2(n));
    vector<vector<int>> dp(n+1,vector<int>(lg+1,-1));
    vector<vector<int>> mx(n+1,vector<int>(lg+1,-1));
    dfs(adj,dp,mx,m,level,1,-1,0);
    for(int i=1;i<=lg;i++){
        for(int j=1;j<=n;j++){
            if(dp[j][i-1]!=-1){
                dp[j][i]= dp[dp[j][i-1]][i-1];
                mx[j][i] =max(mx[j][i-1],mx[dp[j][i-1]][i-1]);
            }
        }
    }
    vector<int> answer;
    for(int i=0;i<B.size();i++){
        int u,v;
        u=B[i][0];
        v=B[i][1];
        answer.push_back(lca(dp,mx,level,m,u,v));
    }
    return answer;
}
