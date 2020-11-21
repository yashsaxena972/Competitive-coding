// Interleaving Strings
/*

Given A, B, C, find whether C is formed by the interleaving of A and B.

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.

*/

int Solution::isInterleave(string A, string B, string C) {
    // Find lengths of the two strings 
    int M = A.length(), N = B.length(); 
  
    // Let us create a 2D table 
    // to store solutions of 
    // subproblems.  C[i][j] will 
    // be true if C[0..i+j-1] 
    // is an interleaving of 
    // A[0..i-1] and B[0..j-1]. 
    bool dp[M + 1][N + 1]; 
  
    // Initialize all values as false. 
    memset(dp, 0, sizeof(dp)); 
  
    // C can be an interleaving of 
    // A and B only of the sum 
    // of lengths of A & B is equal 
    // to the length of C. 
    if ((M + N) != C.length()) 
        return false; 
  
    // Process all characters of A and B 
    for (int i = 0; i <= M; ++i) { 
        for (int j = 0; j <= N; ++j) { 
            // two empty strings have an 
            // empty string as interleaving 
            if (i == 0 && j == 0) 
                dp[i][j] = true; 
  
            // A is empty 
            else if (i == 0) { 
                if (B[j - 1] == C[j - 1]) 
                    dp[i][j] = dp[i][j - 1]; 
            } 
  
            // B is empty 
            else if (j == 0) { 
                if (A[i - 1] == C[i - 1]) 
                    dp[i][j] = dp[i - 1][j]; 
            } 
  
            // Current character of C matches 
            // with current character of A, 
            // but doesn't match with current 
            // character of B 
            else if ( A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) 
                dp[i][j] = dp[i - 1][j]; 
  
            // Current character of C matches 
            // with current character of B, 
            // but doesn't match with current 
            // character of A 
            else if ( A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
                dp[i][j] = dp[i][j - 1]; 
  
            // Current character of C matches 
            // with that of both A and B 
            else if ( A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]); 
        } 
    } 
  
    return dp[M][N];
}
