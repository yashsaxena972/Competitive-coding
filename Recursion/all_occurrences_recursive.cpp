//All occurrences of a number in an array

#include <iostream>
using namespace std;

void allOccurrences(int a[],int i, int n, int key){
    if(i==n){
        return;
    }
    if(a[i] == key){
        cout<<i<<",";
    }
    allOccurrences(a,i+1,n,key);
}

int main() {
    int a[10],n,key;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>key;
    allOccurrences(a,0,n,key);
}
