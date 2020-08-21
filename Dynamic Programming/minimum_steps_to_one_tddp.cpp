// Minimun steps to 1 Top Down DP
// You have 3 options: 
// 1. n -> n/3
// 2. n -> n/2
// 3. n -> n-1

#include <bits/stdc++.h>
using namespace std;

int minSteps(int n, int dp[]){
    // base case
    if(n==1){
        return 0;
    }

    // recursive cases
    if(dp[n]!=0){
        return dp[n];
    }
    
    int op1,op2,op3;
    op1 = op2 = op3 = INT_MAX;
    if(n%3 == 0){
        op1 = minSteps(n/3,dp);
    }
    if(n%2 == 0){
        op2 = minSteps(n/2,dp);
    }
    op3 = minSteps(n-1,dp);
    
    int ans = min(min(op1,op2),op3) + 1;
    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    cin>>n;

    int dp[100] = {0};
    cout<<minSteps(n,dp);
}
