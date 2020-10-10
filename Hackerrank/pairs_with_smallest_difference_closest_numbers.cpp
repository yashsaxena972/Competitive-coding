// Closest Numbers
/*

Given a list of distinct unsorted integers, find the pair of elements that 
have the smallest absolute difference between them? If there are multiple pairs, find them all.

Sample Input 2

4
5 4 3 2
Sample Output 2

2 3 3 4 4 5

*/

// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr) {
    int n = arr.size();
    if(n <= 1){
        return vector<int>();
    }

    vector<int> ans;

    sort(arr.begin(),arr.end());

    int minDiff = arr[1] - arr[0];
    for(int i=2;i<n;i++){
        minDiff = min(minDiff,arr[i] - arr[i-1]);
    }

    for(int i=1;i<n;i++){
        if((arr[i] - arr[i-1]) == minDiff){
            ans.push_back(arr[i-1]);
            ans.push_back(arr[i]);
        }
    }

    return ans;
}