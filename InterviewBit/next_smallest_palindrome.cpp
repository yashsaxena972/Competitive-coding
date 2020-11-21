// Next Smallest Palindrome!
/*

Given a numeric string A representing a large number you need to find the next 
smallest palindrome greater than this number.

Input 1:
A = "23545"

Output 1:
"23632"

Input 2:
A = "999"

Output 2:
"1001"

*/

string Solution::solve(string A) {
    int len = A.length();
    if(len < 2)
        return A[0] < '9' ? to_string(A[0]-'0'+1) : "11";
    bool isOdd = len%2;
    int mid1, mid2;
    mid1 = len/2 - not(isOdd);
    mid2 = len/2;
    int carry = 1, pos=0;
    bool flagIncremental = true;
    // check if mirroring from middle will create palindrome > current number
    for(; pos<=mid1; pos++) {
        // break if mirroring from middle < current number
        if(A[mid2+pos] > A[mid1-pos]) {
            flagIncremental = true;
            break;
        }
        // check palindrome from middle
        else if(A[mid2+pos] == A[mid1-pos])
            flagIncremental = flagIncremental and true;
        // break if mirrorring from middle > current number
        else {
            flagIncremental = false;
            break;
        }
    }
    // if only mirroring from middle < current number, increment middle digit
    if(flagIncremental) {
        for(int i=mid1; i>=0; i--) {
            int temp = (A[i]-'0')+carry;
            A[i] = (temp%10)+'0';
            carry = temp/10;
        }
        if(carry) {
            A = to_string(carry)+A;
            len++;
        }
    }
    isOdd = len%2;
    mid1 = len/2 - not(isOdd);
    mid2 = len/2;
    // mirror from middle of current/incremented number
    for(int i=0; i<=mid1; i++)
        A[mid2+i] = A[mid1-i];
    return A;
}
