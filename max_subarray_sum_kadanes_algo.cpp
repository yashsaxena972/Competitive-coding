/*
Print the max sum of all possible subarrays of an array by applying Kadane's algo.
Kadane's algo
O(n).
*/

#include <iostream>
using namespace std;
int main() {
    int n,ar[100],currSum=0,maxSum=0;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    for(int i=0;i<n;i++){
        currSum += ar[i];
        if(currSum < 0){
            currSum = 0;
        }
        maxSum = max(maxSum,currSum);
    }

    cout<<"Max sum is : "<<maxSum;
}
