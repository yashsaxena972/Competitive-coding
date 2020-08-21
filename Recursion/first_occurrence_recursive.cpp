// Find the first occurrence of the key in the array. Linear Search

#include <iostream>
using namespace std;

int firstOccurrence(int ar[], int n, int key){
    if(n==0){
        return -1;  // element not found
    }
    // recursive case
    if(ar[0]==key){
        return 0;
    }
    int i = firstOccurrence(ar+1,n-1,key);
    if(i == -1){
        return -1;
    }
    return i+1;
}

int main() {
    int n,ar[10],key;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cin>>key;
    cout<<firstOccurrence(ar,n,key);
}
