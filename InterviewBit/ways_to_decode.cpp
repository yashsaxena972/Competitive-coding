// Ways to Decode
/*

A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.

Explanation 1:

 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.
Explanation 2:

 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.

*/

// InterviewBit Solution
int Solution::numDecodings(string A) {
    
    int n=A.length();
    
    vector<int>v;
    
    for(int i=0;i<n;i++){
        v.push_back(A[i]-'0');   
    }
     
    if(v[0]==0){
        return 0;  
    } 
    
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=0;   
    }
     
    dp[0]=1;
    
    for(int i=1;i<n;i++){
        int x=v[i-1]*10+v[i];
        if(v[i]==0){
            if(x>0&&x<27)
                dp[i]=dp[i-1];
            else 
                return 0;
        }
        else if(x>0&&x<27&&x!=v[i])
            dp[i]=dp[i-1]+dp[i-2];
        else
            dp[i]=dp[i-1];
    }
    return dp[n-1];
}



// GFG solution. Partially correct
int Solution::numDecodings(string A) {
    
    int n = A.length();
    // A table to store results of subproblems 
    int count[n+1];  
    count[0] = 1; 
    count[1] = 1; 
    //for base condition "01123" should return 0  
    if(A[0]=='0')   
        return 0; 
    for (int i = 2; i <= n; i++) 
    { 
        count[i] = 0; 
  
        // If the last digit is not 0,  
        // then last digit must add to the number of words 
        if (A[i-1] > '0') 
            count[i] = count[i-1]; 
  
        // If second last digit is smaller  
        // than 2 and last digit is smaller than 7, 
        // then last two digits form a valid character  
        if (A[i-2] == '1' || (A[i-2] == '2' && A[i-1] < '7') ) 
            count[i] += count[i-2]; 
    } 
    return count[n]; 
}
