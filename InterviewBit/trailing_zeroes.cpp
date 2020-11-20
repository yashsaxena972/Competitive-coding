// Trailing Zeroes
/*

Given an integer A, count and return the number of trailing zeroes.

Explanation 1:

 18 in binary is represented as: 10010, there is 1 trailing zero.
Explanation 2:

 8 in binary is represented as: 1000, there are 3 trailing zeroes.

*/

int Solution::solve(int A) {
    int count = 0; 
    while ((A & 1) == 0) { 
        A = A >> 1; 
        count++; 
    } 
    return count; 
}
