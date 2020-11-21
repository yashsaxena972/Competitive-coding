// Min XOR value
// Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. 
// Report the minimum XOR value.

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int minXor = INT_MAX;
    int val = 0;
    for(int i=0;i<A.size();i++){
        val = A[i] ^ A[i+1];
        minXor = min(minXor, val);
    }
    
    return minXor;
}
