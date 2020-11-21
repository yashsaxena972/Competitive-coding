// Length of last word

int Solution::lengthOfLastWord(const string A) {
    
    int ans = 0;
    int i = A.length()-1;
    while(A[i] == ' '){
        i--;
    }
    
    for(;i>=0;i--){
        if(A[i] == ' '){
            break;
        }
        ans++;
    }
    return ans;
}
