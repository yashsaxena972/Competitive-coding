#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubarrayWithSumK(int arr[], int n, int k){
    unordered_map<int,int> m;
    int pre = 0;
    int length = 0;

    for(int i=0;i<n;i++){
        pre += arr[i];

        if(pre == k){
            length = max(length, i+1);
        }
        else if(m.find(pre-k) != m.end()){
            length = max(length, i - m[pre-k]);
        }
        else{
            m[pre] = i;
        }
    }

    return length;
}

int main() {
    int n,k,arr[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    cout<<lengthOfLongestSubarrayWithSumK(arr,n,k);
}
