// Largest Permutation
/*

Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.

*/

vector<int> Solution::solve(vector<int> &A, int B) {
    if(B==0)return A;
    int n=A.size();
    if(n<2)return A;
    vector idx(n,0);
    for(int i=0;i<n;i++){
        idx[A[i]-1]=i;
    }
    for(int i=0;i<n && B>0;i++){
        if(A[i]==n-i)continue;
        int ele=A[i];
        swap(A[idx[n-i-1]],A[i]);
        swap(idx[n-i-1],idx[ele-1]);
        B--;
    }
    return A;
}
