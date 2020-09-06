// Longest Arithmetic Progression
/*

Find longest Arithmetic Progression in an integer array A of size N, and return its length.

*/

int Solution::solve(const vector<int> &A) {
    int n=A.size();
    if(n<=2){
        return n;  
    } 
    int B[n];
    
    for(int i=0;i<n;i++){
        B[i]=A[i];   
    }
     
    sort(B,B+n);
    
    int l[n];
    l[0]=1;
    for(int i=1;i<n;i++){
        l[i]=2;
    }
    
    int ans=2;
    
    for(int j=n-2;j>0;j--){
        int i=j-1,k=j+1;
        while(i>=0&&k<n){
            if(B[i]+B[k]==2*B[j]){
                l[j]=max(l[j],l[k]+1);
                ans=max(ans,l[j]);
                i--;
                k++;
            }
            else if(B[i]+B[k]<2*B[j])
                k++;
            else i--;
        }
    }
    return ans;
}
