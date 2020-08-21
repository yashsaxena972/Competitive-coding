// Return whether array is sorted using recursion

#include <iostream>
using namespace std;

bool isSorted(int ar[], int n){
    if(n==0 or n==1){
        return true;
    }

    if(ar[0]<ar[1] and isSorted(ar+1,n-1)){
        return true;
    }
    return false;
}

int main() {
    int ar[10],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    cout<<isSorted(ar,n);
}
