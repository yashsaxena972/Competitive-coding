// Single Number
// Given an array of integers, every element appears twice except for one. Find that single one.

int Solution::singleNumber(const vector<int> &A) {
    
    int ans = 0;
    for(int i=0;i<A.size();i++){
        // since a xor a = 0
        ans = ans ^ A[i];
    }
    return ans;
}
