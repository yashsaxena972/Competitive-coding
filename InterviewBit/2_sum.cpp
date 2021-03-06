// 2 Sum
/*

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based.
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    vector<int> ans;
    if(A.size() < 2){
        return vector<int> ();
    }
        
    unordered_map<int,int> m; 
    int n = A.size();
    for (int i = 0; i < n; i++) { 
        int temp = B - A[i]; 
  
        if (m.find(temp) != m.end()){
            ans.push_back(m[temp]+1);
            ans.push_back(i+1);
            return ans;
        }
        
        if(m.find(A[i]) == m.end())
        {
            m[A[i]] = i;
        }
    }
    return ans;
}
