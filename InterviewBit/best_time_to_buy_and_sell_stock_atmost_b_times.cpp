// Best Time to Buy and Sell Stock atmost B times
/*

Given an array of integers A of size N in which ith element is the price of the stock on day i.
You can complete atmost B transactions.
Find the maximum profit you can achieve.
NOTE: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    if(B==0 || n == 0)
        return 0;
        
    int max_profit = 0;
    if(B >= n/2) {
        for(int i = 1;i < n;i++) {
            max_profit += max(A[i] - A[i-1], 0);
        }
        return max_profit;
    }
    vector<vector<int>> dp(B+1, vector<int>(n + 1, 0));

    for(int i=1;i<=B;i++) {
        int maxDiff = -A[0];
        for(int j = 2;j <= n;j++) {
            dp[i][j] = max(dp[i][j-1], A[j-1] + maxDiff);
            maxDiff = max(maxDiff, dp[i-1][j] - A[j-1]);
        }
    }
    return dp[B][n];
}
