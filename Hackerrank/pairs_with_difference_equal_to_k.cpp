// Pairs   or    Count all distinct pairs with difference equal to k

// Complete the pairs function below.
int pairs(int k, vector<int> arr) {
    int count = 0;
    sort(arr.begin(),arr.end());

    int l = 0;
    int r = 0;
    while(r < arr.size()){
        if(arr[r] - arr[l] == k){
            count++;
            l++;
            r++;
        }
        else if(arr[r] - arr[l] > k){
            l++;
        }
        else{
            r++;
        }
    }

    return count;
}