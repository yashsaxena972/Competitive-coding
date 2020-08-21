// Last occurrence of a number in an array

#include <iostream>
using namespace std;

int lastOccurrence(int a[], int n, int key){
    if(n==0){
        return -1;
    }
    int i= lastOccurrence(a+1,n-1,key);
    if(i==-1){
        if(a[0]==key){
            return 0;
        }
        else{
            return -1;
        }
    }
    return i+1;
}

int main() {
    int n,a[10],key;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>key;
    cout<<lastOccurrence(a,n,key);
}
