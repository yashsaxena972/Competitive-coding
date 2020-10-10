// Missing Numbers   or   Elements present in an array but not in its duplicate
/*

Numeros the Artist had two lists that were permutations of one another. He was very proud. 
Unfortunately, while transporting them from one exhibition to another, some numbers were lost 
out of the first list. Can you find the missing numbers?

As an example, the array with some numbers missing, . The original array of numbers . The numbers missing are .

*/

#define MAX 1000000

// Complete the missingNumbers function below.
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    int n = arr.size();
    int m = brr.size();
    int a[MAX] = {0};
    vector<int> ans;

    for(int i=0;i<n;i++){
        a[arr[i]]--;
    }

    for(int i=0;i<m;i++){
        a[brr[i]]++;
    }

    for(int i=0;i<MAX;i++){
        if(a[i] > 0){
            ans.push_back(i);
        }
    }

    return ans;
}