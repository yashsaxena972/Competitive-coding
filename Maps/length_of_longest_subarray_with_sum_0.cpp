#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubarray(int arr[], int n){
    unordered_map<int,int> m;
    int pre = 0;
    int length = 0;

    for(int i=0;i<n;i++){
        pre += arr[i];
        
        if(pre == 0){
            length = max(length, i+1);
        }
        else if(m.find(pre) != m.end()){
            // if the prefix sum already exists in the map
            length = max(length, i-m[pre]);
        }
        else{
            // if the prefix sum doesn't exist in the map,ie, it occurs for the first time
            m[pre] = i;
        }
    }

    return length;
}

int main() {
    int n, arr[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<lengthOfLongestSubarray(arr,n);
}
