// Equalize the Array    or    Minimum delete operations to make all elements of array same
/*


Given an array of n elements such that elements may repeat. We can delete 
any number of elements from the array. The task is to find a minimum number of 
elements to be deleted from the array to make it equal.

*/

// Complete the equalizeArray function below.
int equalizeArray(vector<int> arr) {
    unordered_map<int,int> freq;
    int n = arr.size();

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    int maxFreq = INT_MIN;
    for(auto itr:freq){
        maxFreq = max(maxFreq,itr.second);
    }

    return n - maxFreq;
}