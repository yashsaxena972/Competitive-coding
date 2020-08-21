// Max Continuous Series of 1s
// You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
// Find the position of zeros which when flipped will produce maximum continuous series of 1s

vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    
    vector<int> ans;
    
    // Left and right indexes of current window 
    int wL = 0, wR = 0;  
  
    // Left index and size of the widest window  
    int start = 0, end = 0, bestWindow = -1;  
  
    // Count of zeroes in current window 
    int zeroCount = 0;  
  
    // While right boundary of current window doesn't cross  
    // right end 
    while (wR < n) 
    { 
        // If zero count of current window is less than m, 
        // widen the window toward right 
        if (zeroCount <= B) 
        { 
            if (A[wR] == 0) 
              zeroCount++; 
            wR++; 
        } 
  
        // If zero count of current window is more than m, 
        // reduce the window from left 
        if (zeroCount > B) 
        { 
            if (A[wL] == 0) 
              zeroCount--; 
            wL++; 
        } 
  
        // Updqate widest window if this window size is more 
        if (wR-wL+1 > bestWindow) 
        { 
            bestWindow = wR-wL+1; 
            start = wL; 
            end = wR;
        } 
    } 
    
    // Push positions of zeroes in the widest window 
    for (int i=start; i<end; i++) 
    { 
        ans.push_back(i);
    } 
    
    return ans;
}
