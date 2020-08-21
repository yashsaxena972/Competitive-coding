// Remove Duplicates from Sorted Array II
// Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int count = 0;          // Just moving duplicates at back of vector approach, faster;
    int size = A.size();
    for(auto i = 0; i<size; ++i)
    {
        if(i<size-2 && A[i]==A[i+1] && A[i]==A[i+2]) continue;
        else
            A[count++] = A[i];
    }
    return count;
}
