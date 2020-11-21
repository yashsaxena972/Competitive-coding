// Stairs
/* You are climbing a stair case and it takes A steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

This is a specific version of the problem coding blocks/codes/dynamic programming/ laadders_tddp where k = 2;
*/

int Solution::climbStairs(int A) {
    
    int k = 2;
    int dp[100] = {0};
    dp[0] = 1;
    
    for(int i=1;i<=A;i++){
        dp[i] = 0;  // unnecessary
        for(int j=1;j<=k;j++){
            if(i>=j){
                dp[i] += dp[i-j];
            }
        }
    }

    return dp[A];
}
