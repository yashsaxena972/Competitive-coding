// Rod cutting to maximize profit Top Down DP

#include <iostream>
using namespace std;

int maxProfit(int totalLength, int profits[], int dp[]){
    // base case
    if(totalLength == 0){
        return 0;
    }

    // lookup
    if(dp[totalLength]!=0){
        return dp[totalLength];
    }

    // recursive case
    int best=0;
    for(int i=1;i<=totalLength;i++){
        int currProfit = profits[i] + maxProfit(totalLength-i,profits,dp);
        best = max(best, currProfit);
    }

    dp[totalLength] = best;
    return best;
}

int main() {
    int totalLength,profits[100];
    cin>>totalLength;
    for(int i=1;i<=totalLength;i++){
        cin>>profits[i];
    }

    int dp[100] = {0};
    cout<<maxProfit(totalLength,profits,dp);
}
