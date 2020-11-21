// Longest valid Parentheses
/*

Given a string A containing just the characters ’(‘ and ’)’.

Find the length of the longest valid (well-formed) parentheses substring.

Input 1:
    A = "(()"
Output 1:
    2
    Explanation 1:
        The longest valid parentheses substring is "()", which has length = 2.

Input 2:
    A = ")()())"
Output 2:
    4
    Explanation 2:
        The longest valid parentheses substring is "()()", which has length = 4.

*/

int Solution::longestValidParentheses(string A) {
    
    int n = A.length();
    // Variables for left and right counter. 
    // maxlength to store the maximum length found so far 
    int left = 0, right = 0, maxlength = 0; 
  
    // Iterating the string from left to right 
    for (int i = 0; i < n; i++) { 
        // If "(" is encountered, 
        // then left counter is incremented 
        // else right counter is incremented 
        if (A[i] == '(') 
            left++; 
        else
            right++; 
  
        // Whenever left is equal to right, it signifies 
        // that the subsequence is valid and 
        if (left == right) 
            maxlength = max(maxlength, 2 * right); 
  
        // Reseting the counters when the subsequence 
        // becomes invalid 
        else if (right > left) 
            left = right = 0; 
    } 
  
    left = right = 0; 
  
    // Iterating the string from right to left 
    for (int i = n - 1; i >= 0; i--) { 
  
        // If "(" is encountered, 
        // then left counter is incremented 
        // else right counter is incremented 
        if (A[i] == '(') 
            left++; 
        else
            right++; 
  
        // Whenever left is equal to right, it signifies 
        // that the subsequence is valid and 
        if (left == right) 
            maxlength = max(maxlength, 2 * left); 
  
        // Reseting the counters when the subsequence 
        // becomes invalid 
        else if (left > right) 
            left = right = 0; 
    } 
    return maxlength;
}
