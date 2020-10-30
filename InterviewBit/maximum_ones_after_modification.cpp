// Maximum Ones After Modification
/*

Given a binary array A and a number B, we need to find length of the longest 
subsegment of ‘1’s possible by changing at most B ‘0’s.

*/

int Solution::solve(vector<int> &A, int B) {
    int cnt0 = 0; 
    int l = 0; 
    int max_len = 0; 
    int n = A.size();
  
    // i decides current ending point 
    for (int i = 0; i < n; i++) { 
        if (A[i] == 0) 
            cnt0++; 
  
        // If there are more 0's move 
        // left point for current ending 
        // point. 
        while (cnt0 > B) { 
            if (A[l] == 0) 
                cnt0--; 
            l++; 
        } 
  
        max_len = max(max_len, i - l + 1); 
    } 
  
    return max_len; 
}
