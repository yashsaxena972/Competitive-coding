// Rearrange array
// Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    // First step: Increase all values by (arr[arr[i]]%n)*n 
    for (int i=0; i < n; i++) {
        A[i] += (A[A[i]]%n)*n; 
    }
  
    // Second Step: Divide all values by n 
    for (int i=0; i<n; i++) {
        A[i] /= n;
    }
        
}
