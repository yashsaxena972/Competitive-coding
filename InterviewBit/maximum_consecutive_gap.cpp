// Maximum Consecutive Gap
/*

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

*/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    // Find maximum and minimum in arr[] 
    int maxVal = A[0], minVal = A[0]; 
    for (int i = 1; i < n; i++) { 
        maxVal = max(maxVal, A[i]); 
        minVal = min(minVal, A[i]); 
    }
    
    // Arrays to store maximum and minimum values 
    // in n-1 buckets of differences. 
    int maxBucket[n - 1]; 
    int minBucket[n - 1]; 
    fill_n(maxBucket, n - 1, INT_MIN); 
    fill_n(minBucket, n - 1, INT_MAX);
    
    // Expected gap for every bucket. 
    float delta = (float)(maxVal - minVal) / (float)(n - 1); 
    
    // Traversing through array elements and 
    // filling in appropriate bucket if bucket 
    // is empty. Else updating bucket values.  
    for (int i = 0; i < n; i++) { 
        if (A[i] == maxVal || A[i] == minVal) 
            continue; 
  
        // Finding index of bucket. 
        int index = (float)(floor(A[i] - minVal) / delta); 
  
        // Filling/Updating maximum value of bucket 
        if (maxBucket[index] == INT_MIN) 
            maxBucket[index] = A[i]; 
        else
            maxBucket[index] = max(maxBucket[index], A[i]); 
  
        // Filling/Updating minimum value of bucket 
        if (minBucket[index] == INT_MAX) 
            minBucket[index] = A[i]; 
        else
            minBucket[index] = min(minBucket[index], A[i]); 
    }
    
    // Finding maximum difference between maximum value 
    // of previous bucket minus minimum of current bucket. 
    int prev_val = minVal; 
    int max_gap = 0; 
    for (int i = 0; i < n - 1; i++) { 
        if (minBucket[i] == INT_MAX) 
            continue; 
        max_gap = max(max_gap, minBucket[i] - prev_val); 
        prev_val = maxBucket[i]; 
    } 
    max_gap = max(max_gap, maxVal - prev_val); 
  
    return max_gap;
}
