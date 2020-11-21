// Distinct Numbers in Window
/*

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE: if B > N, return an empty array.

Input 1:

 A = [1, 2, 1, 3, 4, 3]
 B = 3

Output 1:

 [2, 3, 3, 2]

Explanation 1:

 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 So, we return an array [2, 3, 3, 2].  

*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    
    vector<int> ans;
    int n = A.size();
    // Creates an empty hashmap hm 
    map<int, int> hm; 
  
    // initialize distinct element count for current window 
    int dist_count = 0; 
  
    // Traverse the first window and store count 
    // of every element in hash map 
    for (int i = 0; i < B; i++) { 
        if (hm[A[i]] == 0) { 
            dist_count++; 
        } 
        hm[A[i]] += 1; 
    } 
  
    ans.push_back(dist_count);
  
    // Traverse through the remaining array 
    for (int i = B; i < n; i++) { 
        // Remove first element of previous window 
        // If there was only one occurrence, then reduce distinct count. 
        if (hm[A[i - B]] == 1) { 
            dist_count--; 
        } 
        // reduce count of the removed element 
        hm[A[i - B]] -= 1; 
  
        // Add new element of current window 
        // If this element appears first time, 
        // increment distinct element count 
  
        if (hm[A[i]] == 0) { 
            dist_count++; 
        } 
        hm[A[i]] += 1; 
  
        ans.push_back(dist_count);
    }
    
    return ans;
}
