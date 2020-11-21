// Count Permutations of BST
/*

You are given two positive integers A and B. For all permutations of [1, 2, …, A], we create a BST. Count how many of these have height B.

Notes:

Values of a permutation are sequentially inserted into the BST by general rules i.e in increasing order of indices.
Height of BST is maximum number of edges between root and a leaf.
Return answer modulo 109 + 7.
Expected time complexity is worst case O(N4).
1 ≤ N ≤ 50

*/

int Solution::cntPermBST(int A, int B) {
    long long int mod = 1000000007;
    
    // vector<vector<lli>>dp(A+1,vector<lli>(B+2,0));
    vector<vector<long long int>>dp(A+1,vector<long long int>(B+2,0));
    vector<vector<long long int>>C(A+1,vector<long long int>(A+1));
        
    for(int i=0;i<=A;i++){
        C[i][0]=1;
        C[i][i]=1;
    }
    
    for(int i=1;i<=A;i++){
        for(int j=1;j<i;j++) {
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
        
    // dp[0][0]=1;
    dp[0][0]=1;
    for(int i=1;i<=(B+1);i++){
        dp[0][i]=1;
    }    
    
    for(int i=1;i<=A;i++){
        for(int j=1;j<=(B+1);j++){
            long long int  ans=0;
            for(int k=0;k<i;k++) {
                long long int t = ((dp[k][j-1]*dp[i-k-1][j-1]))%mod;
                if (j>1){
                    t = (t + mod - (dp[k][j-2]*dp[i-k-1][j-2])%mod)%mod;  
                } 
                t = (t*C[i-1][k])%mod;
                ans = (ans+t)%mod;
            }
            ans %= mod;
            // dp[a][h] = ans;
            dp[i][j] = (dp[i][j-1]+ans)%mod;
        }
    }
        // return (dp[A][B+1])%MOD;
    return (dp[A][B+1]-dp[A][B]+mod)%mod;
}
