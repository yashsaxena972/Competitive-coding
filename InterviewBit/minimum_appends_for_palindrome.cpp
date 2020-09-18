// Minimum Appends for Palindrome!
/*

Given a string A consisting of lowercase characters.
We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.

*/

vector<int> computeLPSArray(string s){
    int n = s.length();
    vector<int> LPS(n);
 
    int j = 0;
    LPS[0] = 0; 
 
    
    int i = 1;
    while (i < n){
        if (s[i] == s[j]){
            j++;
            LPS[i] = j;
            i++;
        }
        else{
            if (j != 0){
                j = LPS[j-1];
            }
            else{
                LPS[i] = 0;
                i++;
            }
        }
    }
    return LPS;
}

int Solution::solve(string A) {
    string rs = A;
    reverse(rs.begin(), rs.end());
    string c = rs + "$" + A;
    vector<int> LPS = computeLPSArray(c);
    return (A.length() - LPS.back());
}
