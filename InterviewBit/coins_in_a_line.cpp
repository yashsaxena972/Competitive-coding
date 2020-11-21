// Coins in a Line
/*

There are A coins (Assume A is even) in a line.
Two players take turns to take a coin from one of the ends of the line until there are no more coins left.
The player with the larger amount of money wins, Assume that you go first.
Return the maximum amount of money you can win.
NOTE: You can assume that opponent is clever and plays optimally.

*/

int Solution::maxcoin(vector<int> &A) {
    
    int n = A.size();
    // Create a table to store 
    // solutions of subproblems 
    int table[n][n]; 
  
    // Fill table using above 
    // recursive formula. Note 
    // that the table is filled 
    // in diagonal fashion (similar 
    // to http:// goo.gl/PQqoS), 
    // from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
            // Here x is value of F(i+2, j), 
            // y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive 
            // formula 
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max( A[i] + min(x, y), A[j] + min(y, z)); 
        } 
    } 
  
    return table[0][n - 1];
}
