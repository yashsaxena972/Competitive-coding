// Beautiful Triplets   or    Triplets in AP
/*

Count the number of triplets in AP with common difference d

*/

// Complete the beautifulTriplets function below.
int beautifulTriplets(int d, vector<int> arr) {
    int ans = 0;
    int n = arr.size();

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            if(arr[j] - arr[i] == d){
                for(int k=i+2;k<n;k++){
                    if(arr[k] - arr[j] == d){
                        ans++;
                        break;
                    }
                }
                break;
            }
        }
    }

    return ans;
}