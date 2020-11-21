// Compare version numbers

int Solution::compareVersion(string A, string B) {
    long long int vnum1=0, vnum2=0;
    
    for(int i=0,j=0; (i<A.length()||j<B.length()); ){
        
        while(i<A.length() && A[i] != '.'){
            vnum1 = vnum1*10+ (A[i]-'0');
            i++;
        }
        while(j<B.length() && B[j] != '.'){
            vnum2 = vnum2*10 + (B[j]-'0');
            j++;
        }
        
        if(vnum1 > vnum2){
            return 1;
        }
        if(vnum1 < vnum2){
            return -1;
        }
        
        // Else if equal, reset the variables and move to the next numeric part
        vnum1 = vnum2 = 0;
        i++;
        j++;
    }
    return 0;
}
