// Longest Common Subsequence
/*

Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.

*/

int Solution::solve(string A, string B) {
    int m = A.length();
    int n = B.length();
    int dp[1000][1000];

    // Base cases
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }

    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int q = 0;
            if(A[i-1] == B[j-1]){
                q = 1 + dp[i-1][j-1];
            }
            else{
                q = max(dp[i-1][j], dp[i][j-1]);
            }
            dp[i][j] = q;
        }
    }

    return dp[m][n];
}
