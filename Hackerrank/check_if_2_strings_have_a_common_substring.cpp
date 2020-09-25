// Two Strings   or   Check if 2 strings have a common substring
/*

Check if two strings have a common substring

You are given two strings str1 and str2. You have to check if the two strings share a common substring.

*/

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    vector<bool> v(26,0);

    for(int i=0;i<s1.length();i++){
        v[s1[i]-'a'] = true;
    }

    for(int i=0;i<s2.length();i++){
        if(v[s2[i]-'a']){
            return "YES";
        }
    }

    return "NO";
}