// Dungeon Princess  or  Minimum Initial Points to Reach Destination
/*

Given a grid with each cell consisting of positive, negative or no points i.e, zero points. 
We can move across a cell only if we have positive points ( > 0 ). Whenever we pass through a cell, 
points in that cell are added to our overall points. We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0).

Constraints :

From a cell (i, j) we can move to (i+1, j) or (i, j+1).
We cannot move from (i, j) if your overall points at (i, j) is <= 0.
We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

*/

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    
    int R = A.size();
    int C = A[0].size();
    // dp[i][j] represents the minimum initial points player 
    // should have so that when starts with cell(i, j) successfully 
    // reaches the destination cell(m-1, n-1) 
    int dp[R][C]; 
    int m = R, n = C; 
  
    // Base case 
    dp[m-1][n-1] = A[m-1][n-1] > 0? 1: abs(A[m-1][n-1]) + 1; 
  
    // Fill last row and last column as base to fill 
    // entire table 
    for (int i = m-2; i >= 0; i--) {
        dp[i][n-1] = max(dp[i+1][n-1] - A[i][n-1], 1); 
    }
        
    for (int j = n-2; j >= 0; j--) {
        dp[m-1][j] = max(dp[m-1][j+1] - A[m-1][j], 1); 
    }
  
    // fill the table in bottom-up fashion 
    for (int i=m-2; i>=0; i--) 
    { 
        for (int j=n-2; j>=0; j--) 
        { 
            int min_points_on_exit = min(dp[i+1][j], dp[i][j+1]); 
            dp[i][j] = max(min_points_on_exit - A[i][j], 1); 
        } 
     } 
  
     return dp[0][0]; 
}
