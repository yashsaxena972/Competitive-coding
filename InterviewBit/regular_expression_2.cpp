// Regular Expression II
/*

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1

*/

bool _isMatch(const string &str, int s, const string &pat, int p){
    if(p == pat.length())        return s == str.size();

    bool star = p < pat.size()-1 and pat[p + 1] == '*';
    bool match = s < str.size() and  (pat[p] == '.' or str[s] == pat[p]);
    // if theres kleene
    if(star){
        // dont match rec, match rec.
        return _isMatch(str, s, pat, p+2) 
            or ( match and _isMatch(str, s+1, pat, p));
    }
    return match and _isMatch(str, s+1, pat, p+1);
}

int Solution::isMatch(const string A, const string B) {
    return _isMatch(A, 0, B, 0);
}
