// Check subarray with sum 0

#include <bits/stdc++.h>
using namespace std;

bool checkSum(int arr[], int n){
    unordered_set<int> s;

    // initialising prefix sum
    int pre = 0;

    for(int i=0;i<n;i++){
        pre += arr[i];

        // check if sum was already present in the set
        if(pre == 0 || s.find(pre)!=s.end()){
            return true;
        }

        s.insert(pre);
    }
    return false;
}

int main() {
    int n, arr[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<checkSum(arr,n);
}
