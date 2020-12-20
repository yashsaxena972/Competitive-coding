// Ways to Decode
/*

A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.

*/


int Solution::numDecodings(string A) {
    
    vector<int> dp(A.size()+1,0);
    dp[0]=1;
    if(A[0]=='0')
        dp[1]=0;
    else
        dp[1]=1;
    for(int i=2;i<=A.size();i++)
    {
        if(A[i-1]>'0')
            dp[i]=dp[i-1];
        if((A[i-2]=='1') || (A[i-2]=='2' && A[i-1]<'7'))
            dp[i]=(dp[i-2]+dp[i])%1000000007;
    }
    return dp[A.size()];
}
