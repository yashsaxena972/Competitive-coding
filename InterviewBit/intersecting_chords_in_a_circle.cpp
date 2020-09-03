// Intersecting Chords in a Circle
/*

Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.

Two ways are different if there exists a chord which is present in one way and not in other.

Return the answer modulo 109 + 7.

Input 1:
    A = 1

Output 1:
    1

Explanation 1:
    If points are numbered 1 to 2 in clockwise direction, then different ways to draw chords are:
    {(1-2)} only.
    So, we return 1.

Input 2:
    A = 2

Output 2:
    2

Explanation 2:
    If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
    {(1-2), (3-4)} and {(1-4), (2-3)}.
    So, we return 2.

*/

int Solution::chordCnt(int A) {
    // n = no of points required 
    int n = 2 * A; 
      
    // dp array containing the sum 
    long long int dp[n + 1]={ 0 }; 
    dp[0] = 1; 
    dp[2] = 1; 
    for (int i=4;i<=n;i+=2){ 
        for (int j=0;j<i-1;j+=2){  
              
          dp[i] = (dp[i] + (dp[j]*dp[i-2-j]))%1000000007; 
        } 
    }  
  
    // returning the required number 
    return dp[n]%1000000007;
}
