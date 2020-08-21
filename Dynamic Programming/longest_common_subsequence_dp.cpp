// Longest Common Subsequence Bottom Up DP

#include <bits/stdc++.h>
using namespace std;

int LCS(char X[], char Y[]){
    int m = strlen(X);
    int n = strlen(Y);
    int dp[100][100];

    // Base cases
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }

    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int q = 0;
            if(X[i-1] == Y[j-1]){
                q = 1 + dp[i-1][j-1];
            }
            else{
                q = max(dp[i-1][j], dp[i][j-1]);
            }
            dp[i][j] = q;
        }
    }

    return dp[m][n];
}

int main() {
    char X[100],Y[100];
    cin>>X>>Y;

    cout<<LCS(X,Y);
}
