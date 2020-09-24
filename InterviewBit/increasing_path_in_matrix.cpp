// Increasing Path in Matrix
/*

Given a 2D integer matrix A of size N x M.
From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].
The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.

 A = [  [1, 2, 3, 4]
        [2, 2, 3, 4]
        [3, 2, 3, 4]
        [4, 5, 6, 7]
     ]

Output 2:

 7

Explanation 2:

 Longest path is 1 2 3 4 5 6 7.      

*/

int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size(),m=A[0].size();
    vector<vector<int> >dp(n,vector(m,-1));
    dp[0][0]=1;
    for(int i=1;i<m;i++){
        if(A[0][i]>A[0][i-1])
            dp[0][i]=1+dp[0][i-1];
    }
    
    for(int i=1;i<n;i++){
        if(A[i][0]>A[i-1][0])
            dp[i][0]=1+dp[i][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(dp[i-1][j]==-1 && dp[i][j-1]==-1)
                return -1;
            if(A[i][j]>A[i-1][j]||A[i][j]>A[i][j-1])
                dp[i][j]=1+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    if(dp[n-1][m-1]==0)
        return -1;
    
    return dp[n-1][m-1];
}
