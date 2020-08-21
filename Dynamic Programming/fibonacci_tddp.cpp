// Fibonacci using Top Down DP

#include <iostream>
using namespace std;

int fib(int n, int dp[]){
    // base cases
    if(n == 0 || n == 1){
        return n;
    }

    // recursive cases
    if(dp[n]!=0){
        // solution already calculated
        return dp[n];
    }

    int ans;
    ans = fib(n-1,dp) + fib(n-2,dp);
    dp[n] = ans;

    return ans;
}

int main() {
    int n;
    cin>>n;
    int dp[100] = {0};

    cout<<fib(n,dp);
}
