// Making Anagrams    or    Remove minimum number of characters so that two strings become anagram
/*

Given two strings in lowercase, the task is to make them anagram. The only allowed 
operation is to remove a character from any string. Find minimum number of characters 
to be deleted to make both the strings anagram?

*/

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    int arr[26] = {0};

    for(int i=0;i<s1.length(); i++){
        arr[s1[i]-'a']++;
    }

    for(int i=0;i<s2.length(); i++){
        arr[s2[i]-'a']--;
    }

    long long int ans = 0;
    for(int i=0;i<26;i++){
        ans += abs(arr[i]);
    }

    return ans;
}