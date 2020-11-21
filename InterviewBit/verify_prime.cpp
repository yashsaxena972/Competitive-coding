// Verify Prime
// Optimized approach
// See factors_of_a_number for details

int Solution::isPrime(int A) {
    int ans=1;
    if(A == 1){
        return 0;
    }
    for(int i=2;i<=pow(A,0.5);i++){
        if(A%i == 0){
            ans=0;
            break;
        }
    }
    return ans;
}
