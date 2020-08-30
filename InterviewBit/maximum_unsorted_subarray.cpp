// Maximum Unsorted Subarray
/*

You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

*/

vector<int> Solution::subUnsort(vector<int> &A) {
    int n=A.size();
    vector<int>ans;
    int s=-1,e=-1;
    
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            s=i;
            break;
        }
    }
    
    if(s==-1){
        ans.push_back(-1);
        return ans;
    }
    
    for(int i=n-1;i>0;i--){
        if(A[i]<A[i-1]){
            e=i;
            break;
        }
    }
   
    int minm=A[s],maxm=A[s];
    for(int i=s+1;i<=e;i++){
        if(A[i]<minm)
            minm=A[i];
        else if(A[i]>maxm)
            maxm=A[i];
    }
    
    for(int i=0;i<s;i++){
        if(A[i]>minm){
            s=i;
            break;
        }
    }
    
    for(int i=n-1;i>e;i--){
        if(A[i]<maxm){
            e=i;
            break;
        }
    }
    ans.push_back(s);
    ans.push_back(e);
    return ans;
}
