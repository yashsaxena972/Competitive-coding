// Unique Binary Search Trees II
/*

Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

Input 1:
    A = 3

Output 1:
    5

Explanation 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

int Solution::numTrees(int A) {
    int dp[A+2] = {0};
    
    dp[0] = 1, dp[1] = 1;
    
    for(int i=2; i<=A; i++)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i] += (dp[j-1] * dp[i-j]);
        }
    }
    
    return dp[A];
}
