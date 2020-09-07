// Tiling With Dominoes
/*

Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.
Return the answer modulo 109 + 7 .

*/

int Solution::solve(int A) {
    if(A%2) return 0;
    
    long long int arr1[A + 1], arr2[A + 1]; 
    arr1[0] = 1, arr1[1] = 0, arr2[0] = 0, arr2[1] = 1; 
    for (int i = 2; i <= A; i++) { 
        arr1[i] = (arr1[i - 2] + 2 * arr2[i - 1] )%1000000007;
        arr2[i] = (arr1[i - 1] + arr2[i - 2])%1000000007; 
    } 
  
    return arr1[A]%1000000007; 
}
