// Permutations
/*

Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

*/

void permutation(vector<int> &A, int st, vector<vector<int> > &v)
{
    if(st >= A.size())
    {
        v.push_back(A);
        return;
    }
    for(int i=st; i<A.size(); i++)
    {
        swap(A[st], A[i]);
        permutation(A, st+1, v);
        swap(A[st], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;
    permutation(A, 0, ans);
    return ans;
}
