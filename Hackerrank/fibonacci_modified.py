// Fibonacci Modified
/*

We define a modified Fibonacci sequence using the following definition:

Given terms  and  where , term  is computed using the following relation:

For example, if  and ,

,
,
,
and so on.
Given three integers, , , and , compute and print the  term of a modified Fibonacci sequence.

*/

dp = {}
# Complete the fibonacciModified function below.
def fibonacciModified(t1, t2, n):
    if n == 1:
        return t1
    if n == 2:
        return t2
    t3 = dp.get(n)
    if t3 is None:
        t3 = fibonacciModified(t1,t2,n-2) + fibonacciModified(t1,t2,n-1)**2
        dp[n] = t3
    
    return t3    
