// Sherlock and the Valid String
/*

Sherlock considers a string to be valid if all characters of the string appear 
the same number of times. It is also valid if he can remove just 1 character 
at 1 index in the string, and the remaining characters will occur the same number 
of times. Given a string , determine if it is valid. If so, return YES, otherwise return NO.

*/

// Complete the isValid function below.
string isValid(string s) {
    vector<int> freq(26,0);
    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
    }

    int maxFreq = -1;
    bool removedChar = false;

    for(int i=0;i<26;i++){
        if(freq[i] == 0){
            continue;
        }
        else if(maxFreq == -1){
            maxFreq = freq[i];
            continue;
        }
        else if(freq[i] == maxFreq){
            continue;
        }
        else if(!removedChar && (freq[i] == maxFreq+1 || freq[i] == 1)){
            removedChar = !removedChar;
            continue;
        }
        else{
            return "NO";
        }
    }
    return "YES";
}