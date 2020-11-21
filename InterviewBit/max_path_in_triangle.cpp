// Maximum Path in Triangle
// Same as Min sum path in triangle, just replace min with max
/*

Given a 2D integer array A of size  N * N  representing a triangle of numbers.
Find the maximum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

*/

int Solution::solve(vector<vector<int> > &A) {
    int dp[A.size()]; 
    int n = A.size() - 1; 
  
    // For the bottom row 
    for (int i = 0; i < A[n].size(); i++)  
        dp[i] = A[n][i];     
  
    // Calculation of the remaining rows, 
    // in bottom up manner. 
    for (int i = A.size() - 2; i >= 0; i--)  
        for (int j = 0; j < A[i].size(); j++)  
            dp[j] = A[i][j] + max(dp[j], dp[j + 1]); 
  
    // return the top element 
    return dp[0]; 
}
