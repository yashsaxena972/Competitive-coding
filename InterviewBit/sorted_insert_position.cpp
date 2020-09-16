// Sorted Insert Position
/*

Given a sorted array A and a target value B, return the index if the target is 
found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.



*/

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
      if(n < 1) {
         return 0;
      }
      int low = 0;
      int high = n-1;
      int mid;
      int pos;
      while(low <= high) {
         mid = low + (high-low)/2;
         if(A[mid] == B) {
            return mid;
         }
         else if(A[mid] > B) {
            high = mid - 1;
            pos = mid;
         }
         else {
            low = mid + 1;
            pos = mid + 1;
         }
      }
      return pos;
}
