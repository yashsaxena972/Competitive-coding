// Find a peak element
/*

Given an array of integers A, find and return the peak element in it.
An array element is peak if it is NOT smaller than its neighbors.
For corner elements, we need to consider only one neighbor.
For example, for input array {5, 10, 20, 15}, 20 is the only peak element.

Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    5

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    100

*/

// A binary search based function 
// that returns index of a peak element 
int findPeakUtil(vector<int> arr, int low, int high, int n) 
{ 
    // Find index of middle element 
    // (low + high)/2 
    int mid = low + (high - low) / 2; 
  
    // Compare middle element with its 
    // neighbours (if neighbours exist) 
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&  
        (mid == n - 1 || arr[mid + 1] <= arr[mid])) 
        return mid; 
  
    // If middle element is not peak and its 
    // left neighbour is greater than it, 
    // then left half must have a peak element 
    else if (mid > 0 && arr[mid - 1] > arr[mid]) 
        return findPeakUtil(arr, low, (mid - 1), n); 
  
    // If middle element is not peak and its 
    // right neighbour is greater than it, 
    // then right half must have a peak element 
    else
        return findPeakUtil( 
            arr, (mid + 1), high, n); 
} 

int Solution::solve(vector<int> &A) {
    int n = A.size();
    return A[findPeakUtil(A, 0, n - 1, n)]; 
}
