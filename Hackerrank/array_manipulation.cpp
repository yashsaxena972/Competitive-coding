// Array Manipulation
/*

Starting with a 1-indexed array of zeros and a list of operations, for each 
operation add a value to each of the array element between two given indices, inclusive. 
Once all operations have been performed, return the maximum value in the array.

*/

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long int> A(n,0);
    long len = queries.size();

    for(long i=0;i<len;i++){
        A[(queries[i][0])-1] = A[(queries[i][0])-1] + queries[i][2];
        if(queries[i][1] < n){
            A[(queries[i][1])] = A[(queries[i][1])] - queries[i][2];
        }
    }

    long sum = 0;
    long x=0;

    for(int i=0;i<n;i++){
        x = x + A[i];
        if(x>sum){
            sum = x;
        }
    }

    return sum;
}