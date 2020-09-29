// Minimum Swaps 2
/*

You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] 
without any duplicates. You are allowed to swap any two elements. You need to find the 
minimum number of swaps required to sort the array in ascending order.

*/

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    int n = arr.size();

    for(int i=0;i<n;i++){
        if(arr[i] == i+1){
            continue;
        }
        swaps++;
        int temp = arr[i];
        arr[i] = arr[temp-1];
        arr[temp-1] = temp;
        i--;
    }

    return swaps;
}