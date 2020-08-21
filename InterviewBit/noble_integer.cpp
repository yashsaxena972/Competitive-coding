// Noble Integer
// Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.

int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    if(A[A.size()-1]==0){
        return 1;
    }
	    
    int n = A.size();
    for(int i=0;i<n-1;i++){
	    if(A[i]==n-i-1){
		    if(A[i]!=A[i+1]){
		        return 1;       
		    }
			
	    }
    }
    return -1;
}
