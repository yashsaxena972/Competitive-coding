// Anagram
/*

Two words are anagrams of one another if their letters can be rearranged 
to form the other word.

In this challenge, you will be given a string. You must split it into two 
contiguous substrings, then determine the minimum number of characters to 
change to make the two substrings into anagrams of one another.

For example, given the string 'abccde', you would break it into two parts: 'abc' and 'cde'. 
Note that all letters have been used, the substrings are contiguous and their lengths 
are equal. Now you can change 'a' and 'b' in the first substring to 'd' and 'e' to 
have 'dec' and 'cde' which are anagrams. Two changes were necessary.

*/

// Complete the anagram function below.
int anagram(string s) {
    int len = s.length();
    if(len%2 == 1){
        return -1;
    }

    int letter[26] = {0};
    int count = 0;
    for(int i=0;i<len/2;i++){
        letter[s[i]-'a']++;
    }

    for(int i=len/2;i<len;i++){
        letter[s[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        count += abs(letter[i]);
    }

    return count/2;
}