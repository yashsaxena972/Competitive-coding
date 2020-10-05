// Count Triplets in GP
/*

You are given an array and you need to find number of tripets of indices  
such that the elements at those indices are in geometric progression for a given common ratio r

*/

// Complete the countTriplets function below.
long long countTriplets(vector<long> arr, long r) {
    unordered_map<long long,long long> left,right;
    long long ans = 0;
    long long n = arr.size();

    for(int i=0;i<n;i++){
        right[arr[i]]++;
    }

    for(int i=0;i<n;i++){

        right[arr[i]]--;

        if(arr[i]%r == 0){
            ans += left[arr[i]/r]*right[arr[i]*r];
        }
        left[arr[i]]++;
    }

    return ans;
}