// Coin Sum Infinite
/*

You are given a set of coins S. In how many ways can you make sum N assuming you have infinite 
amount of each coin in the set.
Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).
Example :
Input : 
    S = [1, 2, 3] 
    N = 4
Return : 4
Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}  
Note that the answer can overflow. So, give us the answer % 1000007

*/

int Solution::coinchange2(vector<int> &A, int B) {
    
    int m = A.size();
    // table[i] will be storing the number of solutions for 
    // value i. We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case (n = 0) 
    int dp[B+1] = {0}; 
  
    // Base case (If given value is 0) 
    dp[0] = 1; 
  
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i=0; i<m; i++) 
        for(int j=A[i]; j<=B; j++) 
            dp[j] = (dp[j] + dp[j-A[i]])%1000007; 
  
    return dp[B]%1000007;
}
