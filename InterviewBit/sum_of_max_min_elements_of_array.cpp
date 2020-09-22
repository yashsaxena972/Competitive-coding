// Max Min
/*

Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.

NOTE: You should make minimum number of comparisons.

*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int max, min;
    if(n%2 == 0){
        if(A[0] < A[1]){
            max = A[1];
            min = A[0];
        }
        else{
            max = A[0];
            min = A[1];
        }

        for(int i=2;i<n;i++){
            if(A[i] > max)
                max = A[i];
            else if(A[i] < min)
                min = A[i];
        }
    }
    else{
        max = min = A[0];
        for(int i=1;i<n;i++){
            if(A[i] > max)
                max = A[i];
            else if(A[i] < min)
                min = A[i];
        }
    }   
    
    return max + min;
}
