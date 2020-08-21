// Trailing zeros in Factorial

int Solution::trailingZeroes(int A) {
    int ans=0;
    
    // Keep dividing n by powers of  
    // 5 and update count 
    for (int i = 5; A / i >= 1; i *= 5) {
        count += A / i; 
    }
        
    return ans;    
}
