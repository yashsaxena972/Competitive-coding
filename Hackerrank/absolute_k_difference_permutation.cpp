// Absolute Permutation    or    K difference permutation
/*

Given two integers n and k. Consider first permutation of natural n numbers, 
P = “1 2 3 … n”, print a permutation “Result” such that abs(Resulti – Pi) = k 
where Pi denotes the position of i in permutation P. The value of Pi varies 
from 1 to n. If there are multiple possible results, then print the lexicographically smallest one.

*/

// Complete the absolutePermutation function below.
vector<int> absolutePermutation(int n, int k) {
    vector<int> ans;

    if(!k){
        for(int i=0;i<n;i++){
            ans.push_back(i+1);
        }
    }
    else if(n%(2*k) != 0){
        ans.push_back(-1);
    }
    else{
        for(int i=0;i<n;i++){
            if((i/k) % 2 == 0){
                ans.push_back(i+k+1);
            }
            else{
                ans.push_back(i-k+1);
            }
        }
    }
    
    return ans;
}