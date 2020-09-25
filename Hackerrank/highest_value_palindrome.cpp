// Highest Value Palindrome
/*

Make largest palindrome by changing at most K-digits

Given a string containing all digits, we need to convert this string to a 
palindrome by changing at most K digits. If many solutions are possible then 
print lexicographically largest one.

*/

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
    string ans = s;

    int left = 0;
    int right = n-1;

    while(left < right){
        if(s[left]!=s[right]){
            ans[left] = ans[right] = max(s[left],s[right]);
            k--;
        }
        left++;
        right--;
    }

    if(k<0){
        return "-1";
    }

    left = 0;
    right = n-1;

    while(left <= right){

        // at mid character, if k>0 then change
        // it to 9
        if(left == right){
            if(k>0){
                ans[left] = '9';
            }
        }

        // if character at left(same as right) is
        // less than 9
        if(ans[left] < '9'){
            // if none of them is changed in the previous loop
            // subtract 2 from k and convert both to 9
            if(k>=2 && ans[left] == s[left] && ans[right] == s[right]){
                k -= 2;
                ans[left] = ans[right] = '9';
            }
            else if(k>=1 && (ans[left]!=s[left] || ans[right]!=s[right])){
                k--;
                ans[left] = ans[right] = '9';
            }
        }
        left++;
        right--;
    }

    return ans;
}
