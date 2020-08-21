// Coins change problem Top Down DP

#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, int coins[], int t, int dp[]){
    // base case
    if(n==0){
        return 0;
    }

    // lookup
    if(dp[n]!=0){
        return dp[n];
    }

    //recursive case
    int ans = INT_MAX;

    for(int i=0;i<t;i++){
        if(n-coins[i] >= 0){
            int subproblem = minCoins(n-coins[i],coins,t,dp);
            ans = min(ans, subproblem+1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

int main() {
    int n=15; // change that you want
    int t=3;  // no. of denominations available
    int coins[] = {1,7,10}; // denominations available
    int dp[100] = {0};

    cout<<minCoins(n,coins,t,dp);

}
