// Water Flow
/*

Given an N x M matrix A of non-negative integers representing the height of each 
unit cell in a continent, the "Blue lake" touches the left and top edges of the 
matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to 
another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.

 Blue Lake ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
           *   *   *   *   * Red Lake
 Water can flow to both lakes from the cells denoted in parentheses.

*/

int x[4]={-1,1,0,0};
int y[4]={0,0,1,-1};

void dfs(int i,int j, vector<vector<bool>> &visited, vector<vector<int>> &cnt, vector<vector<int> > &A){
    visited[i][j]=true;
    cnt[i][j]++;
    int n=visited.size();
    int m=visited[0].size();
    for(int k=0;k<4;k++){
        int x_new=i+x[k];
        int y_new=j+y[k];
        if((x_new>=0&&x_new<n)&&(y_new>=0&&y_new<m)){
            if((!visited[x_new][y_new])&&(A[x_new][y_new]>=A[i][j])){
                dfs(x_new,y_new,visited,cnt,A);
            }
        }
    }
}   

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<bool>> visited(n,vector(m,false));
    vector<vector<int>> cnt(n,vector(m,0));
    for(int i=0;i<m;i++){
        if(!visited[0][i]){
            dfs(0,i,visited,cnt,A);
        }
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i][0]){
            dfs(i,0,visited,cnt,A);
        }
    }
    
    visited.assign(n,vector(m,false));
    for(int i=0;i<m;i++){
        if(!visited[n-1][i]){
            dfs(n-1,i,visited,cnt,A);
        }
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i][m-1]){
            dfs(i,m-1,visited,cnt,A);
        }
    }
    
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cnt[i][j]==2)
                res++;
        }
    }
    return res;
}
