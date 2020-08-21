// Bubble sort recursively

#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    if(n == 1){
        return;
    }
    // inner loop iteratively
    for(int j=0;j<n-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
    // outer loop recursively
    bubbleSort(a,n-1);
    
}

int main() {
    int a[10],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubbleSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
