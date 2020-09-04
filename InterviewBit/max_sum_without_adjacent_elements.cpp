// Max Sum Without Adjacent Elements
/*

Given a rectangular grid of dimension 2 x n. We need to find out the maximum sum such that no two chosen numbers are adjacent, vertically, diagonally or horizontally.

*/

int Solution::adjacent(vector<vector<int> > &A) {
    
    int n = A[0].size();
    // Sum including maximum element of first column 
    int incl = max(A[0][0], A[1][0]); 
  
    // Not including first column's element 
    int excl = 0, excl_new; 
  
    // Traverse for further elements 
    for (int i = 1; i<n; i++ ) 
    { 
        // Update max_sum on including or excluding 
        // of previous column 
        excl_new = max(excl, incl); 
  
        // Include current column. Add maximum element 
        // from both row of current column 
        incl = excl + max(A[0][i], A[1][i]); 
  
        // If current column doesn't to be included 
        excl = excl_new; 
    } 
  
    // Return maximum of excl and incl 
    // As that will be the maximum sum 
    return max(excl, incl); 
}
