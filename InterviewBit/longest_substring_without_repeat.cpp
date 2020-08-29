// Longest Substring Without Repeat

/*

Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/

int Solution::lengthOfLongestSubstring(string A) {
    int n = A.length(); 
  
    int res = 0; // result 
  
    // last index of all characters is initialized 
    // as -1 
    vector<int> lastIndex(256, -1); 
  
    // Initialize start of current window 
    int i = 0; 
  
    // Move end of current window 
    for (int j = 0; j < n; j++) { 
  
        // Find the last index of str[j] 
        // Update i (starting index of current window) 
        // as maximum of current value of i and last 
        // index plus 1 
        i = max(i, lastIndex[A[j]] + 1); 
  
        // Update result if we get a larger window 
        res = max(res, j - i + 1); 
  
        // Update last index of j. 
        lastIndex[A[j]] = j; 
    } 
    return res; 
}
