// Palindrome Index
/*

Given a string of lowercase letters in the range ascii[a-z], determine a 
character that can be removed to make the string a palindrome. There may be 
more than one solution, but any will do. For example, if your string is "bcbc", 
you can either remove 'b' at index  or 'c' at index . If the word is already a 
palindrome or there is no solution, return -1. Otherwise, return the index of a 
character to remove.

*/

bool isPalindrome(string s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    int i=0;
    int len = s.length();
    int j = len-1;
    int ans = -1;

    while(i < j && s[i]==s[j]){
        i++;
        j--;
    }

    if(i<j){
        string str1 = s.substr(0,i) + s.substr(i+1,len-i-1);
        if(isPalindrome(str1)){
            ans = i;
        }
        string str2 = s.substr(0,j) + s.substr(j+1,len-j-1);
        if(isPalindrome(str2)){
            ans = j;
        }
    }

    return ans;
}