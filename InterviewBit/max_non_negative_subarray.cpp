// Max Non Negative SubArray
/*

Given an array of integers, A of length N, find out the maximum sum sub-array 
of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the 
second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

*/

vector<int> Solution::maxset(vector<int> &A) {
    long sum = -1;
    int start = 0;
    int end = 0;
    long sum_seg = 0;
    vector<int> arr_main;
    vector<int> arr_seg;
    for (int i = 0; i < A.size(); i++){
        if (A[i] >= 0){
            arr_seg.push_back(A[i]);

            sum_seg += A[i];
            
            if (sum_seg > sum){
                arr_main = arr_seg;
                sum = sum_seg;
            }
            else if (sum_seg == sum){
                if (arr_seg.size() > arr_main.size()){
                    arr_main = arr_seg;
                }
            }            
        }
        else {
            arr_seg.clear();
            sum_seg = 0;
        }

    }
    return  arr_main;
}
