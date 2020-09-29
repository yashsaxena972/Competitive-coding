// Min Max Riddle
/*

Find maximum of minimum for every window size in a given array

Given an integer array of size n, find the maximum of the minimum’s of every 
window size in the array. Note that window size varies from 1 to n.

*/

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    // complete this function
    int n = arr.size();
    stack<int> s;
    long left[n+1];
    long right[n+1];
    for(int i=0;i<n;i++){
        left[i] = -1;
        right[i] = n;
    }

    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }
        if(!s.empty()){
            left[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }
        if(!s.empty()){
            right[i] = s.top();
        }
        s.push(i);
    }

    vector<long> ans(n+1,0);

    for(int i=0;i<n;i++){
        int len = right[i]-left[i]-1;
        ans[len] = max(ans[len],arr[i]);
    }

    for(int i=n-1;i>=1;i--){
        ans[i] = max(ans[i],ans[i+1]);
    }

    ans.erase(ans.begin());
    return ans;
}