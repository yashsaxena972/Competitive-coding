// Combinations
/*

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

*/

void make(vector<int> temp, int curr, int n, int k, vector<vector<int> >& ans){
    if(temp.size() == k){
        ans.push_back(temp);
        return;
    }
    else if(curr > n){
        return;
    }
    
    for(int i = curr; i <= n; i++){
        vector<int> t(temp);
        t.push_back(i);
        make(t, i+1, n, k, ans);
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > ans;
    
    for(int i = 1; i <= A; i++){
        vector<int> temp(1, i);
        make(temp, i+1, A, B, ans);
    }
    
    return ans;
}
