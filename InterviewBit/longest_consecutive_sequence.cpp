// Longest Consecutive Sequence
/*

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example:
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

int Solution::longestConsecutive(const vector<int> &A) {
    
    int n = A.size();
    unordered_set<int> S; 
    int ans = 0; 
  
    // Hash all the array elements 
    for (int i = 0; i < n; i++) 
        S.insert(A[i]); 
  
    // check each possible sequence from 
    // the start then update optimal length 
    for (int i = 0; i < n; i++) { 
        // if current element is the starting 
        // element of a sequence 
        if (S.find(A[i] - 1) == S.end()) { 
            // Then check for next elements 
            // in the sequence 
            int j = A[i]; 
            while (S.find(j) != S.end()) 
                j++; 
  
            // update  optimal length if 
            // this length is more 
            ans = max(ans, j - A[i]); 
        } 
    } 
    return ans; 
}
