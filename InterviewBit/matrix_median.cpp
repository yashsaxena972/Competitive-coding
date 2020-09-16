// Matrix Median
/*

Given a matrix of integers A of size N x M in which each row is sorted.
Find an return the overall median of the matrix A
Note: No extra memory is allowed.
Note: Rows are numbered from top to bottom and columns are numbered from left to right.

*/

int Solution::findMedian(vector<vector<int> > &A) {
    
    int r = A.size();
    int c = A[0].size();
    int min = INT_MAX, max = INT_MIN; 
    for (int i=0; i<r; i++) 
    { 
        // Finding the minimum element 
        if (A[i][0] < min) 
            min = A[i][0]; 
  
        // Finding the maximum element 
        if (A[i][c-1] > max) 
            max = A[i][c-1]; 
    } 
  
    int desired = (r * c + 1) / 2; 
    while (min < max) 
    { 
        int mid = min + (max - min) / 2; 
        int place = 0; 
  
        // Find count of elements smaller than mid 
        for (int i = 0; i < r; ++i) 
            place = place + upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin(); 
        if (place < desired) 
            min = mid + 1; 
        else
            max = mid; 
    } 
    return min;
}
