// Largest Coprime Divisor
/*

You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5

*/

// Recursive function to return gcd 
// of a and b 
int gcd(int a, int b) 
{ 
    // Everything divides 0 
    if (a == 0 || b == 0) 
        return 0; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
}

int Solution::cpFact(int A, int B) {
    while (gcd(A, B) != 1) { 
        A = A / gcd(A, B); 
    } 
    return A;
}
