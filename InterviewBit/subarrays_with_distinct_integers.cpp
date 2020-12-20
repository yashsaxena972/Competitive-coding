// Subarrays with distinct integers!
/*

Given an array A of positive integers,call a (contiguous,not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly B.

(For example: [1, 2, 3, 1, 2] has 3 different integers 1, 2 and 3)

Return the number of good subarrays of A.

*/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> m;
    int res = 0, j=0, prefix = 0, cnt=0;
    for(auto i = 0; i < A.size(); ++i) {
        if (m[A[i]]++ == 0) 
            ++cnt;
        if (cnt > B){
            --m[A[j++]];
            --cnt;
            prefix = 0;
        }
        while (m[A[j]] > 1){
            ++prefix;
            --m[A[j++]];
        }
        if (cnt == B) 
            res += prefix + 1;
    }
    return res;
}
