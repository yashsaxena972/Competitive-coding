// K Largest Elements
/*

Given an 1D integer array A of size N you have to find and return the B largest elements of the array A.

*/

vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>> pq;
    for(int i=0;i<A.size();i++)
        pq.push(A[i]);

    vector<int> ans;
    for(int i=0;i<B;i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
