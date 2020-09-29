// Abbreviation
/*

You can perform the following operations on the string, :

Capitalize zero or more of 's lowercase letters.
Delete all of the remaining lowercase letters in .
Given two strings,  and , determine if it's possible to make  equal to  
as described. If so, print YES on a new line. Otherwise, print NO.

*/

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    int m = a.length(), n = b.length();
    bool dp[1011][1011];

    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    for(int i=0;i<m;i++){
        for(int j=0;j<n+1;j++){
            if(dp[i][j]){
                if(j<n && toupper(a[i]) == b[j]){
                    dp[i+1][j+1] = true;
                }
                if(!isupper(a[i])){
                    dp[i+1][j] = true;
                }
            }
        }
    }

    if(dp[m][n]){
        return "YES";
    }
    return "NO";
}