// Ladders Problem Top Down DP

#include <iostream>
using namespace std;

int ladders_topdown(int n, int k, int dp[]){
    // base case
    if(n == 0){
        return 1;
    }

    // lookup
    if(dp[n]!=0){
        return dp[n];
    }

    // recursive case
    int ways=0;
    for(int i=1;i<=k;i++){
        if(n-i >= 0){
            ways += ladders_topdown(n-i,k,dp);
        }
    }
    dp[n]  = ways;
    return ways;
}

int main() {
    int n,k;
    int dp[100] = {0};
    cin>>n>>k;
    cout<<ladders_topdown(n,k,dp);
}
