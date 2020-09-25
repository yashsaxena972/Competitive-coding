// Alternating Characters     or     Minimum number of deletions so that no two consecutive are same
/*

Given a string, find minimum number of deletions required so that there will 
be no two consecutive repeating characters in the string.

*/

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int ans = 0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i] == s[i+1]){
            ans++;
        }
    }
    return ans;
}