// Sum of Pairwise Hamming Distance
// Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

// Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array. Return the answer modulo 
// 1000000007.

int Solution::hammingDistance(const vector<int> &A) {
    long long int ans = 0,n = A.size();
    long long int count = 0; 
    
    // traverse over all bits
    for (int i = 0; i < 32; i++) {
        // count number of elements with i'th bit set 
        count = 0; 
        for (int j = 0; j < n; j++) {
            if ( (A[j] & (1 << i)) ) {
                count++; 
            }
        }
         
        // Add "count * (n - count) * 2" to the answer 
        ans = (ans+(count * (n - count) * 2))%1000000007;     
    }
    return ans;
}
