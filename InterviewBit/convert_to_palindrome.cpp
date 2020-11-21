// Convert to Palindrome
/*

Given a string A consisting only of lowercase characters, we need to check whether it is possible
 to make this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.

*/

bool isPalindrome(string::iterator low, string::iterator high){
    while (low < high){
        if (*low != *high)
            return false;
        low++;
        high--;
    }
    return true;
}

int Solution::solve(string A) {
    int n=A.length();
    int l=0,h=n-1;

    while(l<h){
        if(A[l]==A[h]){
            l++;
            h--;
        }
        else{
            if (isPalindrome(A.begin() + l + 1, A.begin() + h)) 
                return 1; 

            /*  If removing str[high] makes the whole string palindrome 
            We basically check if substring str[low+1..high] is 
            palindrome or not. */
            if (isPalindrome(A.begin() + l, A.begin() + h - 1)) 
                return 1; 
            
            return 0;
        }
    }
    
    return 1;
}
