// Rain water trapped

int Solution::trap(const vector<int> &A) {
    int ans = 0;
    int n = A.size();
    
    for(int i=1;i<n;i++){
        int left = A[i];
        for(int j=0;j<i;j++){
            left = max(left,A[j]);
        }
        
        int right = A[i];
        for(int j=i+1;j<n;j++){
            right = max(right,A[j]);
        }
        
        ans += (min(left,right)-A[i]);
    }
    
    return ans;
}
