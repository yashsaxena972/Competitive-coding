// Next Similar Number
/*

Given a number A in a form of string.
You have to find the smallest number that has same set of digits as A and is greater than A.
If A is the greatest possible number with its set of digits, then return -1.

*/

string Solution::solve(string A) {
    if(next_permutation(A.begin(),A.end())) return A;
    return to_string(-1);
}