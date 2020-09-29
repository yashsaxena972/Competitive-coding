// Common Child    or   Longest Common Subsequence
/*

A string is said to be a child of a another string if it can be formed by 
deleting 0 or more characters from the other string. Given two strings of 
equal length, what's the longest string that can be constructed such that it is a child of both?

For example, ABCD and ABDC have two children with maximum length 3, ABC and ABD. 
They can be formed by eliminating either the D or C from both strings. Note that 
we will not consider ABCD as a common child because we can't rearrange characters and ABCD  ABDC.

*/

static int dp[5001][5001];
// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int i,j;

    // base cases
    for(i=0;i<=m;i++){
        dp[i][0] = 0;
    }

    for(i=0;i<=n;i++){
        dp[0][i] = 0;
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}