// Sherlock and Anagrams    or    Count of total anagram substrings
/*
Given a string of lower alphabet characters, count total substring of this string which are anagram to each other.

Examples:

Input  : str = “xyyx”
Output : 4
Total substrings of this string which
are anagram to each other are 4 which 
can be enumerated as,
{“x”, “x”}, {"y", "y"}, {“xy”, “yx”}, 
{“xyy”, “yyx”}

Input  : str = "geeg"
Output : 4

*/

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int n = s.length();
    map<vector<int>,int> mp;

    for(int i=0;i<n;i++){
        vector<int> freq(26,0);
        for(int j=i;j<n;j++){
            freq[s[j]-'a']++;
            mp[freq]++;
        }
    }

    int result = 0;
    for(auto it:mp){
        int freq = it.second;
        result += ((freq)*(freq-1))/2;
    }

    return result;
}