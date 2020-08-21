// Remove element from array
// Given an array and a value, remove all the instances of that value in the array.
// Also return the number of elements left in the array after the operation.
// It does not matter what is left beyond the expected length.

int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int count = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] == B){
            continue;
        }
        else{
            A[count++] = A[i];
        }
    }
    return count;
}
