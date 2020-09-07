// Flip Array
/*

Given an array of positive elements, you have to flip the sign of some of its elements 
such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). 
Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.

*/

int Solution::solve(const vector<int> &A) {
    
    int n = A.size();
    // Array of unordered_map of size=2. 
    unordered_map<int, int> dp[2]; 
  
    // boolean variable used for toggling between maps 
    bool flag = 1; 
  
    // Calculate the sum of all elements of the array 
    int sum = 0; 
    for (int i = 0; i < n; i++) 
        sum += A[i]; 
  
    // Initializing first map(dp[0]) with INT_MAX because 
    // for i=0, there are no elements in the array to flip 
    for (int i = -sum; i <= sum; i++) 
        dp[0][i] = INT_MAX; 
  
    // Base Case 
    dp[0][0] = 0; 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = -sum; j <= sum; j++) { 
            dp[flag][j] = INT_MAX; 
            if (j - A[i - 1] <= sum && j - A[i - 1] >= -sum) 
                dp[flag][j] = dp[flag ^ 1][j - A[i - 1]]; 
            if (j + A[i - 1] <= sum 
                && j + A[i - 1] >= -sum 
                && dp[flag ^ 1][j + A[i - 1]] != INT_MAX) 
                dp[flag][j] = min(dp[flag][j], 
                                  dp[flag ^ 1][j + A[i - 1]] + 1); 
        } 
  
        // For toggling 
        flag = flag ^ 1; 
    } 
  
    // Required sum is minimum non-negative 
    // So, we iterate from i=0 to sum and find 
    // the first i where dp[flag ^ 1][i] != INT_MAX 
    for (int i = 0; i <= sum; i++) { 
        if (dp[flag ^ 1][i] != INT_MAX) 
            return dp[flag ^ 1][i]; 
    } 
  
    // In worst case we will flip max n-1 elements 
    return n - 1; 
}
