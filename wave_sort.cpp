#include <iostream>
using namespace std;
int main() {
    int ar[10],n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>ar[i];
    }

    // Algo for wave sort
    for(i=0;i<n;i+=2){
        // Check for the left element 
        if(i>0 && ar[i-1]>ar[i]){
            swap(ar[i-1],ar[i]);
        }


        // Check for the right element
        if(i<n-1 && ar[i+1]>ar[i]){
            swap(ar[i+1],ar[i]);
        }
    }
    // Print the array
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}
