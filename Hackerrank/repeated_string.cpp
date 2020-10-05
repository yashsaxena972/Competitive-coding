// Repeated String
/*

Lilah has a string, , of lowercase English letters that she repeated infinitely many times.

Given an integer, , find and print the number of letter a's in the first  letters of Lilah's infinite string.

For example, if the string  and , the substring we consider is , the first  characters of her infinite string. 
There are  occurrences of a in the substring.

*/

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long long numA = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a'){
            numA++;
        }
    }

    long long ans = (n/s.size())*numA;
    for(int i=0;i<n%s.size();i++){
        if(s[i] == 'a'){
            ans++;
        }
    }

    return ans;
}