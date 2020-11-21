// Counting Subarrays!
/*

Given an array A of N non-negative numbers and you are also given non-negative number B.

You need to find the number of subarrays in A having sum less than B. We may assume that there is no overflow.

*/

int Solution::solve(vector<int> &A, int B) {
    int start = 0, end = 0, count = 0, sum = A[0]; 
    int n = A.size();
  
    while (start < n && end < n) { 
  
        // If sum is less than k, 
        // move end by one position. 
        // Update count and sum 
        // accordingly. 
        if (sum < B) { 
            end++; 
  
            if (end >= start) 
                count += end - start; 
  
            // For last element, 
            // end may become n 
            if (end < n) 
                sum += A[end]; 
        } 
  
        // If sum is greater than or 
        // equal to k, subtract 
        // arr[start] from sum and 
        // decrease sliding window by 
        // moving start by one position 
        else { 
            sum -= A[start]; 
            start++; 
        } 
    } 
  
    return count; 
}
