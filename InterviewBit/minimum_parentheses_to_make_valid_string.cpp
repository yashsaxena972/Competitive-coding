// Minimum Parantheses!
/*

Given a string A of parantheses ‘(‘ or ‘)’.

The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) 
we must add to make the resulting parentheses string valid.

An string is valid if:

Open brackets must be closed by the corresponding closing bracket.
Open brackets must be closed in the correct order.



*/

int Solution::solve(string A) {
    // maintain balance of string 
    int bal = 0; 
    int ans = 0; 
  
    for (int i = 0; i < A.length(); ++i) { 
  
        bal += A[i] == '(' ? 1 : -1; 
  
        // It is guaranteed bal >= -1 
        if (bal == -1) { 
            ans += 1; 
            bal += 1; 
        } 
    } 
  
    return bal + ans; 
}
