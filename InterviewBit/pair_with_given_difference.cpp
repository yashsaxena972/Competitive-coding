// Pair With Given Difference
/*

Given an one-dimensional unsorted array A containing N integers.
You are also given an integer B, find if there exists a pair of elements in the
 array whose difference is B.
Return 1 if any such pair exists else return 0.

*/

int Solution::solve(vector<int> &A, int B) {
    if(A.empty())
        return 0;
    sort(A.begin(), A.end());

    int i=0;
    int j=0;
    while(i < A.size() && j < A.size()){
        int k = A[j] - A[i];
        if(k == B && i != j)
            return 1;
        else if(k < B)
            j++;
        else
            i++;
    }
    return 0;
}
