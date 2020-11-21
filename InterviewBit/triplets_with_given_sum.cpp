// Triplets in array with given sum

// C++ program to find triplets in a given 
// array whose sum is given sum. 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to print triplets with given sum 
void findTriplets(int arr[], int n, int sum) 
{ 
    // Sort array elements 
    sort(arr, arr + n); 
  
    for (int i = 0; i < n - 1; i++) { 
  
        // initialize left and right 
        int l = i + 1; 
        int r = n - 1; 
        int x = arr[i]; 
        while (l < r) { 
            if (x + arr[l] + arr[r] == sum) { 
  
                // Print elements if it's sum is given sum. 
                printf("%d %d %d\n", x, arr[l], arr[r]); 
                l++; 
                r--; 
            } 
  
            // If sum of three elements is less 
            // than 'sum' then increment in left 
            else if (x + arr[l] + arr[r] < sum) 
                l++; 
  
            // if sum is greater than given sum, then 
            // decrement in right side 
            else
                r--; 
        } 
    } 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 0, -1, 2, -3, 1 }; 
    int sum = -2; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    findTriplets(arr, n, sum); 
    return 0; 
} 