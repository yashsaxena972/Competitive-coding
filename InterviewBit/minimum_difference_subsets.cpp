// Minimum Difference Subsets!
/*

Given an integer array A containing N integers.

You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

Find and return this minimum possible absolute difference.

*/

int Solution::solve(vector<int> &A) {
    int i,j;
    long long sum=0,n=A.size();
    for(auto i:A)
        sum += i;
    vector<long long>dp(sum+1);
    long long mn=sum;
        
    dp[0]=1;
    for(i=1;i<=n;i++){
        for(j=sum;j>=0;j--)
            if(A[i-1]<=j)
                dp[j]=dp[j-A[i-1]] || dp[j];
    }
    
    for(i=0;i<=sum/2;i++){
        if(dp[i])
            mn = min(mn,sum-2*i);
    }
    
    return mn;
}
