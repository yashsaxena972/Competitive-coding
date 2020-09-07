// Tushar's Birthday Party (Type of Knapsack problem)
/*

As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.
Input Format

Friends : List of integers denoting eating capacity of friends separated by space.
Capacity: List of integers denoting filling capacity of each type of dish.
Cost :    List of integers denoting cost of each type of dish.

*/

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int t = *max_element(A.begin(),A.end());
    int dp[t+1];
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    int k = 0;
    for(int i:B){
        for(int j = i; j <=t; j++){
            if(dp[j-i]!=-1)
                dp[j] = dp[j]==-1 ? dp[j-i]+C[k] : min(dp[j],dp[j-i]+C[k]);
        }
        k++;
    }
    int ans = 0;
    for (int i:A) 
        ans+=dp[i];
    
    return ans;
}
