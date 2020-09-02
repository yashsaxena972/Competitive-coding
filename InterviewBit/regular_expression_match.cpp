// Regular Expression Match
/*

Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

’?’ : Matches any single character.
‘*’ : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input 1:
    A = "aa"
    B = "a"

Output 1:
    0

Input 2:
    A = "aa"
    B = "aa"

Output 2:
    1

Input 3:
    A = "aaa"
    B = "aa"

Output 3:
    0
    
Input 4:
    A = "aa"
    B = "*"

Output 4:
    1

Input 5:
    A = "aa"
    B = "a*"

Output 5:
    1

Input 6:
    A = "ab"
    B = "?*"

Output 6:
    1

Input 7:
    A = "aab"
    B = "c*a*b"

Output 7:
    0

*/

int match(string s, int i, string p, int j){
    
    if(i >= s.size() && j >= p.size()){
        return 1;
    }
    
    if(i == s.size() && j < p.size()){
        for(int t = j; t < p.size(); t++){
            if(p[t] != '*'){
                return 0;
            }
        }
        return 1;
    }
    
    if(s[i] == p[j] || p[j] == '?'){
        return match(s, i+1, p, j+1);
    }
    
    if(p[j] == '*'){
        return max(match(s, i+1, p, j), match(s, i, p, j+1));
    }
    
}

int Solution::isMatch(const string s, const string p) {
    int pat = p.size();
    int str = s.size();
    
    int i = 0, j = 0;
    int iIndex = -1, jIndex = -1;
    
    while(i < str){
        if(s[i] == p[j] || (j < pat && p[j] == '?')){
            i++;
            j++;
        }
        else if(p[j] == '*' && j < pat){
            jIndex = j;
            iIndex = i;
            j++;
        }
        else if(jIndex != -1){
            j = jIndex + 1;
            i = iIndex + 1;
            iIndex++;
        }
        else{
            return 0;
        }
        
    }
    
    while(j < pat && p[j] == '*'){
        j++;
    }
    
    if(j == pat){
        return 1;
    }
    
    return 0;
}
