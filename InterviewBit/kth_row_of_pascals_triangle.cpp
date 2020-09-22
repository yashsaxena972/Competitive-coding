// Kth Row of Pascal's Triangle
/*

Input : k = 3
Return : [1,3,3,1]

*/

vector<int> Solution::getRow(int A) {
    
    vector<int> ans;
    // nC0 = 1 
    int prev = 1; 
    ans.push_back(prev);
  
    for (int i = 1; i <= A; i++) { 
        // nCr = (nCr-1 * (n - r + 1))/r 
        int curr = (prev * (A - i + 1)) / i; 
        ans.push_back(curr);
        prev = curr; 
    } 
    
    return ans;
}
