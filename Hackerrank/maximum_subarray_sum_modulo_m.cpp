// Maximum Subarray Sum
/*

Given an array of n elements and an integer m. The task is to find the 
maximum value of the sum of its subarray modulo m i.e find the sum of each 
subarray mod m and print the maximum value of this modulo operation.

*/

// Complete the maximumSum function below.
long maximumSum(vector<long> a, long m) {
    long x, prefix = 0, maxim = 0;
    set<long> s;
    s.insert(0);

    for(int i=0;i<a.size();i++){
        prefix = (prefix + a[i])%m;
        maxim = max(maxim, prefix);

        // finding iterator pointing to the first element
        // that is not less than value "prefix+1"
        auto it = s.lower_bound(prefix + 1);

        if(it != s.end()){
            maxim = max(maxim, prefix - (*it) + m);
        }

        s.insert(prefix);
    }

    return maxim;
}