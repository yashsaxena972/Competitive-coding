// Capture Regions on Board
// Similar to Black Shapes
/*

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]

 Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]     

*/
 
bool memo[1002][1002];
vector<vector<char> >v;
int n,c;
void dfs(int i,int j){
    if(memo[i][j])return;
    if(i>=n||i<0||j<0||j>=c)return;
    if(v[i][j]=='X')return;
    memo[i][j]=true;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    memset(memo,0,sizeof(memo));
    n=A.size();
    c=A[0].size();
    v=A;
    for(int i=0;i<c;i++){
        if(A[0][i]!='X')dfs(0,i);
        if(A[n-1][i]!='X')dfs(n-1,i);
    }
    for(int i=0;i<n;i++){
        if(A[i][0]!='X')dfs(i,0);
        if(A[i][c-1]!='X')dfs(i,c-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<c;j++){
            if(!memo[i][j])A[i][j]='X';
        }
    }
}
