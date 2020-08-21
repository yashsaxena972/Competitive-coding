// Recursive program to perform binary search

#include <iostream>
using namespace std;

int binarySearch(int a[],int start,int end,int key){

    if(start == end){
        return -1;
    }
    
    int mid = (start+end)/2;

    if(a[mid] == key){
        return mid+1;
    }

    else if(a[mid] > key){
        return binarySearch(a,start,mid-1,key);
    }

    else
        return binarySearch(a,mid+1,end,key);
    
}

int main() {
    int ar[10],n,key,start,end,ans;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cin>>key;
    start = 0;
    end = n-1;
    ans = binarySearch(ar,start,end,key);
    if(ans == -1){
        cout<<"Not found";
    }
    else{
        cout<<"Found at position "<<ans;
    }

}
