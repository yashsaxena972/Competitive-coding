// Palindrome String
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

bool isAlphaNumeric(char c){
    if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z')){
        return true;   
    }
    return false;
}

int Solution::isPalindrome(string A) {
    int i=0,j=A.length()-1;
    while(i <= j){
        if(!isAlphaNumeric(A[i])){
            i++;
            continue;
        }
        if(!isAlphaNumeric(A[j])){
            j--;
            continue;
        }
        if(A[i] != A[j] && abs(A[i]-A[j])!=32) // for ignoring cases
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
