// Quicksort -- inplace -- avg. case O(nlogn) -- worst case O(n^2) 
// 3 steps
// 1. Choose pivot
// 2. Partition the array, bringing the pivot to its correct position, smaller elements to the left and larger elements to the right of the pivot
// 3. Recursively sort the left and right parts

#include <iostream>
using namespace std;

int partition(int a[], int s, int e){
    int i= s-1;
    int j = s;
    int pivot = a[e];

    for( ; j<=e-1 ; j++){
        if(a[j] <= pivot){
            i = i+1;
            swap(a[i],a[j]);
        }
    }
    // Bringing the pivot to its position
    swap(a[i+1],a[e]);
    return i+1;  // return the position of pivot
}

void quicksort(int a[], int s, int e){
    // base case
    if(s>=e){
        return;
    }

    // Find pivot and partition the array about it
    int p = partition(a,s,e);

    // Recursively sort the left and right parts 
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}

int main() {
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }  
    return 0;
}
