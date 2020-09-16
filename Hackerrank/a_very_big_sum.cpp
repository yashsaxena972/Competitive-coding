// A Very Big Sum
/*

In this challenge, you are required to calculate and print the sum of the 
elements in an array, keeping in mind that some of those integers may be quite large.

*/

// Complete the aVeryBigSum function below.
long aVeryBigSum(vector<long> ar) {
    int n = ar.size();
    long long int sum = 0;

    for(int i=0; i<n; i++){
        sum += ar[i];
    }

    return sum;
}