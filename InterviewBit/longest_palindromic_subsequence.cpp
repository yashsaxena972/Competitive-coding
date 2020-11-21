// Longest Palindromic Subsequence
/*

Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

*/

int Solution::solve(string A) {
    int n = A.length();
    int i, j, cl; 
    int dp[n][n];  // Create a table to store results of subproblems 
  
  
    // Strings of length 1 are palindrome of lentgh 1 
    for (i = 0; i < n; i++) 
        dp[i][i] = 1; 
  
    // Build the table. Note that the lower diagonal values of table are 
    // useless and not filled in the process. The values are filled in a 
    // manner similar to Matrix Chain Multiplication DP solution (See 
    // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of 
    // substring 
    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (A[i] == A[j] && cl == 2) 
               dp[i][j] = 2; 
            else if (A[i] == A[j]) 
               dp[i][j] = dp[i+1][j-1] + 2; 
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
        } 
    } 
  
    return dp[0][n-1]; 
}
