// Subset
// If S = [1,2,3], a solution is:

/*
[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/

void makeSubsets(vector<int>& A, vector<int> temp, int curr, vector<vector<int> >& ans){
    int n = A.size();
    
    ans.push_back(temp);
    
    if(curr == n){
        return;
    }
    
    for(int i = curr; i < n; i++){
        vector<int> temp1(temp);
        temp1.push_back(A[i]);
        makeSubsets(A, temp1, i+1, ans);
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> temp;
    
    sort(A.begin(),A.end());
    
    makeSubsets(A, temp, 0, ans);
    
    return ans;
}
