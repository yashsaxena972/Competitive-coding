// Redundant Braces
// Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
// Check whether A has redundant braces or not.
// Return 1 if A has redundant braces, else return 0.

int Solution::braces(string A) {
    stack<char> s;
    int size = A.length();
    int i = 0;
    while(i<size)
    {
        char c = A[i];
        if (c == '(' || c == '+' || c == '*' || c == '-' || c == '/')
            s.push(c);
        else if (c == ')')
        {
            if (s.top() == '(')
                return 1;
            else
            {
                while (!s.empty() && s.top() != '(')
                    s.pop();
                s.pop();
            }
        }
        i++;
    }
    return 0;
}
