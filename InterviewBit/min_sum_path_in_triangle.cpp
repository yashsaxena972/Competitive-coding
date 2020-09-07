// Min Sum Path in Triangle
/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // For storing the result in a 1-D array, 
    // and simultaneously updating the result. 
    int dp[A.size()]; 
    int n = A.size() - 1; 
  
    // For the bottom row 
    for (int i = 0; i < A[n].size(); i++)  
        dp[i] = A[n][i];     
  
    // Calculation of the remaining rows, 
    // in bottom up manner. 
    for (int i = A.size() - 2; i >= 0; i--)  
        for (int j = 0; j < A[i].size(); j++)  
            dp[j] = A[i][j] + min(dp[j], dp[j + 1]); 
  
    // return the top element 
    return dp[0]; 
}
