// Bubble sort recursively

#include <iostream>
using namespace std;

void bubble_sort_recursive(int a[], int j, int n){
    // Base cases
    if(n == 1){
        return;
    }
    if(j == n-1){
        // single pass completed
        return bubble_sort_recursive(a,0,n-1);
    }

    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    // moving to next position in the same pass
    return bubble_sort_recursive(a,j+1,n);
}

int main() {
    int a[10],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubble_sort_recursive(a,0,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
