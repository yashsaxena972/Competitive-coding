// Chain of Pairs
/*

Given a N * 2 array A where (A[i][0], A[i][1]) represents the ith pair.
In every pair, the first number is always smaller than the second number.
A pair (c, d) can follow another pair (a, b) if b < c , similarly in this way a chain of pairs can be formed.
Find the length of the longest chain subsequence which can be formed from a given set of pairs.

*/

int dp[1001][10001];

int recur(int x,int y,vector<vector <int>> &a)
{
    if(x>=a.size()) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    if(a[x][0]>y) return dp[x][y]=max(1+recur(x+1,a[x][1],a),recur(x+1,y,a));
    else return dp[x][y]=recur(x+1,y,a);
}

int Solution::solve(vector<vector<int> > &A) {
    for(int i=0;i<1001;i++) 
        for(int j=0;j<=10000;j++) 
            dp[i][j]=-1;
            
    return recur(0,0,A);
}
