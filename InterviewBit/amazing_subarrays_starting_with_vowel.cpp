// Amazing Subarrays
/*

You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

*/

int Solution::solve(string A) {
    long long int len  = A.length();
    long long int sum =0;
    for(int i=0;i<len;i++){
        if(A[i]=='a' || A[i]== 'e' ||A[i]== 'i'||A[i]== 'o'||A[i]== 'u'||A[i]== 'A'||A[i]== 'E'||A[i]== 'I'||A[i]== 'O'||A[i]== 'U')
                    sum+=len-i;
    
    }
    return sum%10003;
}
