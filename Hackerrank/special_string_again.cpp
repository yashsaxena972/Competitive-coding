// Special String Again
/*

A string is said to be a special string if either of two conditions is met:

All of the characters are the same, e.g. aaa.
All characters except the middle one are the same, e.g. aadaa.
A special substring is any substring of a string which meets one of those criteria. 
Given a string, determine how many special substrings can be formed from it.

For example, given the string , we have the following special substrings: .

*/

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long ans = 0;
    int sameCharCount[n] = {0};
    long int i=0,j,c;

    while(i<n){
        j = i+1;
        c = 1;
        while(j<n && s[i] == s[j]){
            j++;
            c++;
        }

        ans += (c*(c+1))>>1;
        sameCharCount[i] = c;
        i = j;
    }

    for(j=1;j<n-1;j++){
        if(s[j] == s[j-1]){
            sameCharCount[j] = sameCharCount[j-1];
        }

        if(s[j-1] == s[j+1] && s[j] != s[j-1]){
            ans += min(sameCharCount[j-1],sameCharCount[j+1]);
        }
    }

    return ans;
}