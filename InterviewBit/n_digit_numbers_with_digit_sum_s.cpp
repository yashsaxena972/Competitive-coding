// N digit numbers with digit sum S
/*

Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

*/

int Solution::solve(int A, int B) {
    long long int dp[A][B];
    if(B<1||B>9*A){
        return 0;    
    }
    
    for(int i=0;i<B;i++){
        if(i+1<=9){
            dp[0][i]=1;  
        } 
        else{
            dp[0][i]=0;  
        } 
    }
    
    for(int j=0;j<A;j++){
        dp[j][0]=1;
    }
    
    for(int i=1;i<A;i++){
        for(int j=1;j<B;j++){
            dp[i][j]=0;
            int k=0;
            if(j>=9){
                k=j-9;  
            } 
            for(;k<=j;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;   
            }
             
        }
    }
    
    return dp[A-1][B-1];
}
