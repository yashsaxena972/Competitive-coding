// Scramble String
/*

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
    0

*/

int Solution::isScramble(const string A, const string B) {
    // Strings of non-equal length 
    // cant' be scramble strings 
    if (A.length() != B.length()) { 
        return false; 
    } 
    
    int n = A.length();
    
    // Empty strings are scramble strings 
    if (n == 0) { 
        return true; 
    } 
    
    // Equal strings are scramble strings 
    if (A == B) { 
        return true; 
    } 
    
    // Check for the condition of anagram 
    string A1 = A, B1 = B; 
  
    sort(A1.begin(), A1.end()); 
    sort(B1.begin(), B1.end()); 
  
    if (A1 != B1) { 
        return false; 
    } 
    
    for (int i = 1; i < n; i++) { 
  
        // Check if S2[0...i] is a scrambled 
        // string of S1[0...i] and if S2[i+1...n] 
        // is a scrambled string of S1[i+1...n] 
        if (isScramble(A.substr(0, i), B.substr(0, i)) && isScramble(A.substr(i, n - i), B.substr(i, n - i))) { 
            return true; 
        } 
  
        // Check if S2[0...i] is a scrambled 
        // string of S1[n-i...n] and S2[i+1...n] 
        // is a scramble string of S1[0...n-i-1] 
        if (isScramble(A.substr(0, i), B.substr(n - i, i)) && isScramble(A.substr(i, n - i), B.substr(0, n - i))) { 
            return true; 
        } 
    } 
  
    // If none of the above 
    // conditions are satisfied 
    return false; 
}
