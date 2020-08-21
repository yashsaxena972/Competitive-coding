// N/3 Repeat Number
// Asked in: Google
// You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
// If so, return the integer. If not, return -1.
// If there are multiple solutions, return any one.


int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int count1 = 0, count2 = 0; 
    int first=INT_MAX, second=INT_MAX;
    
    for (int i = 0; i < A.size(); i++) { 
  
        // if this element is previously seen,  
        // increment count1. 
        if (first == A[i]) 
            count1++; 
  
        // if this element is previously seen,  
        // increment count2. 
        else if (second == A[i]) 
            count2++; 
      
        else if (count1 == 0) { 
            count1++; 
            first = A[i]; 
        } 
  
        else if (count2 == 0) { 
            count2++; 
            second = A[i]; 
        } 
  
        // if current element is different from 
        // both the previously seen variables,  
        // decrement both the counts. 
        else { 
            count1--; 
            count2--; 
        } 
    }
    
    count1 = 0; 
    count2 = 0; 
  
    // Again traverse the array and find the 
    // actual counts. 
    for (int i = 0; i < A.size(); i++) { 
        if (A[i] == first) 
            count1++; 
  
        else if (A[i] == second) 
            count2++; 
    } 
  
    if (count1 > A.size()/3) 
        return first; 
  
    if (count2 > A.size()/3) 
        return second; 
  
    return -1; 
}
