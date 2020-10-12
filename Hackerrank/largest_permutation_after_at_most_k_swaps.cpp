// Largest Permutation   or   Largest permutation after at most k swaps
/*

You are given an unordered array of unique integers incrementing from 1. You can swap any two elements a limited number of times. 
Determine the largest lexicographical value array that can be created by executing no more than the limited number of swaps.


Given a permutation of first n natural numbers as array and an integer k. Print the lexicographically largest permutation after at 
most k swaps
*/

// Complete the largestPermutation function below.
vector<int> largestPermutation(int k, vector<int> arr) {
    int n = arr.size();
    int pos[n+1];

    for(int i=0;i<n;i++){
        pos[arr[i]] = i;
    }

    for(int i=0;i<n && k;i++){
        if(arr[i] == n-i){
            continue;
        }

        int temp = pos[n-i];

        pos[arr[i]] = pos[n-i];
        pos[n-i] = i;

        swap(arr[temp],arr[i]);
        k--;
    }

    return arr;
}