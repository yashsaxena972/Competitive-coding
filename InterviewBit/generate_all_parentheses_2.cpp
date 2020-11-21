// Generate all Parentheses II
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.
// For example, given n = 3, a solution set is:
// "((()))", "(()())", "(())()", "()(())", "()()()"
// Make sure the returned list of strings are sorted.

void generate_brackets(int A, int open, int close, string str,vector<string>& ans){
    if(close == A){
        ans.push_back(str);
        return;
    }
    
    if(open < A){
        str += '(';
        generate_brackets(A,open+1,close,str,ans);
        str.pop_back();
    }
    
    if(close < open){
        str += ')';
        generate_brackets(A,open,close+1,str,ans);
        str.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    if(A>0){
        generate_brackets(A,0,0,"",ans);
    }
    return ans;
}
