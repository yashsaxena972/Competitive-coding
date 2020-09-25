// Construct the Array
/*

Your goal is to find the number of ways to construct an array such that 
consecutive positions contain different values.

Specifically, we want to construct an array with  elements such that each 
element between  and , inclusive. We also want the first and last elements 
of the array to be  and .

Given ,  and , find the number of ways to construct such an array. Since the 
answer may be large, only find it modulo .

*/

#define MOD 1000000007l
// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    long long int A0 = 0, A1 = 1, At;
    long long int k1 = k-1, k2 = k-2;

    for(int i=1;i<n-1;i++){
        At = (A0*k2+A1)%MOD;
        A1 = (A0*k1)%MOD;
        A0 = At;
    }

    long long int ans;
    if(x == 1){
        ans = (A0*k1)%MOD;
    }
    else{
        ans = (A0*k2+A1)%MOD;
    }

    return ans;
}