// Store all occurrences of a number in an array, into another array

#include <iostream>
using namespace std;

int storeOccurrences(int a[],int i, int n, int key, int output[], int j){
    if(i == n){  // When the entire input array has been traversed, the value of j will be returned as the size of the output array
        return j;
    }
    if(a[i] == key){
        output[j] = i;
        return storeOccurrences(a,i+1,n,key,output,j+1);
    }
    return storeOccurrences(a,i+1,n,key,output,j);
}

int main() {
    int a[10],out[10],n,key,output[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>key;
    int outputSize = storeOccurrences(a,0,n,key,output,0);
    for(int i=0;i<outputSize;i++){
        cout<<output[i]<<",";
    }
}
