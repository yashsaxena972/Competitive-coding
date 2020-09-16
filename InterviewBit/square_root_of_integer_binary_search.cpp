// Square Root of Integer  (Using Binary Search)
/*

Given an integar A.
Compute and return the square root of A.
If A is not a perfect square, return floor(sqrt(A)).
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

*/

int Solution::sqrt(int A) {
    // Base cases 
    if (A == 0 || A == 1)  
       return A; 
  
    // Do Binary Search for floor(sqrt(x)) 
    long long int start = 1, end = A, ans;    
    while (start <= end)  
    {         
        long int mid = (start + end) / 2; 
  
        // If x is a perfect square 
        if (mid*mid == A) 
            return mid; 
  
        // Since we need floor, we update answer when mid*mid is  
        // smaller than x, and move closer to sqrt(x) 
        if (mid*mid < A)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else // If mid*mid is greater than x 
            end = mid-1;         
    } 
    return ans; 
}
