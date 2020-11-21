// Arrange II  or Horses in Stables
/*


You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
Example:


Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option. 

*/

int Solution::arrange(string A, int B) {
    int n = A.size();
	if(n<B)
	    return -1;
	    
	int dp[n+1][B+1];
	for(int i=0;i<=n;++i)
	    fill(dp[i],dp[i]+B+1,1e9);
	dp[0][0] = 0;

	for(int j=1;j<=B;++j)
	    for(int i=1;i<=n;++i)
	    {
	        int w = 0 ,b = 0;
	        for(int l=i;l>=1;--l)
	        {
	            w += (A[l-1]=='W');
	            b += (A[l-1]=='B');
	            dp[i][j] = min(dp[i][j],dp[l-1][j-1]+w*b);
	        }
	    }
	return dp[n][B];
}
