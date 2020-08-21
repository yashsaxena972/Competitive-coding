// Wines problem 2D DP

#include <iostream>
using namespace std;

int profit(int wines[], int i, int j, int y, int dp[][100]){
    // base case
    if(i>j){
        return 0;
    }

    // lookup
    if(dp[i][j]!=0){
        return dp[i][j];
    }

    // recursive case
    int op1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
    int op2 = wines[j]*y + profit(wines,i,j-1,y+1,dp);

    int ans = max(op1,op2);
    return ans;
}

int main() {
    int wines[] = {2,3,5,1,4};
    int n = sizeof(wines)/sizeof(int);
    int dp[100][100] = {0};
    cout<<profit(wines,0,n-1,1,dp);
}
