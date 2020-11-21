// Repeating Sub-Sequence
/*

Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.

Return an integer, 0 or 1:

    => 0 : False
    => 1 : True

Input 1:

 A = "abab"
Input 2:

 A = "abba"


Example Output
Output 1:

 1
Output 2:

 0    

*/

int Solution::anytwo(string A) {
    int n = A.length(); 
  
    // Create and initialize DP table 
    int dp[n+1][n+1]; 
    for (int i=0; i<=n; i++) 
        for (int j=0; j<=n; j++) 
            dp[i][j] = 0; 
  
    // Fill dp table (similar to LCS loops) 
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=n; j++) 
        { 
            // If characters match and indexes are  
            // not same 
            if (A[i-1] == A[j-1] && i != j) 
                dp[i][j] =  1 + dp[i-1][j-1];           
                       
            // If characters do not match 
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
        } 
    } 
    return dp[n][n] >=2?1:0;
}
