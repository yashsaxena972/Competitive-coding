// Rain Water Trapped

int Solution::trap(const vector<int> &A) {
    int ans = 0;
    int n = A.size();
    int left_max = 0;
    int right_max = 0;
    int lo = 0,hi = n-1;
    
    while(lo<=hi){
        if (A[lo] < A[hi]) {
            if (A[lo] > left_max)
                // update max in left
                left_max = A[lo];
            else
                // water on curr element = max - curr
                ans += left_max - A[lo];
            lo++;
        }
        else {
            if (A[hi] > right_max)
                // update right maximum
                right_max = A[hi];
            else
                ans += right_max - A[hi];
            hi--;
        }
    }
    
    return ans;
}
