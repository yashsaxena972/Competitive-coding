// Max Array Sum
/*

Given an array of integers, find the subset of non-adjacent elements with the maximum sum. 
Calculate the sum of that subset.

For example, given an array  we have the following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
Our maximum subset sum is .

*/

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    int incl = arr[0];
    int excl = 0;
    int excl_new;

    for(int i=1;i<arr.size();i++){
        excl_new = (incl > excl)? incl: excl;
        incl = excl + arr[i];
        excl = excl_new;
    }

    return ((incl>excl)?incl:excl);
}