// The Maximum Subarray   or    Max subarray and subsequence sum

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    
    int n = arr.size();
    int max1 = INT_MIN,max2 = INT_MIN;
    int sum = 0;
    vector<int> ans;
       
    for(int i=0;i<n;i++){
        if(arr[i] > max1){
            max1 = arr[i];
        }
        if(arr[i] >= 0){
            sum += arr[i];
        }
    }

    if(sum == 0){
        sum = max1;
    }

    int maxSum = 0, currSum = 0;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum < 0){
            currSum = 0;
        }
        else if(currSum > maxSum){
            maxSum = currSum;
        }
    }
    if(maxSum == 0){
        maxSum = sum;
    }

    ans.push_back(maxSum);
    ans.push_back(sum);
    return ans;
}