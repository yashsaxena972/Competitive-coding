// Ladders problem Bottom Up DP

#include <iostream>
using namespace std;

int ladders_bottomup(int n, int k){
    int dp[100] = {0};
    dp[0] = 1;
    
    for(int i=1;i<=n;i++){
        dp[i] = 0;  // unnecessary
        for(int j=1;j<=k;j++){
            if(i>=j){
                dp[i] += dp[i-j];
            }
        }
    }

    return dp[n];
}

int main() {
    int n,k;
    cin>>n>>k;
    cout<<ladders_bottomup(n,k);
}
