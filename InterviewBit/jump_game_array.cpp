// Jump Game Array
/*

Given an array of non-negative integers, A, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

*/

int Solution::canJump(vector<int> &A) {
    int n=A.size();
    
    if(n==1){
        return 1;  
    } 
    
    int max_reach=A[0],step=A[0],jump=1;
    
    for(int i=1;i<n-1;i++){
        max_reach=max(max_reach,i+A[i]);
        step--;
        if(step<0) return 0;
        if(step==0){
         jump++;
         step=max_reach-i; 
        }
    }
    if(max_reach>=n-1){
        return 1;  
    } 
    return 0;
}
