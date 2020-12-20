// Subset Sum Problem!
/*

Given an integer array A of size N.

You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

If there exist a subset then return 1 else return 0.

*/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    if(B==0)
        return true;
    if(n==0)
        return false;
    bool dp[n+1][B+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=B;j++){
            if(i==0 && j==0)
                dp[i][j]=true;
            else if(j==0)
                dp[i][j]=true;
            else if(i==0)
                dp[i][j]=false;
            else{
                if(j < A[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=( dp[i-1][j] || dp[i-1][j-A[i-1]] );
            }
        }
    }
    return dp[n][B];
}
