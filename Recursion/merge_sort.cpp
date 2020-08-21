// Merge Sort

#include <iostream>
using namespace std;

void merge(int a[], int s, int e){
    int mid = (s+e)/2;
    int temp[100];
    int i=s,j=mid+1,k=s; // i is the pointer to the 1st part, j is the pointer to the 2nd part and k is the pointer to the temporary array

    while(i<=mid && j<=e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }

    // If either part is complete while there are some elements in the other
    while(i<=mid){
        temp[k++] = a[i++];
    }

    while(j<=e){
        temp[k++] = a[j++];
    }

    // Copying the temp array into the original array
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int s, int e){
    // base case
    if(s >= e){
        return;
    }
    // Merge sort follows 3 steps
    // 1.Divide
    int mid = (s+e)/2;

    // 2. Recursively sort the 2 parts
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

    // 3. Merge the 2 sorted parts
    // The array is not actually divided so we just need to merge by positions of the same array
    merge(a,s,e);

}

int main() {
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
