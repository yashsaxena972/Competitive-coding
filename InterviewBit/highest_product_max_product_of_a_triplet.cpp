// Highest Product     or     Maximum product of a triplet (subsequence of size 3) in array
/*

Given an array A, of N integers A.
Return the highest product possible by multiplying 3 numbers from the array.

Input 1:
A = [1, 2, 3, 4]

Output 1:
24

Explanation 1:
2 * 3 * 4 = 24

Input 2:
A = [0, -1, 3, 100, 70, 50]

Output 2:
350000

Explanation 2:
70 * 50 * 100 = 350000

*/

int Solution::maxp3(vector<int> &A) {
    
    int n = A.size();
    // if size is less than 3, no triplet exists 
    if (n < 3) 
        return -1; 
  
    // Initialize Maximum, second maximum and third 
    // maximum element 
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN; 
  
    // Initialize Minimum and second mimimum element 
    int minA = INT_MAX, minB = INT_MAX; 
  
    for (int i = 0; i < n; i++) 
    { 
        // Update Maximum, second maximum and third 
        // maximum element 
        if (A[i] > maxA) 
        { 
            maxC = maxB; 
            maxB = maxA; 
            maxA = A[i]; 
        } 
  
        // Update second maximum and third maximum element 
        else if (A[i] > maxB) 
        { 
            maxC = maxB; 
            maxB = A[i]; 
        } 
  
        // Update third maximum element 
        else if (A[i] > maxC) 
            maxC = A[i]; 
  
        // Update Minimum and second mimimum element 
        if (A[i] < minA) 
        { 
            minB = minA; 
            minA = A[i]; 
        } 
  
        // Update second mimimum element 
        else if(A[i] < minB) 
            minB = A[i]; 
    } 
  
    return max(minA * minB * maxA, 
               maxA * maxB * maxC); 
}
