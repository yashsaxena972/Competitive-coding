// Stringoholics
/*

You are given an array A consisting of strings made up of the letters ‘a’ and ‘b’ only.
Each string goes through a number of operations, where:

1.  At time 1, you circularly rotate each string by 1 letter.
2.  At time 2, you circularly rotate the new rotated strings by 2 letters.
3.  At time 3, you circularly rotate the new rotated strings by 3 letters.
4.  At time i, you circularly rotate the new rotated strings by i % length(string) letters.

Eg: String is "abaa"

1.  At time 1, string is "baaa", as 1 letter is circularly rotated to the back
2.  At time 2, string is "aaba", as 2 letters of the string "baaa" is circularly rotated to the back
3.  At time 3, string is "aaab", as 3 letters of the string "aaba" is circularly rotated to the back
4.  At time 4, string is again "aaab", as 4 letters of the string "aaab" is circularly rotated to the back
5.  At time 5, string is "aaba", as 1 letters of the string "aaab" is circularly rotated to the back

A: [a,ababa,aba]
Output

4

String 'a' is it's original self at time 1, 2, 3 and 4.
String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)

Hence, 3 strings are their original self at time 4.

*/

int Solution::solve(vector<string> &A) {
    long long n=A.size();
    vector<int> v(n);    
    for(long long i=0;i<n;i++){
        long long x=A[i].size();
        if(x<=1)
            v[i]=1;
        else{
            long long k=1,c=0;
            while(1){
                c=(k*(k+1))/2;
                if(c%x==0){
                    v[i]=k;
                    break;
                }
                k++;
            }
        }
    }
    
    long long ans=1;
    for(long long i=0;i<n;i++){
        for(long long j=i+1;j<n&&v[i]!=1;j++){
            v[j]=v[j]/__gcd(v[i],v[j]);
        }
        ans = (long long)(ans%1000000007*(v[i])%1000000007)%1000000007;
    }
    
    return ans%1000000007;
}
