// Vowel and Consonant Substrings!
/*

Given a string A consisting of lowercase characters.

You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.

Return the count of substring modulo 109 + 7.

*/

#define mod 1000000007

int Solution::solve(string A) {
    int n=A.length();
    if(n==0 or n==1)
        return 0;
    int count=0;
    vector<int> vowel(n,0);
    vector<int> cons(n,0);
    for(int i=n-2;i>=0;i--)
    {
        if(A[i+1]=='a' or A[i+1]=='e' or A[i+1]=='i' or A[i+1]=='o' or A[i+1]=='u')
        {
            vowel[i]+=1;
        }
        else 
        {
            cons[i]+=1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        vowel[i]+=vowel[i+1];
        cons[i]+=cons[i+1];
    }
  
    for(int i=0;i<n-1;i++)
    {
        if(A[i]=='a' or A[i]=='e' or A[i]=='i' or A[i]=='o' or A[i]=='u')
        {
            count+=cons[i];
        }
        else
        count+=vowel[i];
    }
    return count%mod;
}
